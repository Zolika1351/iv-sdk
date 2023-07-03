template<typename T>
class CPool
{
public:
	uint8_t* m_pObjects;				// 00-04
	uint8_t* m_pFlags;					// 04-08
	uint32_t m_nCount;					// 08-0C
	uint32_t m_nEntrySize;				// 0C-10
	int32_t m_nTop;						// 10-14
	uint32_t m_nUsed;					// 14-18
	uint8_t m_bAllocated;				// 18-19
	uint8_t pad[3];						// 19-1C

	CPool(int size, char* name, int entrySize)
	{
		((void(__thiscall*)(CPool*, int, char*, int))(AddressSetter::Get(0x872F10, 0x3F3DB0)))(this, size, name, entrySize);
	}

	T* GetAt(uint32_t nHandle)
	{
		return ((T*(__thiscall*)(CPool*, uint32_t))(AddressSetter::Get(0x26700, 0x92E00)))(this, nHandle);
	}
	uint32_t GetIndex(T* pObject)
	{
		return ((uint32_t(__thiscall*)(CPool*, void*))(AddressSetter::Get(0x47230, 0xAFF10)))(this, pObject);
	}
	void* New()
	{
		return ((void*(__thiscall*)(CPool*))(AddressSetter::Get(0x39CB0, 0x9F3A0)))(this);
	}

	// helper functions
	bool IsValid(int slot)
	{
		return !(m_pFlags[slot] & 0x80);
	}

	T* Get(int slot)
	{
		if (!IsValid(slot)) return nullptr;
		return (T*)&m_pObjects[m_nEntrySize * slot];
	}

	int FindNextUsed(int curr)
	{
		for (int i = curr; i < m_nCount; i++)
		{
			if (IsValid(i)) return i;
		}
		return -1;
	}

	// pool iterator
	struct Iterator
	{
		Iterator(CPool<T>* ptr, int id)
		{
			pool = ptr;
			index = id;
		}

		T* operator*() const { return pool->Get(index); }
		Iterator& operator++()
		{
			index = pool->FindNextUsed(index + 1);
			return *this;
		}
		bool operator!= (const Iterator& b) { return index != b.index; };

	private:
		CPool<T>* pool;
		int index = 0;
	};
};
VALIDATE_SIZE(CPool<CPed>, 0x1C);

template<typename T>
auto begin(CPool<T>* pool) { return CPool<T>::Iterator(pool, pool->FindNextUsed(0)); }
template<typename T>
auto end(CPool<T>* pool) { return CPool<T>::Iterator(pool, -1); }
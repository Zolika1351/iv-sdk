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
};
VALIDATE_SIZE(CPool<CPed>, 0x1C);
// native calling code by aru, slightly modified to fit

class IVNativeCallContext
{
public:
	void* m_pReturn;						// 00-04
	unsigned int m_nArgCount;				// 04-08
	void* m_pArgs;							// 08-0C
	unsigned int m_nDataCount;				// 0C-10
	CVector* m_pOriginalData[4];			// 10-20
	CQuaternion m_TemporaryData[4];			// 20-60
};
VALIDATE_OFFSET(IVNativeCallContext, m_pOriginalData, 0x10);
VALIDATE_OFFSET(IVNativeCallContext, m_TemporaryData, 0x20);

class NativeContext : public IVNativeCallContext
{
private:
	// Configuration
	enum
	{
		MaxNativeParams = 16,
		ArgSize = 4,
	};

	// Anything temporary that we need
	unsigned char m_TempStack[MaxNativeParams * ArgSize];

public:
	inline NativeContext()
	{
		// It's okay to point both args and return at
		// the same pointer as the game will handle this
		m_pArgs = &m_TempStack;
		m_pReturn = &m_TempStack;
		m_nArgCount = 0;
		m_nDataCount = 0;
	}

	template <typename T>
	inline void Push(T value)
	{
		// Have we reached our argument count?
		if (m_nArgCount == MaxNativeParams)
		{
			// We can only store 16 arguments
			return;
		}

		// Is the argument too big?
		if (sizeof(T) > ArgSize)
		{
			// We only accept 4 byte or less arguments
			return;
		}
		else if (sizeof(T) < ArgSize) // Is the argument too small?
		{
			// Reset the argument data
			*(unsigned int*)(m_TempStack + ArgSize * m_nArgCount) = 0;
		}

		// Add to argument to the argument stack
		*(T*)(m_TempStack + ArgSize * m_nArgCount) = value;

		// Increment the total argument count
		m_nArgCount++;
	}

	template <typename T>
	inline T GetResult()
	{
		// Copy back any vector results
		while (m_nDataCount > 0)
		{
			m_nDataCount--;
			CVector* pVec3 = m_pOriginalData[m_nDataCount];
			CQuaternion* pVec4 = &m_TemporaryData[m_nDataCount];
			pVec3->x = pVec4->x;
			pVec3->y = pVec4->y;
			pVec3->z = pVec4->z;
		}

		return *(T*)m_TempStack;
	}

	template<typename T>
	inline T GetArgument(size_t idx)
	{
		uintptr_t* arguments = (uintptr_t*)m_pArgs;

		if (arguments)
		{
			if (&arguments[idx])
			{
				if (arguments[idx])
				{
					return *(T*)&arguments[idx];
				}
			}
		}
		return 0;
	}

	template<typename T>
	inline void SetResult(size_t idx, T value)
	{
		uintptr_t* returnValues = (uintptr_t*)m_pReturn;

		*(T*)&returnValues[idx] = value;
	}

};

class NativeInvoke
{
private:
	typedef void(_cdecl* NativeCall)(IVNativeCallContext* pNativeContext);

	static bool Invoke(unsigned int uiHash, IVNativeCallContext* pNativeContext)
	{
		auto NativeFunc = (NativeCall)CRunningScript::FindNativeAddress(uiHash);
		if (NativeFunc != NULL)
		{
			NativeFunc(pNativeContext);
			return true;
		}
		return false;
	}

public:
	static inline void Invoke2(NativeContext* cxt, uint32_t Hash)
	{
		Invoke(Hash, cxt);
	}

	template <typename R>
	static inline R Invoke(uint32_t hash)
	{
		NativeContext cxt;
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1>
	static inline R Invoke(uint32_t hash, T1 p1)
	{
		NativeContext cxt;
		cxt.Push(p1);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2>
	static inline R Invoke(uint32_t hash, T1 p1, T2 p2)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3>
	static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4>
	static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7, typename T8>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		cxt.Push(p8);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7, typename T8, typename T9>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		cxt.Push(p8);
		cxt.Push(p9);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7, typename T8, typename T9,
		typename T10>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		cxt.Push(p8);
		cxt.Push(p9);
		cxt.Push(p10);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7, typename T8, typename T9,
		typename T10, typename T11>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		cxt.Push(p8);
		cxt.Push(p9);
		cxt.Push(p10);
		cxt.Push(p11);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7, typename T8, typename T9,
		typename T10, typename T11, typename T12>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		cxt.Push(p8);
		cxt.Push(p9);
		cxt.Push(p10);
		cxt.Push(p11);
		cxt.Push(p12);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7, typename T8, typename T9,
		typename T10, typename T11, typename T12, typename T13>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12, T13 p13)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		cxt.Push(p8);
		cxt.Push(p9);
		cxt.Push(p10);
		cxt.Push(p11);
		cxt.Push(p12);
		cxt.Push(p13);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7, typename T8, typename T9,
		typename T10, typename T11, typename T12, typename T13, typename T14>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		cxt.Push(p8);
		cxt.Push(p9);
		cxt.Push(p10);
		cxt.Push(p11);
		cxt.Push(p12);
		cxt.Push(p13);
		cxt.Push(p14);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}

	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7, typename T8, typename T9,
		typename T10, typename T11, typename T12, typename T13, typename T14,
		typename T15>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14, T15 p15)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		cxt.Push(p8);
		cxt.Push(p9);
		cxt.Push(p10);
		cxt.Push(p11);
		cxt.Push(p12);
		cxt.Push(p13);
		cxt.Push(p14);
		cxt.Push(p15);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}


	template <typename R, typename T1, typename T2, typename T3, typename T4,
		typename T5, typename T6, typename T7, typename T8, typename T9,
		typename T10, typename T11, typename T12, typename T13, typename T14,
		typename T15, typename T16>
		static inline R Invoke(uint32_t hash, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14, T15 p15, T16 p16)
	{
		NativeContext cxt;
		cxt.Push(p1);
		cxt.Push(p2);
		cxt.Push(p3);
		cxt.Push(p4);
		cxt.Push(p5);
		cxt.Push(p6);
		cxt.Push(p7);
		cxt.Push(p8);
		cxt.Push(p9);
		cxt.Push(p10);
		cxt.Push(p11);
		cxt.Push(p12);
		cxt.Push(p13);
		cxt.Push(p14);
		cxt.Push(p15);
		cxt.Push(p16);
		Invoke(hash, &cxt);
		return cxt.GetResult<R>();
	}
};

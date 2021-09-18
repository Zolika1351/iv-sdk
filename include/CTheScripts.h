class CTheScripts
{
public:
	static uint32_t FindNativeAddress(uint32_t nativeHash)
	{
		__try
		{
			uint32_t funcPtr = Addresses::nFindNativeAddress;
			uint32_t nativePtr;
			_asm
			{
				push esi
				mov esi, nativeHash
				call funcPtr
				pop esi
				mov nativePtr, eax
			}

			return nativePtr;
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			return 0;
		}
	}
	static bool IsPlayerOnAMission()
	{
		return ((bool(__cdecl*)())(Addresses::nIsPlayerOnAMission))();
	}
};
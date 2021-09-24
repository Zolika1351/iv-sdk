class CTimer
{
public:
	static inline uint8_t& m_CodePause = AddressSetter::GetRef<uint8_t>(0xDDDF41, 0xDDDF42);
	static inline uint8_t& m_UserPause = AddressSetter::GetRef<uint8_t>(0xCFCC39, 0xCFCC3A);
	static inline uint32_t& m_FrameCounter = AddressSetter::GetRef<uint32_t>(0xDDDF38, 0xCFCC30);
	static inline uint32_t& m_snTimeInMilliseconds = AddressSetter::GetRef<uint32_t>(0xDDDE74, 0xCFCB6C);
	static inline float& ms_fMinTimeStep = AddressSetter::GetRef<float>(0xB1D9E4, 0xB2E09C);
	static inline float& ms_fMaxTimeStep = AddressSetter::GetRef<float>(0xB1D9E8, 0xB2E0A0);
	static inline float& ms_fTimeStep = AddressSetter::GetRef<float>(0xDDDE7C, 0xCFCB74);
	static inline float& ms_fTimeStepNonClipped = AddressSetter::GetRef<float>(0xDDDEBC, 0xCFCBB4);
	static inline float& ms_fTimeScale = AddressSetter::GetRef<float>(0xB1D9D8, 0xB2E090); // set by scripts
	static inline float& ms_fTimeScale2 = AddressSetter::GetRef<float>(0xB1D9DC, 0xB2E094); // set by scripts
	static inline float& ms_fTimeScale3 = AddressSetter::GetRef<float>(0xB1D9E0, 0xB2E098); // changes for death camera

	static bool GetIsPaused()
	{
		return ((uint32_t(__cdecl*)())(AddressSetter::Get(0x44370, 0xAD0B0)))();
	}
};
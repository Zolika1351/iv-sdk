class CTimer
{
public:
	static inline uint8_t& m_CodePause = *(uint8_t*)nullptr;
	static inline uint8_t& m_UserPause = *(uint8_t*)nullptr;
	static inline uint32_t& m_FrameCounter = *(uint32_t*)nullptr;
	static inline uint32_t& m_snTimeInMilliseconds = *(uint32_t*)nullptr;
	static inline float& ms_fMinTimeStep = *(float*)nullptr;
	static inline float& ms_fMaxTimeStep = *(float*)nullptr;
	static inline float& ms_fTimeStep = *(float*)nullptr;
	static inline float& ms_fTimeStepNonClipped = *(float*)nullptr;
	static inline float& ms_fTimeScale = *(float*)nullptr; // set by scripts
	static inline float& ms_fTimeScale2 = *(float*)nullptr; // set by scripts
	static inline float& ms_fTimeScale3 = *(float*)nullptr; // changes for death camera
};
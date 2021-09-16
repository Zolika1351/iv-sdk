class CClock
{
public:
	static inline uint32_t& ms_nGameClockForcedMinutes = *(uint32_t*)nullptr;
	static inline uint32_t& ms_nGameClockForcedHours = *(uint32_t*)nullptr;
	static inline uint32_t& CurrentDay = *(uint32_t*)nullptr;
	static inline uint32_t& ms_nGameClockSeconds = *(uint32_t*)nullptr;
	static inline uint32_t& ms_nGameClockMinutes = *(uint32_t*)nullptr;
	static inline uint32_t& ms_nGameClockHours = *(uint32_t*)nullptr;
	static inline uint32_t& ms_nGameClockDays = *(uint32_t*)nullptr;
	static inline uint32_t& ms_nGameClockMonth = *(uint32_t*)nullptr;
	static inline uint32_t& ms_nMillisecondsPerGameMinute = *(uint32_t*)nullptr;
};
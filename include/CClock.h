class CClock
{
public:
	static inline uint32_t& ms_nGameClockForcedMinutes = AddressSetter::GetRef<uint32_t>(0xDD52F0, 0xD51684);
	static inline uint32_t& ms_nGameClockForcedHours = AddressSetter::GetRef<uint32_t>(0xDD5308, 0xD5169C);
	static inline uint32_t& CurrentDay = AddressSetter::GetRef<uint32_t>(0xDD5310, 0xD516A4);
	static inline uint32_t& ms_nGameClockSeconds = AddressSetter::GetRef<uint32_t>(0xDD530C, 0xD516A0);
	static inline uint32_t& ms_nGameClockMinutes = AddressSetter::GetRef<uint32_t>(0xDD52FC, 0xD51690);
	static inline uint32_t& ms_nGameClockHours = AddressSetter::GetRef<uint32_t>(0xDD5300, 0xD51694);
	static inline uint32_t& ms_nGameClockDays = AddressSetter::GetRef<uint32_t>(0xDD5314, 0xD516A8);
	static inline uint32_t& ms_nGameClockMonth = AddressSetter::GetRef<uint32_t>(0xDD52F8, 0xD5168C);
	static inline uint32_t& ms_nMillisecondsPerGameMinute = AddressSetter::GetRef<uint32_t>(0xDD5304, 0xD51698);
};
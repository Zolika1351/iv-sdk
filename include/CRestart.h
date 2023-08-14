class CRestart
{
public:
	static inline auto& NumberOfHospitalRestarts = AddressSetter::GetRef<uint32_t>(0xF50FC8, 0xF59E68);
	static inline auto& NumberOfPoliceRestarts = AddressSetter::GetRef<uint32_t>(0xF50FD0, 0xF59E70);
	static inline auto& NumberOfSafehouses = AddressSetter::GetRef<uint32_t>(0xF50FCC, 0xF59E6C);

	static inline auto HospitalRestartPoints = (CVector_pad*)AddressSetter::Get(0xF51380, 0xF5A220);
	static inline auto HospitalRestartHeadings = (float*)AddressSetter::Get(0xF50DC4, 0xF59C64);
	static inline auto HospitalRestartWhenToUse = (int*)AddressSetter::Get(0xF50D90, 0xF59C30);

	static inline auto PoliceRestartPoints = AddressSetter::GetRef<CVector_pad>(0xF51420, 0xF5A2C0);
	static inline auto PoliceRestartHeadings = AddressSetter::GetRef<float>(0xF50DF8, 0xF59C98);
	static inline auto PoliceRestartWhenToUse = AddressSetter::GetRef<int>(0xF50D40, 0xF59BE0);

	struct tSafehouse
	{
		CVector_pad vPos;							// 00-10
		float fHeading;								// 10-14
		char sName[32];								// 14-34
		uint32_t nWhenToUse;						// 34-38
		uint8_t bEnabled;							// 38-39
		uint8_t pad[0x7];							// 39-40
	};
	VALIDATE_SIZE(tSafehouse, 0x40);

	static inline auto Safehouses = (tSafehouse*)AddressSetter::Get(0xF51200, 0xF5A0A0);

	static inline auto& bOverrideRestart = AddressSetter::GetRef<bool>(0xF50DB8, 0xF59C58);
	static inline auto& OverridePosition = AddressSetter::GetRef<CVector_pad>(0xF51560, 0xF5A400);
	static inline auto& OverrideHeading = AddressSetter::GetRef<float>(0xF50DBC, 0xF59C5C);
	static inline auto& bFadeInAfterNextDeath = AddressSetter::GetRef<bool>(0xF59E78, 0xF59E78);
	static inline auto& ExtraHospitalRestartCoors = AddressSetter::GetRef<CVector_pad>(0xF51570, 0xF5A410);
	static inline auto& ExtraHospitalRestartHeading = AddressSetter::GetRef<float>(0xF50DEC, 0xF59C8C);
	static inline auto& ExtraHospitalRestartWhenToUse = AddressSetter::GetRef<uint32_t>(0xF50DC0, 0xF59C60);
	static inline auto& ExtraPoliceStationRestartCoors = AddressSetter::GetRef<CVector_pad>(0xF50FF0, 0xF59E90);
	static inline auto& ExtraPoliceStationRestartHeading = AddressSetter::GetRef<float>(0xF50DF0, 0xF59C90);
	static inline auto& ExtraPoliceStationRestartWhenToUse = AddressSetter::GetRef<uint32_t>(0xF50DF4, 0xF59C94);

	static bool Save()
	{
		return ((int(__cdecl*)())(AddressSetter::Get(0x4E5D60, 0x5BBB00)))();
	}
	static bool Load()
	{
		return ((int(__cdecl*)())(AddressSetter::Get(0x4E5F00, 0x5BBC90)))();
	}
};
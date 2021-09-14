class CPed;
class CVehicle;

class CPlayerInfo
{
public:
	char pad[0x4C];														// 000-04C
	char m_sName[20];													// 04C-060
	char pad2[0x390];													// 060-3F0
	CPed* m_pPlayerPed2;												// 3F0-3F4
	char pad3[0x20];													// 3F4-414
	float m_fStamina;													// 414-418
	char pad3_[0x7C];													// 418-494
	int m_nLastHitPedTime;												// 494-498
	int m_nLastHitBuildingTime;											// 498-49C
	int m_nLastHitObjectTime;											// 49C-4A0
	int m_nLastDroveOnPavementTime;										// 4A0-4A4
	int m_nLastRanLightTime;											// 4A4-4A8
	int m_nLastDroveAgainstTrafficTime;									// 4A8-4AC
	char pad4[0x10];													// 4AC-4BC
	int m_nControlFlags;												// 4BC-4C0
	char pad5[0x1A];													// 4AC-4DA
	char m_nPlayerId;													// 4DA-4DB
	char pad6;															// 4DB-4DC
	int m_nState;														// 4DC-4E0 2: joined game 6: left
	char pad7[0x66];													// 4E0-546
	// 46C: another playerped but this time its networked
	char m_nNeverTired;													// 546-547
	char pad8[0x3];														// 547-54A
	short m_nMaxHealth;													// 54A-54C
	short m_nMaxArmor;													// 54C-54E
	char pad9[0x2];														// 54E-550
	char m_nCanDoDriveby;												// 550-551
	char pad10[0xB];													// 551-55C
	int m_nMood;														// 55C-560
	char pad11[0x10];													// 560-570
	int m_nColour;														// 570-574
	int m_nTeam;														// 574-578
	char pad12[0x8];													// 578-580
	char m_nHasDiedRecently;											// 580-581
	char pad13[0xB];													// 581-58C
	CPed* m_pPlayerPed;													// 58C-590
	char pad14[0x4];													// 590-594
	CVehicle* m_pOnlyEnterThisVehicle;									// 594-598
	char pad15[0x28];													// 598-5C0

	static CPlayerInfo* GetPlayerInfo(uint32_t nPlayerId)
	{
		return ((CPlayerInfo*(__cdecl*)(uint32_t))(Addresses::nGetPlayerInfo))(nPlayerId);
	}
};
VALIDATE_SIZE(CPlayerInfo, 0x5C0);
VALIDATE_OFFSET(CPlayerInfo, m_fStamina, 0x414);
VALIDATE_OFFSET(CPlayerInfo, m_sName, 0x4C);
VALIDATE_OFFSET(CPlayerInfo, m_nLastHitPedTime, 0x494);
VALIDATE_OFFSET(CPlayerInfo, m_nPlayerId, 0x4DA);
VALIDATE_OFFSET(CPlayerInfo, m_nState, 0x4DC);
VALIDATE_OFFSET(CPlayerInfo, m_nNeverTired, 0x546);
VALIDATE_OFFSET(CPlayerInfo, m_nMaxHealth, 0x54A);
VALIDATE_OFFSET(CPlayerInfo, m_nCanDoDriveby, 0x550);
VALIDATE_OFFSET(CPlayerInfo, m_nMood, 0x55C);
VALIDATE_OFFSET(CPlayerInfo, m_nTeam, 0x574);
VALIDATE_OFFSET(CPlayerInfo, m_pPlayerPed, 0x58C);
VALIDATE_OFFSET(CPlayerInfo, m_nControlFlags, 0x4BC);


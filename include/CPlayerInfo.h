class CPed;
class CVehicle;

class CPlayerInfo
{
public:
	uint8_t pad[0x4C];													// 000-04C
	char m_sName[20];													// 04C-060
	uint8_t pad2[0x390];												// 060-3F0
	CPed* m_pPlayerPed2;												// 3F0-3F4
	uint8_t pad3[0x20];													// 3F4-414
	float m_fStamina;													// 414-418
	uint8_t pad3_[0x7C];												// 418-494
	uint32_t m_nLastHitPedTime;											// 494-498
	uint32_t m_nLastHitBuildingTime;									// 498-49C
	uint32_t m_nLastHitObjectTime;										// 49C-4A0
	uint32_t m_nLastDroveOnPavementTime;								// 4A0-4A4
	uint32_t m_nLastRanLightTime;										// 4A4-4A8
	uint32_t m_nLastDroveAgainstTrafficTime;							// 4A8-4AC
	uint8_t pad4[0x10];													// 4AC-4BC
	uint32_t m_nControlFlags;											// 4BC-4C0
	uint8_t pad5[0x1A];													// 4AC-4DA
	uint8_t m_nPlayerId;												// 4DA-4DB
	uint8_t pad6;														// 4DB-4DC
	uint32_t m_nState;													// 4DC-4E0 2: joined game 6: left
	uint8_t pad7[0x66];													// 4E0-546
	// 46C: another playerped but this time its networked
	uint8_t m_nNeverTired;												// 546-547
	uint8_t pad8[0x3];													// 547-54A
	uint16_t m_nMaxHealth;												// 54A-54C
	uint16_t m_nMaxArmor;												// 54C-54E
	uint8_t pad9[0x2];													// 54E-550
	uint8_t m_nCanDoDriveby;											// 550-551
	uint8_t pad10[0xB];													// 551-55C
	uint32_t m_nMood;													// 55C-560
	uint8_t pad11[0x10];												// 560-570
	int32_t m_nColour;													// 570-574
	int32_t m_nTeam;													// 574-578
	uint8_t pad12[0x8];													// 578-580
	uint8_t m_nHasDiedRecently;											// 580-581
	uint8_t pad13[0xB];													// 581-58C
	CPed* m_pPlayerPed;													// 58C-590
	uint8_t pad14[0x4];													// 590-594
	CVehicle* m_pOnlyEnterThisVehicle;									// 594-598
	uint8_t pad15[0x28];												// 598-5C0

	static CPlayerInfo* GetPlayerInfo(uint32_t nPlayerId)
	{
		return ((CPlayerInfo*(__cdecl*)(uint32_t))(AddressSetter::Get(0x417F20, 0x3CD210)))(nPlayerId);
	}
	void KillPlayerOutsideWorld()
	{
		((void(__thiscall*)(CPlayerInfo*))(AddressSetter::Get(0x478F7D, 0x4B59D0)))(this);
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

CVector& FindPlayerCentreOfWorld(CVector* v)
{
	return ((CVector&(__cdecl*)(CVector*))(AddressSetter::Get(0x418100, 0x3CD3F0)))(v);
}

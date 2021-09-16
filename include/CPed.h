class CPhysical;
class CPedIntelligenceNY;
class CPlayerInfo;
class CPedDataNY;
class CObject;
class CVehicle;
class rmcDrawable;
class CCustomShaderEffectPedBoneDamageFX;

class CPedMoveBlendOnFoot
{
public:
	char pad[0x8];														// 00-08
	float m_fMoveState;													// 08-0C 3 - sprint, 2 - run, 1 - walk
	char pad1[0x10];													// 0C-1C
	float m_fMoveLeanAmount;											// 1C-20 3 is normal, less than 3 leans left, more than 3 leans right
	char pad2[0x8];														// 20-28
	float m_fMoveTurn;													// 28-2C
	char pad3[0x24];													// 2C-50
	int m_nUnkFlags;													// 50-54
	char pad4[0x18];													// 54-6C
	float m_fMoveAnimSpeed;												// 6C-70
	float m_fMaxMoveBlendRatio;											// 70-74 caps m_fMoveState
};
VALIDATE_OFFSET(CPedMoveBlendOnFoot, m_fMoveLeanAmount, 0x1C);
VALIDATE_OFFSET(CPedMoveBlendOnFoot, m_fMoveAnimSpeed, 0x6C);
VALIDATE_OFFSET(CPedMoveBlendOnFoot, m_fMoveState, 0x8);
VALIDATE_OFFSET(CPedMoveBlendOnFoot, m_fMoveTurn, 0x28);

struct PedWeaponSlot
{
	uint32_t m_nType;													// 00-04
	uint32_t* m_pAmmo;													// 04-08
	uint8_t m_nHasModelLoaded;											// 08-09
	uint8_t pad[0x3];													// 09-0C
};

struct PedWeapons
{
	uint8_t weaponspad1[0x18];											// 00-18 CPed 2B0-2C8
	uint32_t m_nActiveWeaponSlot;										// 18-1C CPed 2C8-2CC
	uint8_t weaponspad2[0x10];											// 1C-2C CPed 2CC-2DC
	CObject* m_pWeaponObject;											// 2C-30 CPed 2DC-2E0
	uint8_t weaponspad3[0xC];											// 30-3C CPed 2E0-388
	PedWeaponSlot m_aWeapons[12];										// 3C-CC CPed 2EC-37C
};
VALIDATE_SIZE(PedWeapons, 0xCC);
VALIDATE_OFFSET(PedWeapons, m_nActiveWeaponSlot, 0x18);
VALIDATE_OFFSET(PedWeapons, m_pWeaponObject, 0x2C);
VALIDATE_OFFSET(PedWeapons, m_aWeapons, 0x3C);

// incomplete - needs props
struct tPedDrawableInfo
{
	uint8_t pad[0x5C];														// 00-5C
	uint8_t m_nDrawables[11];												// 5C-67
	uint8_t m_nTextures[11];												// 67-72
};
VALIDATE_OFFSET(tPedDrawableInfo, m_nDrawables, 0x5C);
VALIDATE_OFFSET(tPedDrawableInfo, m_nTextures, 0x67);

struct tPedComponentModels
{
	rmcDrawable* m_pDrawables[11];								// 00-2C
	uint8_t pad[0x2C];											// 2C-58
	CCustomShaderEffectPedBoneDamageFX* m_pPedBoneDamageFX;		// 58-5C
	uint8_t pad2[0x6];											// 5C-62
};
VALIDATE_OFFSET(tPedComponentModels, m_pPedBoneDamageFX, 0x58);

class CPed : public CPhysical
{
public:																	// 000-210
	uint8_t m_nDoDeathCamera;											// 210-211
	uint8_t m_nReceiveDamage;											// 211-212
	uint8_t m_nDoDeath;													// 212-213
	uint8_t pad1;														// 213-214
	float m_fPedHealth;													// 214-218
	uint8_t m_nPlayerIndex;												// 218-219
	uint8_t m_bIsPlayer;												// 219-21A
	uint8_t pad2[0x2];													// 21A-21C
	tPedDrawableInfo* m_pDrawableInfo;									// 21C-220
	uint8_t pad3[0x4];													// 220-224
	CPedIntelligenceNY* m_pPedIntelligence;								// 224-228
	CPlayerInfo* m_pPlayerInfo;											// 228-22C
	CPedDataNY* m_pPedData;												// 22C-230
	uint8_t pad4[0x30];													// 230-260
	struct
	{
		unsigned int pad : 2;
		unsigned int m_bNoHeadshots : 1;
		unsigned int pad2 : 29;
	} m_nPedFlags;														// 260-264
	uint8_t pad5[0x8];													// 264-26C
	struct
	{
		unsigned int pad : 3;
		unsigned int m_inCar : 1;
		unsigned int pad2 : 9;
		unsigned int m_bInAir : 1;
		unsigned int pad3 : 18;
	} m_nPedFlags2;														// 26C-270
	uint8_t pad6[0x40];													// 270-2C8
	PedWeapons m_pWeaponData;											// 2B0-37C
	uint8_t pad7[0xC];													// 37C-388
	uint8_t m_nShootRate;												// 388-389
	uint8_t m_nAccuracy;												// 389-38A
	uint8_t pad8[0xFA];													// 38A-484
	CEntity* m_pStandingOnEntity;										// 484-488
	uint8_t pad9[0x194];												// 488-61C
	uint32_t m_nVoiceHash;												// 61C-620
	uint8_t pad10[0x1A8];												// 620-7C8
	int m_nRagdollStatus;												// 7C8-7CC
	int m_nRagdollTime;													// 7CC-7D0
	uint8_t pad11[0x21];												// 7D0-7F1
	uint8_t m_nWeaponObjectVisible;										// 7F1-7F2
	uint8_t pad12[0x27E];												// 7F2-A90
	uint8_t m_nCreatedBy;												// A70-A74
	uint8_t pad13[0x1C];												// A74-A90
	CPedMoveBlendOnFoot* m_pPedMoveBlendOnFoot;							// A90-A94
	float m_fMaxHealth;													// A94-A98
	uint8_t pad14[0x18];												// A98-AB0
	float m_fCurrentHeading;											// AB0-AB4
	float m_fDesiredHeading;											// AB4-AB8
	uint8_t pad15[0x88];												// AB8-B40
	CVehicle* m_pVehicle;												// B40-B44
	uint8_t pad16[0x364];												// B44-EA8
	tPedComponentModels* m_pComponentModels;							// EA8-EAC
	uint8_t pad17[0x54];												// EAC-F00

	CPad* GetPadFromPlayer()
	{
		return ((CPad * (__thiscall*)(CPed*))(Addresses::nGetPadFromPlayer))(this);
	}
};

VALIDATE_SIZE(CPed, 0xF00);
VALIDATE_OFFSET(CPed, m_nCreatedBy, 0xA70);
VALIDATE_OFFSET(CPed, m_nPlayerIndex, 0x218);
VALIDATE_OFFSET(CPed, m_nRagdollStatus, 0x7C8);
VALIDATE_OFFSET(CPed, m_nWeaponObjectVisible, 0x7F1);
VALIDATE_OFFSET(CPed, m_fMaxHealth, 0xA94);
VALIDATE_OFFSET(CPed, m_fCurrentHeading, 0xAB0);
VALIDATE_OFFSET(CPed, m_fDesiredHeading, 0xAB4);
VALIDATE_OFFSET(CPed, m_pVehicle, 0xB40);
VALIDATE_OFFSET(CPed, m_pDrawableInfo, 0x21C);
VALIDATE_OFFSET(CPed, m_nShootRate, 0x388);
VALIDATE_OFFSET(CPed, m_nAccuracy, 0x389);
VALIDATE_OFFSET(CPed, m_pPedMoveBlendOnFoot, 0xA90);
VALIDATE_OFFSET(CPed, m_pComponentModels, 0xEA8);
VALIDATE_OFFSET(CPed, m_nVoiceHash, 0x61C);
VALIDATE_OFFSET(CPed, m_pStandingOnEntity, 0x484);
VALIDATE_OFFSET(CPed, m_pWeaponData, 0x2B0);
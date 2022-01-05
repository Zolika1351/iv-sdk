#include "eVehiclePart.h"

class phArchetypeGta;
class gtaFragType;
struct tDrawableStruct;

enum eModelInfoType
{
	MODEL_INFO_INSTANCE = 1,
	MODEL_INFO_MLO = 2,
	MODEL_INFO_TIME = 3,
	MODEL_INFO_WEAPON = 4,
	MODEL_INFO_VEHICLE = 5,
	MODEL_INFO_PED = 6,
};

class CBaseModelInfo
{
public:
	uint8_t pad[0x4];								// 00-04
	phArchetypeGta* m_pArchetype;					// 04-08
	gtaFragType* m_pFragType;						// 08-0C only valid if model's loaded
	tDrawableStruct* m_pDrawableStruct;				// 0C-10 only valid if model's loaded
	uint8_t pad1[0x10];								// 10-20
	CVector m_vMinBounds;							// 20-2C
	float m_fDrawDistance;							// 2C-30
	CVector m_vMaxBounds;							// 30-3C
	uint32_t m_nHash;								// 3C-40
	uint32_t m_nIDEFlags;							// 40-44
	uint32_t m_nReferencesThisFrame;				// 44-48
	uint8_t pad2[0xE];								// 48-56
	int8_t m_nAnimIndex;							// 56-58
	uint8_t pad3[0x8];								// 58-60

	uint8_t GetModelType()
	{
		return ((uint8_t(__thiscall*)(CBaseModelInfo*))(*(void***)this)[3])(this);
	}
};
VALIDATE_SIZE(CBaseModelInfo, 0x60);
VALIDATE_OFFSET(CBaseModelInfo, m_pFragType, 0x8);
VALIDATE_OFFSET(CBaseModelInfo, m_pDrawableStruct, 0xC);
VALIDATE_OFFSET(CBaseModelInfo, m_vMinBounds, 0x20);
VALIDATE_OFFSET(CBaseModelInfo, m_fDrawDistance, 0x2C);
VALIDATE_OFFSET(CBaseModelInfo, m_vMaxBounds, 0x30);
VALIDATE_OFFSET(CBaseModelInfo, m_nHash, 0x3C);
VALIDATE_OFFSET(CBaseModelInfo, m_nAnimIndex, 0x56);
VALIDATE_OFFSET(CBaseModelInfo, m_nIDEFlags, 0x40);

struct CVehicleStructure
{
	uint32_t m_nBones[102];							// 000-198
	uint8_t pad[0x74];								// 198-20C
};
VALIDATE_SIZE(CVehicleStructure, 0x20C);

class CVehicleModelInfo : public CBaseModelInfo
{
public:
	char m_sGameName[12];							// 060-06C
	eVehicleType m_nVehicleType;					// 06C-070
	uint8_t pad[0x1C];								// 070-08C
	uint32_t m_nHandlingId;							// 08C-090
	uint8_t pad2[0x4];								// 090-094
	struct
	{
		unsigned int bSmallWorker : 1;
		unsigned int bBig : 1;
		unsigned int bNoBoot : 1;
		unsigned int bOnlyDuringOfficeHours : 1;
		unsigned int bBootInFront : 1;
		unsigned int bIsVan : 1;
		unsigned int bAvoidTurns : 1;
		unsigned int bLivery : 1;
		unsigned int bLiveryExtra : 1;
		unsigned int bSports : 1;
		unsigned int bDelivery : 1;
		unsigned int bNoAmbOcc : 1;
		unsigned int bOnlyOnHighways : 1;
		unsigned int bTallship : 1;
		unsigned int bTruckEngineFx : 1;
		unsigned int bTruckExhaustFx : 1;
		unsigned int bExtGang : 1;
		unsigned int bExtConv : 1;
		unsigned int bExtTaxi : 1;
		unsigned int bExtRare : 1;
		unsigned int bExtRequi : 1;
		unsigned int bExtStrong : 1;
		unsigned int bExtScript : 1;
		unsigned int bExtAll : 1;
		unsigned int bExtSunroof : 1;
		unsigned int bTruckFireFx : 1;
		unsigned int bBangerExhaustFx : 1;
		unsigned int pad : 5;
	} m_nVehicleFlags;								// 094-098
	uint8_t pad3[0x34];								// 098-09C
	CVehicleStructure* m_pVehicleStruct;			// 0CC-0D0
	uint8_t pad4[0x6C];								// 070-13C
	uint32_t m_nLiveryHashes[4];					// 13C-14C
	uint8_t pad5[0x284];							// 14C-3D0

	// sets center of mass and mass in the phBound based on the center of mass param and fMass off handling
	void SetHandlingParams(tHandlingData* pHandling, CVector* pCenterOfMass)
	{
		((void(__thiscall*)(CBaseModelInfo*, tHandlingData*, CVector*))(AddressSetter::Get(0x7E7D70, 0x6477B0)))(this, pHandling, pCenterOfMass);
	}

	static int GetNumberOfSeats(int modelIndex)
	{
		return ((int(__cdecl*)(int))(AddressSetter::Get(0x7E6A60, 0x6464A0)))(modelIndex);
	}
	
	void ChooseVehicleColour(uint8_t* color1, uint8_t* color2, uint8_t* color3, uint8_t* color4, int startingColor)
	{
		((void(__thiscall*)(CVehicleModelInfo*, uint8_t*, uint8_t*, uint8_t*, uint8_t*, int))(AddressSetter::Get(0x7E6930, 0x646370)))(this, color1, color2, color3, color4, startingColor);
	}

	static inline CRGBA* ms_vehicleColourTable = (CRGBA*)AddressSetter::Get(0x12D65A8, 0x1001BE0); // ms_vehicleColourTable[196]
};
VALIDATE_SIZE(CVehicleModelInfo, 0x3D0);
VALIDATE_OFFSET(CVehicleModelInfo, m_nHandlingId, 0x8C);
VALIDATE_OFFSET(CVehicleModelInfo, m_sGameName, 0x60);
VALIDATE_OFFSET(CVehicleModelInfo, m_nVehicleType, 0x6C);
VALIDATE_OFFSET(CVehicleModelInfo, m_nLiveryHashes, 0x13C);
VALIDATE_OFFSET(CVehicleModelInfo, m_pVehicleStruct, 0xCC);
VALIDATE_OFFSET(CVehicleModelInfo, m_nVehicleFlags, 0x94);

class CModelInfo
{
public:
	static inline CBaseModelInfo** ms_modelInfoPtrs = (CBaseModelInfo**)AddressSetter::Get(0x11F73B0, 0xE2C168); // ms_modelInfoPtrs[31000]
	static CBaseModelInfo* GetModelInfo(uint32_t hashKey, int* index)
	{
		return ((CBaseModelInfo*(__cdecl*)(uint32_t, int*))(AddressSetter::Get(0x58AAE0, 0x4DD2D0)))(hashKey, index);
	}
};
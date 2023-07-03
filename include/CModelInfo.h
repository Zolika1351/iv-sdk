#include "eVehiclePart.h"

class phArchetypeGta;
class gtaFragType;
struct tDrawableStruct;

enum ModelInfoType
{
	MI_TYPE_NONE = 0,
	MI_TYPE_ATOMIC = 1,
	MI_TYPE_MLO = 2,
	MI_TYPE_TIME = 3,
	MI_TYPE_WEAPON = 4,
	MI_TYPE_VEHICLE = 5,
	MI_TYPE_PED = 6,
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
	int16_t m_nTexDictionary;						// 48-4A -1 or index in the txd pool
	uint8_t pad2[0xC];								// 4A-56
	int8_t m_nAnimIndex;							// 56-58
	uint8_t pad3[0x8];								// 58-60

	uint8_t GetModelType()
	{
		return ((uint8_t(__thiscall*)(CBaseModelInfo*))(*(void***)this)[3])(this);
	}

	void SetAnimGroup(char* group)
	{
		((void(__thiscall*)(CBaseModelInfo*, char*))(AddressSetter::Get(0x58F3F0, 0x63D400)))(this, group);
	}

	void SetTexDictionary(char* txd)
	{
		((void(__thiscall*)(CBaseModelInfo*, char*))(AddressSetter::Get(0x58EE30, 0x63CE40)))(this, txd);
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

class CPedModelInfo : public CBaseModelInfo
{
public:
	uint8_t pad[0x20];								// 060-080
	int32_t m_nGestureAnimIndex;					// 080-084
	int32_t m_nFacialAnimIndex;						// 084-088
	int32_t m_nVisemesAnimIndex;					// 088-08C
	uint8_t m_bStreamedPed;							// 08C-08D load from player:/
	uint8_t pad2[0x3];								// 08C-090
	uint32_t m_nPedType;							// 090-094
	uint8_t pad3[0x28];								// 094-0BC
	uint32_t m_nVoiceHash;							// 0BC-0C0
	uint8_t pad4[0xA0];								// 0C0-160
};
VALIDATE_SIZE(CPedModelInfo, 0x160);
VALIDATE_OFFSET(CPedModelInfo, m_bStreamedPed, 0x8C);
VALIDATE_OFFSET(CPedModelInfo, m_nPedType, 0x90);
VALIDATE_OFFSET(CPedModelInfo, m_nGestureAnimIndex, 0x80);
VALIDATE_OFFSET(CPedModelInfo, m_nFacialAnimIndex, 0x84);
VALIDATE_OFFSET(CPedModelInfo, m_nVisemesAnimIndex, 0x88);
VALIDATE_OFFSET(CPedModelInfo, m_nVoiceHash, 0xBC);

class CVehicleStructure
{
public:
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
	uint8_t pad3[0x28];								// 098-0C0
	int16_t m_nAnimIndex2;							// 0C0-0C2
	uint8_t padC2[0xA];								// 0C2-0CC
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

	void SetSecondaryAnimGroup(char* group)
	{
		((void(__thiscall*)(CVehicleModelInfo*, char*))(AddressSetter::Get(0x7EAC80, 0x64A6C0)))(this, group);
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
VALIDATE_OFFSET(CVehicleModelInfo, m_nAnimIndex2, 0xC0);

class CModelInfo
{
public:
	static inline CBaseModelInfo** ms_modelInfoPtrs = (CBaseModelInfo**)AddressSetter::Get(0x11F73B0, 0xE2C168); // ms_modelInfoPtrs[31000]

	static CBaseModelInfo* GetModelInfo(uint32_t hashKey, int* index)
	{
		return ((CBaseModelInfo*(__cdecl*)(uint32_t, int*))(AddressSetter::Get(0x58AAE0, 0x4DD2D0)))(hashKey, index);
	}
	static CPedModelInfo* AddPedModel(char* modelName)
	{
		return ((CPedModelInfo*(__cdecl*)(char*))(AddressSetter::Get(0x58AE90, 0x4DD680)))(modelName);
	}
	static CVehicleModelInfo* AddVehicleModel(char* modelName)
	{
		return ((CVehicleModelInfo*(__cdecl*)(char*))(AddressSetter::Get(0x58AE20, 0x4DD610)))(modelName);
	}
	static CBaseModelInfo* AddAtomicModel(char* modelName)
	{
		return ((CBaseModelInfo*(__cdecl*)(char*))(AddressSetter::Get(0x58AC60, 0x4DD450)))(modelName);
	}
	static void Initialise()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x58AFF0, 0x4DD7B0)))();
	}
};
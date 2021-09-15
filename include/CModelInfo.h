#include "eVehiclePart.h"

class phArchetypeGta;
class gtaFragType;
struct tDrawableStruct;

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

struct tVehicleStruct
{
	uint8_t m_nBones[0x18C];						// 000-18C
	uint8_t pad[0x80];								// 18C-20C
};
VALIDATE_SIZE(tVehicleStruct, 0x20C);

class CVehicleModelInfo : public CBaseModelInfo
{
public:
	char m_sGameName[12];							// 060-06C
	eVehicleType m_nVehicleType;					// 06C-070
	uint8_t pad[0x24];								// 070-094
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
	uint8_t pad1[0x34];								// 098-09C
	tVehicleStruct* m_pVehicleStruct;				// 0CC-0D0
	uint8_t pad2[0x6C];								// 070-13C
	uint32_t m_nLiveryHashes[4];					// 13C-14C
	uint8_t pad3[0x284];							// 14C-3D0
};
VALIDATE_SIZE(CVehicleModelInfo, 0x3D0);
VALIDATE_OFFSET(CVehicleModelInfo, m_sGameName, 0x60);
VALIDATE_OFFSET(CVehicleModelInfo, m_nVehicleType, 0x6C);
VALIDATE_OFFSET(CVehicleModelInfo, m_nLiveryHashes, 0x13C);
VALIDATE_OFFSET(CVehicleModelInfo, m_pVehicleStruct, 0xCC);
VALIDATE_OFFSET(CVehicleModelInfo, m_nVehicleFlags, 0x94);

class CModelInfo
{
public:
	static inline CBaseModelInfo* ms_modelInfoPtrs; // ms_modelInfoPtrs[31000]
	static CBaseModelInfo* GetModelInfo(uint32_t hashKey, int* index)
	{
		return ((CBaseModelInfo*(__cdecl*)(uint32_t, int*))(Addresses::nGetModelInfo))(hashKey, index);
	}
};
namespace rage { class grmShaderGroup; }

class phArchetypeGta
{
public:
	uint8_t pad[0xC];													// 00-0C
	rage::phBound* m_pBounds;											// 0C-10
	uint8_t pad1[0x18];													// 10-28
	float m_fMaxSpeed;													// 28-2C
};
VALIDATE_OFFSET(phArchetypeGta, m_pBounds, 0xC);
VALIDATE_OFFSET(phArchetypeGta, m_fMaxSpeed, 0x28);

namespace rage
{
	struct crSkeletonData
	{
		char* m_sName;									// 00-04
		uint8_t pad[0x10];								// 04-14
		uint16_t m_nBoneID;								// 14-16
		uint8_t pad2[0xCA];								// 16-E0
	};
	VALIDATE_SIZE(crSkeletonData, 0xE0);
	VALIDATE_OFFSET(crSkeletonData, m_nBoneID, 0x14);

	class crSkeleton
	{
	public:
		crSkeletonData* m_aData;						// 00-04 array
		uint8_t pad[0x10];								// 04-14
		uint16_t m_nBoneCount;							// 14-18
		crSkeletonData* GetBoneDataByName(char* sName)
		{
			return ((crSkeletonData *(__thiscall*)(crSkeleton*, char*))(AddressSetter::Get(0x2434F0, 0x4F510)))(this, sName);
		}
	};
	VALIDATE_OFFSET(crSkeleton, m_aData, 0x0);
	VALIDATE_OFFSET(crSkeleton, m_nBoneCount, 0x14);

	class rmcDrawable
	{
	public:
		uint8_t pad[0x8];													// 000-050
		grmShaderGroup* m_pShaderGroup;										// 008-00C
		crSkeleton* m_pSkeleton;											// 00C-010
		uint8_t pad2[0x40];													// 010-050
		float m_fLodDistanceHigh;											// 050-054
		float m_fLodDistanceLow;											// 054-058
		float m_fLodDistanceVLow;											// 058-05C
		float m_fLodDistanceVLow2;											// 05C-060
	};
	VALIDATE_OFFSET(rmcDrawable, m_pShaderGroup, 0x8);
	VALIDATE_OFFSET(rmcDrawable, m_pSkeleton, 0xC);
	VALIDATE_OFFSET(rmcDrawable, m_fLodDistanceHigh, 0x50);
	VALIDATE_OFFSET(rmcDrawable, m_fLodDistanceLow, 0x54);

	class phInst
	{
	public:
		uint8_t pad[0x4];													// 00-04
		phArchetypeGta* m_pArchetype;										// 04-08 peds have phArchetypeGta, cars have phArchetypeDamp
		int16_t m_nRigidBodyIndex;											// 08-0A
		uint8_t pad2[0x2];													// 0A-0C
		CEntity* m_pEntity;													// 0C-10
		uint8_t pad3[0x30];													// 10-40
		CVector m_vPos;														// 40-4C
		uint8_t pad4[0x4];													// 4C-50
	};
	VALIDATE_SIZE(phInst, 0x50);
	VALIDATE_OFFSET(phInst, m_nRigidBodyIndex, 0x8);
	VALIDATE_OFFSET(phInst, m_pEntity, 0xC);
	VALIDATE_OFFSET(phInst, m_vPos, 0x40);
}

class gtaFragType
{
public:
	uint8_t pad[0xB4];													// 000-0B4
	rage::rmcDrawable* m_pDrawable;										// 0B4-0B8
	uint8_t pad2[0x2C];													// 0B8-0E4
	phArchetypeGta* m_pArchetype;										// 0E4-0E8
};
VALIDATE_OFFSET(gtaFragType, m_pDrawable, 0xB4); 
VALIDATE_OFFSET(gtaFragType, m_pArchetype, 0xE4);

class phInstGta : public rage::phInst
{
public:																	// 00-50
	uint8_t pad[0xC];													// 50-5C
	uint32_t* m_pUnkImportant;											// 5C-60
	uint8_t pad2[0x0C];													// 60-6C
	gtaFragType* m_pFragType;											// 6C-70

	// this is what's used to detach car parts, groupId is in the same order as groups are in the .oft file
	// use tDoor->m_nGroupID for vehicle doors, haven't found a way to see the rest of the bones, or anything for other entity types other than guessing
	phInstGta* DetachFragmentGroup(uint32_t groupId)
	{
		return ((phInstGta * (__thiscall*)(phInstGta*, signed int))(AddressSetter::Get(0x117D30, 0x245C10)))(this, groupId);
	}
};
VALIDATE_OFFSET(phInstGta, m_pFragType, 0x6C);
VALIDATE_OFFSET(phInstGta, m_pUnkImportant, 0x5C);
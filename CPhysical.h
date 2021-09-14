class CNetworkObject;
class phInstGta;
class CCustomShaderEffectVehicleFX;
class gtaDrawable;
class CPhysical;
class phConstrainedCollider;

struct tObjectDrawable
{
	gtaDrawable* m_pDrawable;											// 000-004
	CCustomShaderEffectVehicleFX* m_pShaderEffect;						// 004-008
	CPhysical* m_pEntityPtr;											// 008-00C
};

// someone split this damn thing into entity, dynamicentity and physical, this is a cry for help
class CPhysical
{
public:
	uint8_t pad[0x10];													// 000-010
	CVector m_vPosition;												// 010-01C
	float m_fHeading;													// 01C-020
	CMatrix* m_pMatrix;													// 020-024
	struct
	{
		unsigned int pad1 : 5;
		unsigned int m_bVisible : 1; // >> 5 & 1 - visible
		unsigned int pad2 : 26;
	} m_nEntityFlags;													// 024-028 >> 5 & 1 - visible
	uint32_t m_nEntityFlags2;											// 028-02C 0x80 - cast shadows
	uint8_t pad1[0x2];													// 02C-02E
	int16_t m_nModelIndex;												// 02E-030
	uint8_t pad2[0x4];													// 030-034
	tObjectDrawable* m_pDrawablePtr;									// 034-038
	phInstGta* m_pInstGta;												// 038-03C cars have fraginst, peds have phinst
	uint8_t pad3[0x10];													// 03C-04C
	uint32_t m_unkDeletePtr;											// 04C-050
	float m_fDrawDistance;												// 050-054
	uint8_t pad4_[0xF];													// 054-063
	uint8_t m_nAlpha;													// 063-064
	uint8_t pad5[0x8];													// 064-06C
	CNetworkObject* m_pNetworkObject;									// 06C-070
	uint8_t pad6[0x8];													// 070-078
	uint32_t* m_pAnim;													// 078-07C
	uint8_t pad7[0x9C];													// 07C-118
	struct
	{
		unsigned int flag1 : 6;
		unsigned int m_bBulletProof : 1;
		unsigned int m_bFireProof : 1;
		unsigned int m_bCollisionProof : 1;
		unsigned int m_bMeleeProof : 1;
		unsigned int m_bInvincible : 1;
		unsigned int m_bOnlyDamagedByPlayer : 1;
		unsigned int m_bExplosionProof : 1;
		unsigned int flag14 : 19;
	} m_nPhysicalFlags;													// 118-11C
	uint8_t pad9[0xA0];													// 11C-1BC
	CPhysical* m_pAttachedToEntity;										// 1BC-1C0
	CVector m_vAttachOffset;											// 1C0-1CC
	uint8_t pad10[0x4];													// 1CC-1D0
	CQuaternion m_qAttachOffset;										// 1D0-1E0
	uint8_t pad11[0x4];													// 1E0-1E4
	CPhysical* m_pLastDamageEntity;										// 1E4-1E8
	uint8_t pad12[0x4];													// 1E8-1EC
	int32_t m_nLastDamageWeapon;										// 1EC-1F0
	float m_fHealth;													// 1F0-1F4
	uint8_t pad13[0x1C];												// 1F4-210

	phConstrainedCollider* GetConstrainedCollider()
	{
		return ((phConstrainedCollider*(__thiscall*)(CPhysical*))(Addresses::nGetConstrainedCollider))(this);
	}
};

VALIDATE_SIZE(CPhysical, 0x210);
VALIDATE_OFFSET(CPhysical, m_fDrawDistance, 0x50);
VALIDATE_OFFSET(CPhysical, m_pAnim, 0x78);
VALIDATE_OFFSET(CPhysical, m_pLastDamageEntity, 0x1E4);
VALIDATE_OFFSET(CPhysical, m_nLastDamageWeapon, 0x1EC);
VALIDATE_OFFSET(CPhysical, m_fHealth, 0x1F0);
VALIDATE_OFFSET(CPhysical, m_nPhysicalFlags, 0x118);
VALIDATE_OFFSET(CPhysical, m_nEntityFlags, 0x24);
VALIDATE_OFFSET(CPhysical, m_pMatrix, 0x20);
VALIDATE_OFFSET(CPhysical, m_pInstGta, 0x38);
VALIDATE_OFFSET(CPhysical, m_pAttachedToEntity, 0x1BC);
VALIDATE_OFFSET(CPhysical, m_vAttachOffset, 0x1C0);
VALIDATE_OFFSET(CPhysical, m_qAttachOffset, 0x1D0);

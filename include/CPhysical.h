class phConstrainedCollider;

class CPhysical : public CDynamicEntity
{
public:
	uint8_t pad7[0x8];													// 110-118
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
	CEntity* m_pAttachedToEntity;										// 1BC-1C0
	CVector m_vAttachOffset;											// 1C0-1CC
	uint8_t pad10[0x4];													// 1CC-1D0
	CQuaternion m_qAttachOffset;										// 1D0-1E0
	uint8_t pad11[0x4];													// 1E0-1E4
	CEntity* m_pLastDamageEntity;										// 1E4-1E8
	uint8_t pad12[0x4];													// 1E8-1EC
	int32_t m_nLastDamageWeapon;										// 1EC-1F0
	float m_fHealth;													// 1F0-1F4
	uint8_t pad13[0x1C];												// 1F4-210

	phConstrainedCollider* GetConstrainedCollider()
	{
		return ((phConstrainedCollider*(__thiscall*)(CPhysical*))(AddressSetter::Get(0x5E7080, 0x505110)))(this);
	}

	CVector* GetVelocity(CVector* v)
	{
		return ((CVector*(__thiscall*)(CPhysical*, CVector*))(*(void***)this)[59])(this, v);
	}
};

VALIDATE_SIZE(CPhysical, 0x210);
VALIDATE_OFFSET(CPhysical, m_pLastDamageEntity, 0x1E4);
VALIDATE_OFFSET(CPhysical, m_nLastDamageWeapon, 0x1EC);
VALIDATE_OFFSET(CPhysical, m_fHealth, 0x1F0);
VALIDATE_OFFSET(CPhysical, m_nPhysicalFlags, 0x118);
VALIDATE_OFFSET(CPhysical, m_pAttachedToEntity, 0x1BC);
VALIDATE_OFFSET(CPhysical, m_vAttachOffset, 0x1C0);
VALIDATE_OFFSET(CPhysical, m_qAttachOffset, 0x1D0);

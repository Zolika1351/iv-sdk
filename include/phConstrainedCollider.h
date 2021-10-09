namespace rage
{
	class phSleep
	{
	public:
		uint8_t pad[0x4];													// 00-04
		float m_fMinVelocity;												// 04-08
	};
	VALIDATE_OFFSET(phSleep, m_fMinVelocity, 0x4);

	struct tUnkColliderParams2
	{
		uint8_t pad[0x1A0];													// 000-1A0
		CMatrix m_mMatrix;													// 1A0-1E0
		CVector_pad m_vUnk;													// 1E0-1F0
		CVector_pad m_vUnk2;												// 1F0-200
		uint8_t pad2[0x60];													// 200-260
		CVector_pad m_vVelocity;											// 260-270
		CVector_pad m_vRotationVelocity;									// 270-280
	};
	VALIDATE_OFFSET(tUnkColliderParams2, m_mMatrix, 0x1A0);
	VALIDATE_OFFSET(tUnkColliderParams2, m_vUnk, 0x1E0);
	VALIDATE_OFFSET(tUnkColliderParams2, m_vUnk2, 0x1F0);
	VALIDATE_OFFSET(tUnkColliderParams2, m_vVelocity, 0x260);
	VALIDATE_OFFSET(tUnkColliderParams2, m_vRotationVelocity, 0x270);
	struct tUnkColliderParams
	{
		uint32_t pad;														// 000-004
		tUnkColliderParams2* m_pParams2;									// 004-008
	};
	class phConstrainedCollider
	{
	public:
		uint8_t pad[0x18];													// 000-018
		phSleep* m_pSleep;													// 018-01C
		uint8_t pad2[0x74];													// 01C-090
		CVector_pad m_vPos2;												// 090-0A0
		uint8_t pad3[0x20];													// 0A0-100
		float m_fUnkScale;													// 0C0-0C4
		float m_fUnkScale2;													// 0C4-0C8 usually 0.0005889763124
		float m_fMaxSpeed;													// 0C8-0CC 80.0, copied from modelinfo
		float m_fMaxTurnSpeed;												// 0CC-0D0 6.283185482
		CVector_pad m_vUnk1;												// 0D0-0E0
		CVector_pad m_vUnk2;												// 0E0-0F0
		CVector_pad m_vUnk3;												// 0F0-100
		CVector_pad m_vPos;													// 100-110
		CVector_pad m_vPedVelocity;											// 110-120
		CVector_pad m_vUnk4;												// 120-130
		uint8_t pad4[0x170];												// 130-2A0
		tUnkColliderParams* m_pUnkParameters;								// 2A0-2A4

		void SetVelocity(CVector* v)
		{
			((void(__thiscall*)(phConstrainedCollider*, CVector*))(*(void***)this)[42])(this, v);
		}
	};
	VALIDATE_OFFSET(phConstrainedCollider, m_pSleep, 0x18);
	VALIDATE_OFFSET(phConstrainedCollider, m_vPos2, 0x90);
	VALIDATE_OFFSET(phConstrainedCollider, m_vPos, 0x100);
	VALIDATE_OFFSET(phConstrainedCollider, m_vPedVelocity, 0x110);
	VALIDATE_OFFSET(phConstrainedCollider, m_vUnk4, 0x120);
	VALIDATE_OFFSET(phConstrainedCollider, m_pUnkParameters, 0x2A0);
}
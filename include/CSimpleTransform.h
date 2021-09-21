class CSimpleTransform
{
public:
	CVector m_vPosition;												// 000-00C
	float m_fHeading;													// 00C-010
};

VALIDATE_SIZE(CSimpleTransform, 0x10);

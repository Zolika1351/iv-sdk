class CCam
{
public:
	char pad[0x10];														// 000-010
	CMatrix m_mMatrix;													// 010-050
	char pad2[0x10];													// 050-060
	float m_fFOV;														// 060-064
	float m_fFarZ;														// 064-068
};
VALIDATE_OFFSET(CCam, m_mMatrix, 0x10);
VALIDATE_OFFSET(CCam, m_fFOV, 0x60);
VALIDATE_OFFSET(CCam, m_fFarZ, 0x64);

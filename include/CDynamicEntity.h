class CDynamicEntity : public CEntity
{
public:
	uint8_t pad6[0x8];													// 070-078
	uint32_t* m_pAnim;													// 078-07C
	uint8_t pad7[0x94];													// 07C-110

	// initial matrix from the model without physical changes e.g. door opening, etc
	CMatrix* GetBoneMatrix(int boneID)
	{
		return ((CMatrix*(__thiscall*)(CDynamicEntity*, int))(AddressSetter::Get(0xD9100, 0x315390)))(this, boneID);
	}
};

VALIDATE_SIZE(CDynamicEntity, 0x110);
VALIDATE_OFFSET(CDynamicEntity, m_pAnim, 0x78);

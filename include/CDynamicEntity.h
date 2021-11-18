class CDynamicEntity : public CEntity
{
public:
	uint8_t pad6[0x8];													// 070-078
	uint32_t* m_pAnim;													// 078-07C
	uint8_t pad7[0x94];													// 07C-110

	// used for reading bone positions e.g. seat locations
	CMatrix* GetBoneMatrix(int boneID)
	{
		return ((CMatrix*(__thiscall*)(CDynamicEntity*, int))(AddressSetter::Get(0x5C7710, 0x4F1930)))(this, boneID);
	}

	// used for transform modifications e.g. popup lights, firetruck/apc cannon but 1:1 identical to the above
	CMatrix* GetBoneMatrix2(int boneID)
	{
		return ((CMatrix * (__thiscall*)(CDynamicEntity*, int))(AddressSetter::Get(0xD9100, 0x315390)))(this, boneID);
	}
};

VALIDATE_SIZE(CDynamicEntity, 0x110);
VALIDATE_OFFSET(CDynamicEntity, m_pAnim, 0x78);

class CDynamicEntity : public CEntity
{
public:
	uint8_t pad6[0x8];													// 070-078
	uint32_t* m_pAnim;													// 078-07C
	uint8_t pad7[0x94];													// 07C-110
};

VALIDATE_SIZE(CDynamicEntity, 0x110);
VALIDATE_OFFSET(CDynamicEntity, m_pAnim, 0x78);

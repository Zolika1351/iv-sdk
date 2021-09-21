class CInteriorInst : public CBuilding
{
public:
	uint8_t pad[0xF0];										// 070-160
};

VALIDATE_SIZE(CInteriorInst, 0x160);

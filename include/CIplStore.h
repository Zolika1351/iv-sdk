struct IplDef
{
	uint8_t pad[0x60];				// 00-60
};
VALIDATE_SIZE(IplDef, 0x60);

class CIplStore
{
public:
	static inline CQuadTreeNode*& ms_pQuadTree = AddressSetter::GetRef<CQuadTreeNode*>(0x128FF9C, 0xF6E46C);
	static inline CPool<IplDef>*& ms_pPool = AddressSetter::GetRef<CPool<IplDef>*>(0x128FF98, 0xF6E468); // dupe of the one in CPools for convenience

	static void LoadIpls(CVector pos, bool unk)
	{
		((void(__cdecl*)(CVector, bool))(AddressSetter::Get(0x726FA0, 0x60B8C0)))(pos, unk);
	}
	static void SetIplsRequired(CVector pos)
	{
		((void(__cdecl*)(CVector))(AddressSetter::Get(0x7267C0, 0x60B060)))(pos);
	}
};

bool& gbIplsNeededAtPosn = AddressSetter::GetRef<bool>(0x128FFA0, 0xF6E470);
CVector& gvecIplsNeededAtPosn = AddressSetter::GetRef<CVector>(0xB3BE50, 0xB49190);

void SetIfIplIsRequired(CVector2D* pos, IplDef* def)
{
	((void(__cdecl*)(CVector2D*, IplDef*))(AddressSetter::Get(0x726520, 0x60AD50)))(pos, def);
}

void SetIfIplIsRequiredReducedBB(CVector2D* pos, IplDef* def)
{
	((void(__cdecl*)(CVector2D*, IplDef*))(AddressSetter::Get(0x726560, 0x60AE00)))(pos, def);
}
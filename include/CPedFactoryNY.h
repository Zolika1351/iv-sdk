class CPedFactory
{

};

struct tUnkSpawnData
{
	uint8_t m_nFlag1;
	uint8_t m_nFlag2;
};
VALIDATE_SIZE(tUnkSpawnData, 0x2);

class CPedFactoryNY : public CPedFactory
{
public:

	CPed* CreatePed(tUnkSpawnData* pSpawnData, int32_t model, CMatrix* mat, bool bNetwork, bool bUnk1)
	{
		return ((CPed*(__thiscall*)(CPedFactoryNY*, tUnkSpawnData*, int32_t, CMatrix*, bool, bool))(*(void***)this)[5])(this, pSpawnData, model, mat, bNetwork, bUnk1);
	}
};

CPedFactoryNY*& PedFactory = AddressSetter::GetRef<CPedFactoryNY*>(0x11E35A0, 0xE52DE0);
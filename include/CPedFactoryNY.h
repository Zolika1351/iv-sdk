class CPedFactory
{

};

struct tSpawnData
{
	uint8_t m_nFlag1;
	uint8_t m_nFlag2;
};
VALIDATE_SIZE(tSpawnData, 0x2);

class CPedFactoryNY : public CPedFactory
{
public:

	CPed* CreatePed(tSpawnData* pSpawnData, int32_t model, CMatrix* mat, bool bNetwork, bool bUnk1)
	{
		return ((CPed*(__thiscall*)(CPedFactoryNY*, tSpawnData*, int32_t, CMatrix*, bool, bool))(*(void***)this)[5])(this, pSpawnData, model, mat, bNetwork, bUnk1);
	}
};

CPedFactoryNY*& PedFactory = AddressSetter::GetRef<CPedFactoryNY*>(0x11E35A0, 0xE52DE0);
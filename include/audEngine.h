class audConfig
{
public:

	void LoadFromFile(char* path)
	{
		((void(__thiscall*)(audConfig*, char*))(AddressSetter::Get(0x8E4020, 0x3AC520)))(this, path);
	}
};

class audEngine
{
public:
	static inline audConfig& m_pSoundsConfig = AddressSetter::GetRef<audConfig>(0x1316F18, 0xCF1BE8);
	static inline audConfig& m_pCurvesConfig = AddressSetter::GetRef<audConfig>(0x1316D04, 0xCF19D4);
	static inline audConfig& m_pGameConfig = AddressSetter::GetRef<audConfig>(0x1316F74, 0xCF1C44);

	// this is used after every category patch, but the parameter is 1 in ep2 and 0 in the rest
	void SetUnknown(float unk1)
	{
		((void(__thiscall*)(audEngine*, float))(AddressSetter::Get(0x8DC360, 0x39CC60)))(this, unk1);
	}
};

audEngine& AudioEngine = AddressSetter::GetRef<audEngine>(0x1316CA0, 0xCF1970);
class CRadioStation
{
public:
	uint8_t pad[0x17FC];								// 0000-17FC
	char m_sName[32];									// 17FC-181C
	uint8_t pad2[0x118];								// 181C-1934
	static CRadioStation* GetRadioStation(int id)
	{
		return ((CRadioStation*(__cdecl*)(int))(AddressSetter::Get(0x6C4CC0, 0x3D6E30)))(id);
	}
};
VALIDATE_SIZE(CRadioStation, 0x1934);
VALIDATE_OFFSET(CRadioStation, m_sName, 0x17FC);

class audRadioAudioEntity
{
public:
	uint8_t pad[0x78];								// 00-78
	uint32_t m_nCurrentRadioStation;				// 78-7C
};
VALIDATE_OFFSET(audRadioAudioEntity, m_nCurrentRadioStation, 0x78);

audRadioAudioEntity& RadioAudioEntity = AddressSetter::GetRef<audRadioAudioEntity>(0xDA3700, 0xD71F48);
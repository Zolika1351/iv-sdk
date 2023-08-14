class audRadioAudioEntity
{
public:
	uint8_t pad[0x78];								// 00-78
	uint32_t m_nCurrentRadioStation;				// 78-7C
};
VALIDATE_OFFSET(audRadioAudioEntity, m_nCurrentRadioStation, 0x78);

audRadioAudioEntity& RadioAudioEntity = AddressSetter::GetRef<audRadioAudioEntity>(0xDA3700, 0xD71F48);
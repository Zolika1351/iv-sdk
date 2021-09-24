namespace rage
{
	class SkyhatMiniNoise
	{
	public:
		uint8_t pad[0x14];									// 000-014
		grcRenderTargetPC* m_pRenderTarget;					// 014-018
		uint8_t pad2[0xC];									// 018-024
		CSprite2d m_pTexture[6];							// 024-03C
		uint8_t pad3[0x204];								// 03C-240
	};
	VALIDATE_SIZE(SkyhatMiniNoise, 0x240);
	VALIDATE_OFFSET(SkyhatMiniNoise, m_pRenderTarget, 0x14);
	VALIDATE_OFFSET(SkyhatMiniNoise, m_pTexture, 0x24); // 24-3C 48 last

	class SkyDome
	{
	public:
		uint8_t pad[0x10];									// 000-010
		SkyhatMiniNoise m_sSkyhatMiniNoise;					// 010-250
		uint8_t pad2[0xE0];									// 250-330
	};
	VALIDATE_SIZE(SkyDome, 0x330);
	VALIDATE_OFFSET(SkyDome, m_sSkyhatMiniNoise, 0x10);
}
rage::SkyDome*& TheSkyDome = AddressSetter::GetRef<rage::SkyDome*>(0x130B040, 0x13366A8);
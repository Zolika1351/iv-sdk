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
		uint8_t pad2[0xA8];									// 250-2F8

		// shader technique IDs, which are all stored in skydome for some reason
		uint32_t m_nDPSkyFront;								// 2F8-2FC
		uint32_t m_nDPSkyBack;								// 2FC-300
		uint32_t m_nParaboloid;								// 300-304
		uint32_t m_nDraw;									// 304-308
		uint32_t m_nDrawWithMoon;							// 308-30C
		uint32_t m_nDrawStencil;							// 30C-310
		uint32_t m_nDrawSunOnly;							// 310-314

		uint8_t pad3[0x1C];									// 314-330

		static inline char*& sTexturePath = AddressSetter::GetRef<char*>(0x882791, 0x8A2741);
	};
	VALIDATE_SIZE(SkyDome, 0x330);
	VALIDATE_OFFSET(SkyDome, m_sSkyhatMiniNoise, 0x10);
	VALIDATE_OFFSET(SkyDome, m_nDPSkyFront, 0x2F8);
	VALIDATE_OFFSET(SkyDome, m_nDPSkyBack, 0x2FC);
	VALIDATE_OFFSET(SkyDome, m_nParaboloid, 0x300);
	VALIDATE_OFFSET(SkyDome, m_nDraw, 0x304);
	VALIDATE_OFFSET(SkyDome, m_nDrawWithMoon, 0x308);
	VALIDATE_OFFSET(SkyDome, m_nDrawStencil, 0x30C);
	VALIDATE_OFFSET(SkyDome, m_nDrawSunOnly, 0x310);
}
rage::SkyDome*& TheSkyDome = AddressSetter::GetRef<rage::SkyDome*>(0x130B040, 0x13366A8);
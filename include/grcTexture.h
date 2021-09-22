namespace rage
{
	class grcTexture
	{
	public:
	};

	class grcTexturePC : public grcTexture
	{
	public:
		uint8_t pad[0x18];								// 00-18
		LPDIRECT3DTEXTURE9 m_pD3DTexture = nullptr;		// 18-1C
		uint8_t pad2[0x34];								// 1C-50

		// this doesn't actually seem to load textures? it always creates a dummy one, maybe there's another function that does that
		grcTexturePC(char* sName, uint32_t* pUnk = nullptr)
		{
			((void(__stdcall*)(grcTexturePC*, char*, uint32_t*))(AddressSetter::Get(0x22AF70, 0x220A0)))(this, sName, pUnk);
		}
	};
	VALIDATE_SIZE(grcTexturePC, 0x50);
}
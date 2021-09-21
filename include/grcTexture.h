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
		LPDIRECT3DTEXTURE9 m_pD3DTexture;				// 18-1C
		uint8_t pad2[0x34];								// 1C-50
	};
	VALIDATE_SIZE(grcTexturePC, 0x50);
}
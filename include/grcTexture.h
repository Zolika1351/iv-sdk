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
		IDirect3DBaseTexture9* m_pBaseTexture;			// 18-1C
	};
}
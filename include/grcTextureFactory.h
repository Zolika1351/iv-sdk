namespace rage
{
	class grcTextureFactory
	{

	};

	class grcTextureFactoryPC : public grcTextureFactory
	{
	public:
		uint8_t pad[0x70];								// 00-70

		grcTexturePC* CreateTexture(char* sName, uint32_t* pUnk = nullptr)
		{
			return ((grcTexturePC*(__stdcall*)(grcTextureFactoryPC*, char*, uint32_t*))(*(void***)this)[3])(this, sName, pUnk);
		}
	};
	VALIDATE_SIZE(grcTextureFactoryPC, 0x70);

	grcTextureFactoryPC*& TextureFactory = AddressSetter::GetRef<grcTextureFactoryPC*>(0x14A8630, 0x14CAD4C);
}
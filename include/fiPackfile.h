namespace rage
{
	class fiPackfile
	{
	public:
		uint8_t pad[0x478];						// 000-478

		fiPackfile()
		{
			((void(__thiscall*)(fiPackfile*))(AddressSetter::Get(0x1BCCF0, 0x5EAB0)))(this);
		}

		bool OpenPackfile(char* path, char unk1_1, char unk2_0, int unk3_0or3)
		{
			return ((bool(__thiscall*)(fiPackfile*, char*, char, char, int))(AddressSetter::Get(0x1BCE10, 0x5EBD0)))(this, path, unk1_1, unk2_0, unk3_0or3);
		}

		bool Mount(char* mountPoint)
		{
			return ((bool(__thiscall*)(fiPackfile*, char*))(AddressSetter::Get(0x1BD3A0, 0x5F160)))(this, mountPoint);
		}
	};
	VALIDATE_SIZE(fiPackfile, 0x478);
}
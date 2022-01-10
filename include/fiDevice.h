namespace rage
{
	class fiDeviceLocal
	{
		uint32_t m_pVFTable = AddressSetter::Get(0x95A9BC, 0x9894C4);
		uint8_t pad[0x20C];
	};
	VALIDATE_SIZE(fiDeviceLocal, 0x210);

	class fiDevice
	{
	public:
		static inline int& g_nMaxMountPoints = AddressSetter::GetRef<int>(0x22E6, 0x8FB46);

		uint32_t m_pVFTable = AddressSetter::Get(0x953D0C, 0x9856A4);
		uint8_t pad[0x20C];

		uint32_t SetPath(char* path, bool bAbsolute)
		{
			return ((uint32_t(__thiscall*)(fiDevice*, char*, bool))(AddressSetter::Get(0x1B43F0, 0x6F7D0)))(this, path, bAbsolute);
		}

		uint32_t SetMountPath(char* path)
		{
			return ((uint32_t(__thiscall*)(fiDevice*, const char*))(AddressSetter::Get(0x1B4480, 0x6F860)))(this, path);
		}

		static bool Mount(char* path, fiDeviceLocal* device, bool bUnk1)
		{
			return ((char(__cdecl*)(const char*, fiDeviceLocal*, int))(AddressSetter::Get(0x1ABE20, 0x5DDA0)))(path, device, bUnk1);
		}
	};
	VALIDATE_SIZE(fiDevice, 0x210);
};
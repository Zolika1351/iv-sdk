namespace AddressSetter
{
	uint32_t gBaseAddress;
	bool bAddressesRead = false;

	uint32_t GetVersionFromEXE()
	{
		TCHAR szFileName[MAX_PATH];

		GetModuleFileName(NULL, szFileName, MAX_PATH);

		DWORD  verHandle = 0;
		UINT   size = 0;
		LPBYTE lpBuffer = NULL;
		DWORD  verSize = GetFileVersionInfoSize(szFileName, &verHandle);

		if (verSize != NULL)
		{
			LPSTR verData = new char[verSize];

			if (GetFileVersionInfo(szFileName, verHandle, verSize, verData))
			{
				if (VerQueryValue(verData, TEXT("\\"), (VOID FAR * FAR*) & lpBuffer, &size))
				{
					if (size)
					{
						VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
						if (verInfo->dwSignature == 0xfeef04bd)
						{
							std::string str = std::to_string((verInfo->dwFileVersionMS >> 16) & 0xffff);
							str += std::to_string((verInfo->dwFileVersionMS >> 0) & 0xffff);
							str += std::to_string((verInfo->dwFileVersionLS >> 16) & 0xffff);
							str += std::to_string((verInfo->dwFileVersionLS >> 0) & 0xffff);
							delete[] verData;
							return std::stoi(str);
						}
					}
				}
			}
			delete[] verData;
		}
		return 0;
	}

	// 1040 is too different to support in this project
	void DetermineVersion()
	{
		uint32_t ver = GetVersionFromEXE();
		switch (ver)
		{
		case 1070:
			plugin::gameVer = plugin::VERSION_1070;
			break;
		case 1080:
			plugin::gameVer = plugin::VERSION_1080;
			break;
		default:
			plugin::gameVer = plugin::VERSION_NONE;
			break;
		}
	}

	void PickAddressesByVersion()
	{
		gBaseAddress = (uint32_t)GetModuleHandle(NULL);
		switch (plugin::gameVer)
		{
		case plugin::VERSION_1070:
			Addresses::nProcessScriptsEvent = gBaseAddress + 0x21601;
			Addresses::nGameLoadEvent = gBaseAddress + 0x4ADB38;
			break;
		case plugin::VERSION_1080:
			Addresses::nProcessScriptsEvent = gBaseAddress + 0x95141;
			Addresses::nGameLoadEvent = gBaseAddress + 0x770748;
			break;
		default:
			break;
		}
	}

	void Init()
	{
		DetermineVersion();
		PickAddressesByVersion();
	}

	// note that the base address is added here and 0x400000 is not subtracted, so rebase your .idb to 0x0 or subtract it yourself
	template<typename T> T& GetRef(uint32_t addr1070, uint32_t addr1080)
	{
		if (!bAddressesRead)
		{
			Init();
		}
		if (plugin::gameVer == plugin::VERSION_1070) return *reinterpret_cast<T*>(gBaseAddress + addr1070);
		if (plugin::gameVer == plugin::VERSION_1080) return *reinterpret_cast<T*>(gBaseAddress + addr1080);
		return *reinterpret_cast<T*>(nullptr);
	}

	uint32_t Get(uint32_t addr1070, uint32_t addr1080)
	{
		if (!bAddressesRead)
		{
			Init();
		}
		if (plugin::gameVer == plugin::VERSION_1070) return gBaseAddress + addr1070;
		if (plugin::gameVer == plugin::VERSION_1080) return gBaseAddress + addr1080;
		return 0;
	}
}
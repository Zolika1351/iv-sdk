class CZone
{
public:
	char InfoLabel[8];								// 00-08
	char TextLabel[8];								// 08-10
	int16_t MinX;									// 10-12
	int16_t MinY;									// 12-14
	int16_t MinZ;									// 14-16
	int16_t MaxX;									// 16-18
	int16_t MaxY;									// 18-1A
	int16_t MaxZ;									// 1A-1C
	int16_t unk1;									// 1C-1E
	int16_t unk2;									// 1E-20
	uint8_t PopulationType;							// 20-21
	uint8_t Scumminess;								// 21-22
	uint8_t pad[0x6];								// 22-28
};
VALIDATE_SIZE(CZone, 0x28);
VALIDATE_OFFSET(CZone, TextLabel, 0x8);
VALIDATE_OFFSET(CZone, PopulationType, 0x20);

class CTheZones
{
public:
	static inline auto& TotalNumberOfMapZones = AddressSetter::GetRef<uint32_t>(0xE05CA4, 0x1001F14);
	static inline auto MapZoneArray = (CZone*)AddressSetter::Get(0xE05D10, 0x1001F80);

	static inline auto& ZonesRevealed = AddressSetter::GetRef<uint32_t>(0xE05C90, 0x1001F00);
	static inline auto ZonesVisited = (bool*)AddressSetter::Get(0xE05CA8, 0x1001F18); // ZonesVisited[100] ZonesVisited[10][10]

	static bool Save()
	{
		return ((int(__cdecl*)())(AddressSetter::Get(0x48BF30, 0x64AAB0)))();
	}
	static bool Load()
	{
		return ((int(__cdecl*)())(AddressSetter::Get(0x48BF90, 0x64AB10)))();
	}
};
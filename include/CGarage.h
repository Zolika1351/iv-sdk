class CStoredCar
{
public:
	// the pad spaces here are completely unused
	float CoorX;								// 00-04
	float CoorY;								// 04-08
	float CoorZ;								// 08-0C
	uint32_t FlagsLocal;						// 0C-10
	uint16_t ModelIndex;						// 10-12
	uint8_t pad2[0x1D];							// 12-30
	uint16_t Bits;								// 30-32
	uint8_t Colour1;							// 32-33
	uint8_t Colour2;							// 33-34
	uint8_t Colour3;							// 34-35
	uint8_t Colour4;							// 35-36
	uint8_t pad3[0x2];							// 36-38
	uint32_t Extras;							// 38-3C CVehicle+0xE20
	uint32_t PaintJob;							// 3C-40
	uint8_t pad4[0x2];							// 40-42
	uint8_t unk2;								// 42-33 CVehicle+0x10C2
	int8_t iFrontX;								// 43-44
	int8_t iFrontY;								// 44-45
	int8_t iFrontZ;								// 45-46
	uint8_t pad5[0x2];							// 46-48

	void StoreCar(CVehicle* pCar)
	{
		((void(__thiscall*)(CStoredCar*, CVehicle*))(AddressSetter::Get(0x88A430, 0x868B90)))(this, pCar);
	}
	void RestoreCar()
	{
		((void(__thiscall*)(CStoredCar*))(AddressSetter::Get(0x88A600, 0x868D60)))(this);
	}
};
VALIDATE_SIZE(CStoredCar, 0x48);
VALIDATE_OFFSET(CStoredCar, CoorX, 0);
VALIDATE_OFFSET(CStoredCar, FlagsLocal, 0xC);
VALIDATE_OFFSET(CStoredCar, ModelIndex, 0x10);
VALIDATE_OFFSET(CStoredCar, Bits, 0x30);
VALIDATE_OFFSET(CStoredCar, Colour1, 0x32);
VALIDATE_OFFSET(CStoredCar, PaintJob, 0x3C);
VALIDATE_OFFSET(CStoredCar, iFrontX, 0x43);
VALIDATE_OFFSET(CStoredCar, iFrontZ, 0x45);
VALIDATE_OFFSET(CStoredCar, unk2, 0x42);

class CGarage
{
public:
	float BaseX;								// 00-04
	float BaseY;								// 04-08
	float BaseZ;								// 08-0C
	float Delta1X;								// 0C-10
	float Delta1Y;								// 10-14
	float Delta2X;								// 14-18
	float Delta2Y;								// 18-1C
	float CeilingZ;								// 1C-20
	float Delta1Length;							// 20-24
	float Delta2Length;							// 24-28
	float MinX;									// 28-2C
	float MaxX;									// 2C-30
	float MinY;									// 30-34
	float MaxY;									// 34-38
	uint8_t pad2[0x4];							// 38-3C
	CVehicle* pCarToCollect;					// 3C-40
	uint8_t pad3[0x8];							// 40-48
	uint8_t Type;								// 48-49
	uint8_t pad4[0x23];							// 49-6C

	bool IsPointInsideGarage(CVector Point)
	{
		return ((bool(__thiscall*)(CGarage*))(AddressSetter::Get(0x4FF4D0, 0x565AA0)))(this);
	}
	void PlayerArrestedOrDied()
	{
		((void(__thiscall*)(CGarage*))(AddressSetter::Get(0x4FF480, 0x565A50)))(this);
	}
	void StoreAndRemoveCarsForThisHideOut(CStoredCar* aStoredCars, bool unk)
	{
		((void(__thiscall*)(CGarage*, CStoredCar*, bool))(AddressSetter::Get(0x500DF0, 0x5673C0)))(this, aStoredCars, unk);
	}
	void TidyUpGarageClose()
	{
		((void(__thiscall*)(CGarage*))(AddressSetter::Get(0x500960, 0x566F30)))(this);
	}
	void Update()
	{
		((void(__thiscall*)(CGarage*))(AddressSetter::Get(0x501230, 0x567810)))(this);
	}
};
VALIDATE_SIZE(CGarage, 0x6C);
VALIDATE_OFFSET(CGarage, BaseZ, 0x8);
VALIDATE_OFFSET(CGarage, Delta2Length, 0x24);
VALIDATE_OFFSET(CGarage, CeilingZ, 0x1C);
VALIDATE_OFFSET(CGarage, Delta1Length, 0x20);
VALIDATE_OFFSET(CGarage, MinX, 0x28);
VALIDATE_OFFSET(CGarage, pCarToCollect, 0x3C);
VALIDATE_OFFSET(CGarage, Type, 0x48);

class CSaveGarage
{
public:
	uint8_t pad[0x48];

	void CopyGarageIntoSaveGarage(CGarage* pGarage)
	{
		((void(__thiscall*)(CSaveGarage*, CGarage*))(AddressSetter::Get(0x4FEF00, 0x5654D0)))(this, pGarage);
	}
	void CopyGarageOutOfSaveGarage(CGarage* pGarage)
	{
		((void(__thiscall*)(CSaveGarage*, CGarage*))(AddressSetter::Get(0x4FEF90, 0x565560)))(this, pGarage);
	}
};
VALIDATE_SIZE(CSaveGarage, 0x48);

class CGarages
{
public:

	static inline auto& bCamShouldBeOutside = AddressSetter::GetRef<bool>(0xCD0170, 0xECBDF4);
	static inline auto& bHasResprayHappened = AddressSetter::GetRef<bool>(0xF54A62, 0xECBDDA);
	static inline auto& MessageStartTime = AddressSetter::GetRef<uint32_t>(0xF54A54, 0xECBDCC);
	static inline auto& MessageEndTime = AddressSetter::GetRef<uint32_t>(0xF54A74, 0xECBDEC);
	static inline auto& LastGaragePlayerWasIn = AddressSetter::GetRef<int32_t>(0xF54A70, 0xECBDE8);
	static inline auto& LastTimeHelpMessage = AddressSetter::GetRef<uint32_t>(0xF54A68, 0xECBDE0);

	static inline auto& BombsAreFree = AddressSetter::GetRef<bool>(0xF54A60, 0xECBDD8);
	static inline auto& RespraysAreFree = AddressSetter::GetRef<bool>(0xF54A63, 0xECBDDB);
	static inline auto& NoResprays = AddressSetter::GetRef<bool>(0xF54A61, 0xECBDD9);

	static inline auto& NumGarages = AddressSetter::GetRef<uint32_t>(0xF54A64, 0xECBDDC);
	static inline CGarage* aGarages = (CGarage*)AddressSetter::Get(0xF55030, 0xECC3A8); // aGarages[40]
	static inline CStoredCar* aCarsInSafeHouse = (CStoredCar*)AddressSetter::Get(0xF54A88, 0xECBE00); // aCarsInSafeHouse[20]

	static bool CameraShouldBeOutside()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x4FF470, 0x565A40)))();
	}
	static void CloseHideOutGaragesBeforeSave(bool unk)
	{
		((void(__cdecl*)(bool))(AddressSetter::Get(0x500FE0, 0x5675B0)))(unk);
	}
	static void Init()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x4FF080, 0x565650)))();
	}
	static bool Load()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x501110, 0x5676E0)))();
	}
	static void PlayerArrestedOrDied()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x500A90, 0x567060)))();
	}
	static bool Save()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x501030, 0x567600)))();
	}
	static void Shutdown()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x4FF020, 0x5655F0)))();
	}
	static void Update()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x502200, 0x5687E0)))();
	}
};
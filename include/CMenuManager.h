class CMenuManager
{
public:
	static inline uint32_t& m_bInvertMouseX = AddressSetter::GetRef<uint32_t>(0xCC7A00, 0xCFC0D0);
	static inline uint32_t& m_bInvertRightStickX = AddressSetter::GetRef<uint32_t>(0xCC7A04, 0xCFC0D4);
	static inline uint32_t& m_bAutoSave = AddressSetter::GetRef<uint32_t>(0xCC79F0, 0xCFC0C0);
	static inline uint32_t& m_bClipCapture = AddressSetter::GetRef<uint32_t>(0xCC7C58, 0xCFC328);
	static inline uint32_t& m_bHeliMouseControls = AddressSetter::GetRef<uint32_t>(0xCC7C78, 0xCFC348);
	static inline uint32_t& m_bHudOn = AddressSetter::GetRef<uint32_t>(0xCC7A2C, 0xCFC0FC);

	static inline uint32_t& m_nMouseSensitivity = AddressSetter::GetRef<uint32_t>(0xCC7C10, 0xCFC2E0);

	// written to float values when changed in menu
	static inline uint32_t& m_nBrightness = AddressSetter::GetRef<uint32_t>(0xCC7A18, 0xCFC0E8);
	static inline uint32_t& m_nContrast = AddressSetter::GetRef<uint32_t>(0xCC7A1C, 0xCFC0EC);
	static inline uint32_t& m_nSaturation = AddressSetter::GetRef<uint32_t>(0xCC7A20, 0xCFC0F0);

	static inline uint32_t& m_nVehicleDensity = AddressSetter::GetRef<uint32_t>(0xCC7C3C, 0xCFC30C);

	static inline float& m_fBrightness = AddressSetter::GetRef<float>(0xB21704, 0xB38208);
	static inline float& m_fContrast = AddressSetter::GetRef<float>(0xB21708, 0xB3820C);
	static inline float& m_fSaturation = AddressSetter::GetRef<float>(0xB2170C, 0xB38210);
};
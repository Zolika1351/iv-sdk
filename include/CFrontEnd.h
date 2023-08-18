class CFrontEnd
{
public:
	static inline auto& g_iUserWaypointID = AddressSetter::GetRef<int32_t>(0xCC79EC, 0xCFC0BC);
	static inline auto& vMapCursor = AddressSetter::GetRef<CVector2D>(0xCC8308, 0xCFC9D8);

	static void SwitchOnWaypoint(int unk_8, float x, float y, bool snapToHoveringBlip, CVector* outPos)
	{
		return ((void(__cdecl*)(int, float, float, bool, CVector*))(AddressSetter::Get(0x38C270, 0x3C2F60)))(unk_8, x, y, snapToHoveringBlip, outPos);
	}
	static void SwitchOffWaypoint()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x3880C0, 0x3BEDB0)))();
	}
	static void ToggleWaypoint()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x1B500, 0x8B520)))();
	}
};
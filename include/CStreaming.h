class CStreaming
{
public:
	static inline uint8_t& ms_disableStreaming = AddressSetter::GetRef<uint8_t>(0xE1DFAA, 0xF997D2);
	// this is easier to use until RequestModel is fully documented
	static void ScriptRequestModel(int32_t nHash, uint32_t* pRunningThread = nullptr)
	{
		((void(__cdecl*)(int32_t, uint32_t*))(AddressSetter::Get(0x76C3D0, 0x7191D0)))(nHash, pRunningThread);
	}
	//ScriptRequestModel: CStreaming::RequestModel(v4, dword_11F73A0, dword_12C38A8 | 0xC);
	// todo: look into this
	static void RequestModel(int32_t modelIndex, int32_t unk1, int32_t nFlags)
	{
		((void(__cdecl*)(int32_t, int32_t, int32_t))(AddressSetter::Get(0x432C40, 0x4B4BD0)))(modelIndex, unk1, nFlags);
	}
	static void LoadAllRequestedModels(bool priorityOnly)
	{
		((void(__cdecl*)(bool))(AddressSetter::Get(0x432C20, 0x4B4BB0)))(priorityOnly);
	}
};
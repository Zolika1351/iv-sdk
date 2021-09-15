class CStreaming
{
public:
	static inline uint8_t& ms_disableStreaming = *(uint8_t*)nullptr;
	// this is easier to use until RequestModel is fully documented
	static void ScriptRequestModel(int32_t modelIndex, uint32_t* pRunningThread = nullptr)
	{
		((void(__cdecl*)(int32_t, uint32_t*))(Addresses::nScriptRequestModel))(modelIndex, pRunningThread);
	}
	//ScriptRequestModel: CStreaming::RequestModel(v4, dword_11F73A0, dword_12C38A8 | 0xC);
	// todo: look into this
	static void RequestModel(int32_t modelIndex, int32_t unk1, int32_t nFlags)
	{
		((void(__cdecl*)(int32_t, int32_t, int32_t))(Addresses::nRequestModel))(modelIndex, unk1, nFlags);
	}
	static void LoadAllRequestedModels(bool priorityOnly)
	{
		((void(__cdecl*)(bool))(Addresses::nLoadAllRequestedModels))(priorityOnly);
	}
};
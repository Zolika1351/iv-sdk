class CTxdStore
{
	static void PushCurrentTxd()
	{
		((void(__cdecl*)())(Addresses::nPushCurrentTxd))();
	}
	static void PopCurrentTxd()
	{
		((void(__cdecl*)())(Addresses::nPopCurrentTxd))();
	}
};
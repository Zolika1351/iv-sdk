class CProjectileInfo
{
public:
	// start is usually pos
	// end is pos + dir vector
	// the actual position is read from the matrix so no idea why the start vector exists
	// 0 0 0 start vec makes the end vec act as a direction vector and it seems to work fine
	// object can be null, it'll create one if it is
	static bool AddProjectile(CEntity* pEntProjOwner, int ProjType, CMatrix* pMatrix, CVector* vecStart, CVector* vecEnd, CEntity* pTargetEntity, bool noMPSync, CObject* pProjectileObject)
	{
		return ((bool(__cdecl*)(CEntity*, int, CMatrix*, CVector*, CVector*, CEntity*, bool, CObject*))(AddressSetter::Get(0x59DA30, 0x452A90)))(pEntProjOwner, ProjType, pMatrix, vecStart, vecEnd, pTargetEntity, noMPSync, pProjectileObject);
	}
};
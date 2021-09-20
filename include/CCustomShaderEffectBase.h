class CCustomShaderEffectBase
{
public:
	void Update(CEntity* attachedEntity)
	{
		((void(__thiscall*)(CCustomShaderEffectBase*, CEntity*))(*(void***)this)[3])(this, attachedEntity);
	}
};

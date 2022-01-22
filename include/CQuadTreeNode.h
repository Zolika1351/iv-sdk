class CQuadTreeNode
{
public:
	CRect               m_sRect;					// 00-10
	uint32_t*			m_pItemList;				// 10-14
	CQuadTreeNode*		m_pChildren[4];				// 14-24
	uint32_t			m_nLevel;					// 24-28

	CQuadTreeNode(CRect* rect, int levels)
	{
		((void(__thiscall*)(CQuadTreeNode*, CRect*, int))(AddressSetter::Get(0x4DE0F0, 0x76DEA0)))(this, rect, levels);
	}
	void ForAllMatching(CVector2D v, void(*callback)(CVector2D*, void*))
	{
		((void(__thiscall*)(CQuadTreeNode*, CVector2D, void(*)(CVector2D*, void*)))(AddressSetter::Get(0x4DE130, 0x76DEE0)))(this, v, callback);
	}
};
VALIDATE_SIZE(CQuadTreeNode, 0x28);
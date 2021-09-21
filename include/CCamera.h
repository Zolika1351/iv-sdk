class CCamera
{
public:
	static inline CCam*& m_pFinalCam = AddressSetter::GetRef<CCam*>(0xB21A70, 0xB488EC); // CCamFinal
};
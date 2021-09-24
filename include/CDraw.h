// this entire thing should be looked into a lot more, right now theres basically only rtti data here
class CViewportPrimaryOrtho;
class CViewportGame;
class CViewportRadar;
class CViewportMobilePhone;
namespace rage
{
	class ProceduralTextureRenderTargetDef;
	class grcRenderTargetPC;
	class grmShaderFx;
	class grcVertexBufferD3D
	{
		uint8_t pad[0x40];												// 00-40
	};
	VALIDATE_SIZE(grcVertexBufferD3D, 0x40);
	class SkyhatPerlinNoise
	{
	public:
		uint8_t pad[0x24];												// 00-24
		CSprite2d m_pSprite[2];											// 24-2C
		uint8_t pad2[0x4];												// 2C-30
	};
	VALIDATE_SIZE(SkyhatPerlinNoise, 0x30);
	VALIDATE_OFFSET(SkyhatPerlinNoise, m_pSprite, 0x24);
}

struct tGlobalScene
{
	CViewportPrimaryOrtho* m_pPrimaryViewport;						// 000-004
	CViewportGame* m_pGameViewport;									// 004-008
	CViewportRadar* m_pRadarViewport;								// 008-00C
	CViewportMobilePhone* m_pPhoneViewport;							// 00C-010
	uint8_t pad[0x70];												// 010-080
	rage::ProceduralTextureRenderTargetDef* m_pRenderTargetTexture;	// 080-084
	uint8_t pad2[0x7C];												// 084-100
	rage::grcRenderTargetPC* m_pRenderTarget;						// 100-104
	uint8_t pad3[0x7C];												// 104-180
	rage::grmShaderFx* m_pUnkShaderFx[2];							// 180-188
	uint8_t pad4[0x78];												// 188-200
	rage::SkyhatPerlinNoise m_sSkyhatNoise;							// 200-230
	uint8_t pad5[0x10];												// 230-240
	rage::grcVertexBufferD3D m_sVertexBuffer[2];					// 240-2C0
};
VALIDATE_OFFSET(tGlobalScene, m_pPrimaryViewport, 0x0);
VALIDATE_OFFSET(tGlobalScene, m_pGameViewport, 0x4);
VALIDATE_OFFSET(tGlobalScene, m_pRadarViewport, 0x8);
VALIDATE_OFFSET(tGlobalScene, m_pPhoneViewport, 0xC);
VALIDATE_OFFSET(tGlobalScene, m_pRenderTargetTexture, 0x80);
VALIDATE_OFFSET(tGlobalScene, m_pRenderTarget, 0x100);
VALIDATE_OFFSET(tGlobalScene, m_pUnkShaderFx, 0x180);
VALIDATE_OFFSET(tGlobalScene, m_sSkyhatNoise, 0x200);

// the order seems to be dynamic
struct tRenderPhases
{
	CRenderPhase* m_aRenderPhases[32];								// 000-??? array, of size m_nNumRenderPhases
};

class CDraw
{
public:
	tGlobalScene* m_pGlobalScene;									// 000-004
	uint8_t pad[0x34];												// 004-038
	tRenderPhases* m_pRenderPhases;									// 038-03C
	uint16_t m_nNumRenderPhases;									// 03C-03E
	uint8_t pad2[0x415];											// 03E-453
	uint8_t m_bForceHudWidescreen;									// 453-454 m_bWidescreenBorders?

	float CalculateAspectRatio(bool bUnk) // bUnk = 1 forces it to 1.777... if m_bForceHudWidescreen byte is non-zero
	{
		return ((float(__thiscall*)(CDraw*, bool))(AddressSetter::Get(0x3B4110, 0x49BA00)))(this, bUnk);
	}
};
VALIDATE_OFFSET(CDraw, m_pRenderPhases, 0x38);
VALIDATE_OFFSET(CDraw, m_bForceHudWidescreen, 0x453);

CDraw& Scene = AddressSetter::GetRef<CDraw>(0xCF47E0, 0xDF8280); // scene? renderer? rw to rage wrapper? some core rage rendering class? just called it CDraw, Scene & GlobalScene for now
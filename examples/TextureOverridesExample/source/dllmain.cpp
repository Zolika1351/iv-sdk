#include "../../../include/IVSDK.cpp"

LPDIRECT3DTEXTURE9 rainbowTex = nullptr;

// absolute worst case scenario here: returning the custom texture for every single call
// if you only want to replace specific textures, you're free to use SetTexture on the CSprite2d and then return that by default
CSprite2d __stdcall LoadRainbowTexture(char* sName)
{
	CSprite2d RainbowSprite;
	RainbowSprite.m_pTexture = new rage::grcTexturePC("test1");
	RainbowSprite.m_pTexture->m_pD3DTexture = rainbowTex;
	return RainbowSprite;
}

int RainbowStage;
float RainbowR;
float RainbowG;
float RainbowB;
void AdvanceRainbow()
{
	float delta = CTimer::ms_fTimeStep * 50;
	switch (RainbowStage)
	{
	case 0:
		if (RainbowB < 255) RainbowB += delta;
		else RainbowStage = 1;
		break;
	case 1:
		if (RainbowG > 0) RainbowG -= delta;
		else RainbowStage = 2;
		break;
	case 2:
		if (RainbowR < 255) RainbowR += delta;
		else RainbowStage = 3;
		break;
	case 3:
		if (RainbowB > 0) RainbowB -= delta;
		else RainbowStage = 4;
		break;
	case 4:
		if (RainbowG < 255) RainbowG += delta;
		else RainbowStage = 5;
		break;
	case 5:
		if (RainbowR > 0) RainbowR -= delta;
		else RainbowStage = 0;
		break;
	default:
		break;
	}
	if (RainbowR > 255) RainbowR = 255;
	if (RainbowG > 255) RainbowG = 255;
	if (RainbowB > 255) RainbowB = 255;
	if (RainbowR < 0) RainbowR = 0;
	if (RainbowG < 0) RainbowG = 0;
	if (RainbowB < 0) RainbowB = 0;
}

void CreateRainbowTexture()
{
	HANDLE handle;
	rage::g_pDirect3DDevice->CreateTexture(16, 16, 0, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &rainbowTex, &handle);
}

// every frame while in-game
void RainbowTexturesLoop()
{
	// all this is hilariously unstable but it's a proof of concept anyway
	AdvanceRainbow();
	if (auto tex = rainbowTex)
	{
		D3DLOCKED_RECT rect = { 0 };
		tex->LockRect(0, &rect, nullptr, 0);
		if (CRGBA* data = (CRGBA*)rect.pBits)
		{
			for (int i = 0; i < 16 * 16; i++)
			{
				data->red = RainbowR;
				data->green = RainbowG;
				data->blue = RainbowB;
				data->alpha = 255;
				data++;
			}
		}
		tex->UnlockRect(0);
		tex->GenerateMipSubLevels();
	}
}

// right after gta.dat loads, put any extra loading related things here
void InitRainbowStuff()
{
	if (!rainbowTex)
	{
		CreateRainbowTexture();
	}
}

// ran after the sdk initializes, add all your hooks/events/etc here
void plugin::gameStartupEvent()
{
	Overrides::GetTexture(LoadRainbowTexture);
	plugin::processScriptsEvent::Add(RainbowTexturesLoop);
	plugin::gameLoadEvent::Add(InitRainbowStuff);
}

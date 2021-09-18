#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)
#define VALIDATE_OFFSET(struc, member, offset) \
	static_assert(offsetof(struc, member) == offset, "The offset of " #member " in " #struc " is not " #offset "...")

namespace plugin
{
	enum eGameVersion
	{
		VERSION_NONE,
		VERSION_1070,
		VERSION_1080,
	};
	eGameVersion gameVer = VERSION_NONE;
	void processScriptsEvent();
	void gameStartupEvent();
	void gameLoadEvent();
}

#include "NewAddressSet.h"
#include "CRGBA.h"
#include "CKeyGen.h"
#include "CVector.h"
#include "CQuaternion.h"
#include "CMatrix.h"
#include "CPlayerInfo.h"
#include "CWorld.h"
#include "CPad.h"
#include "CEntity.h"
#include "CDynamicEntity.h"
#include "CPhysical.h"
#include "CObject.h"
#include "CPed.h"
#include "CRadar.h"
#include "CPool.h"
#include "CPools.h"
#include "CGarage.h"
#include "cHandlingDataMgr.h"
#include "CVehicle.h"
#include "CModelInfo.h"
#include "phInstGta.h"
#include "CTheScripts.h"
#include "phConstrainedCollider.h"
#include "CTimer.h"
#include "CStreaming.h"
#include "CFileLoader.h"
#include "CdStream.h"
#include "CGame.h"
#include "CCam.h"
#include "CExplosion.h"
#include "CHudColours.h"
#include "CVisibilityPlugins.h"
#include "CNetwork.h"
#include "CShadows.h"
#include "CWeaponInfo.h"
#include "CClock.h"
#include "CCutsceneMgr.h"
#include "CRenderPhase.h"
#include "CDraw.h"
#include "grcTexture.h"
#include "pgDictionary.h"
#include "CTxdStore.h"

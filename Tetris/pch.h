#pragma once

#ifndef __PCH__
#define __PCH__

#include <vector>
#include <string>

#include "resource.h"
#include "framework.h"

#include "Vector2.h"

enum class BRUSH_TYPE
{
	HOLLOW,
	END
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END
};

enum class GROUP_TYPE
{
	PLAYER,
	MONSTER,
	END
};

enum class SCENE_TYPE
{
	INTRO,
	MAIN_MENU,
	STAGE,
	END
};

#endif // !__PCH__

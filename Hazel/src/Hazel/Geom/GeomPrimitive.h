#pragma once
#include "GeomBuffer.h"
#include "Hazel/Common/Types.h"

namespace Hazel {

	namespace GeomPrimitive
	{
		GeomBuffer CreateBox(FVF fvf, float width, float height, float depth, uint numSubdivisions);
	};

}

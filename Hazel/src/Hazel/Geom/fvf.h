#pragma once

#include "Hazel/Common/Types.h"

namespace Hazel {

	using FVF = uint64;

	const FVF FVF_UNKNOWN = -1;
	const FVF FVF_POS = 1 << 0;
	const FVF FVF_NORMAL = FVF_POS << 1;
	const FVF FVF_UV = FVF_NORMAL << 1;
	const FVF FVF_COLOR = FVF_UV << 1;
	const FVF FVF_LAST = FVF_COLOR << 1;

	uint fvfGetStride(FVF fvf);
	uint fvfGetOffset(FVF fvf, FVF type);

}

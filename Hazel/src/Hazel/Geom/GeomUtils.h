#pragma once

#include "GeomBuffer.h"
#include "Hazel/Renderer/Buffer.h"
#include "Hazel/Renderer/VertexArray.h"

namespace Hazel {

	namespace GeomUtils
	{
		Ref<VertexArray> GeomCreateVertexArray(GeomBuffer& geomBuffer);
		Ref<VertexBuffer> GeomCreateVertexBuffer(GeomBuffer& geomBuffer);
		Ref<IndexBuffer> GeomCreateIndexBuffer(GeomBuffer& geomBuffer);
	};

}

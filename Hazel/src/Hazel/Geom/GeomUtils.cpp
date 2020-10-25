#include "hzpch.h"
#include "GeomUtils.h"

namespace Hazel {
	Ref<VertexArray> GeomUtils::GeomCreateVertexArray(GeomBuffer& geomBuffer)
	{
		auto va = VertexArray::Create();
		va->SetIndexBuffer(GeomCreateIndexBuffer(geomBuffer));
		va->AddVertexBuffer(GeomCreateVertexBuffer(geomBuffer));
		return va;
	}

	Ref<VertexBuffer> GeomUtils::GeomCreateVertexBuffer(GeomBuffer& geomBuffer)
	{
		Ref<VertexBuffer> ret = VertexBuffer::Create((float*)geomBuffer.data.data(), geomBuffer.data.size());
		HZ_CORE_ASSERT(geomBuffer.fvf ^ FVF_POS == 0);
		ret->SetLayout({
			{ ShaderDataType::Float3, "a_Position" },
			});
		return ret;
	}

	Ref<IndexBuffer> GeomUtils::GeomCreateIndexBuffer(GeomBuffer& geomBuffer)
	{
		Ref<IndexBuffer> ret = IndexBuffer::Create((uint*)geomBuffer.faces.data(), geomBuffer.faces.size() * 3);
		return ret;
	}

}

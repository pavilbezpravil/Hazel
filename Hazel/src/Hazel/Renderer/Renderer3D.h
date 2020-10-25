#pragma once

#include "Hazel/Renderer/Camera.h"
#include "Hazel/Math/Types.h"
#include "VertexArray.h"

namespace Hazel {

	struct Mesh
	{
		Ref<VertexArray> vertexArray;
	};
	
	class Renderer3D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const Camera& camera, const glm::mat4& transform);
		static void EndScene();
		static void Flush();

		// Primitives
		static void DrawMesh(const Ref<Mesh>& mesh, const Mat4& transform, const glm::vec4& color);
		
		// Stats
		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t MeshCount = 0;
			uint32_t VertexCount = 0;
			uint32_t IndexCount = 0;
		};
		static void ResetStats();
		static Statistics GetStats();
	};

}

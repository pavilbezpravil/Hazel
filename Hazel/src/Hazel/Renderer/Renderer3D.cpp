#include "hzpch.h"

#include "Hazel/Renderer/Renderer3D.h"

#include "Hazel/Renderer/VertexArray.h"
#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/RenderCommand.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Hazel {

	struct QuadVertex
	{
		glm::vec3 Position;
		glm::vec4 Color;
	};

	struct Renderer3DData
	{
		Ref<Shader> TextureShader;

		Renderer3D::Statistics Stats;
	};

	static Renderer3DData s_Data;

	void Renderer3D::Init()
	{
		HZ_PROFILE_FUNCTION();

		s_Data.TextureShader = Shader::Create("assets/shaders/base3d.glsl");
		s_Data.TextureShader->Bind();
		s_Data.TextureShader->SetFloat4("u_Color", Vec4(1, 0, 0, 1));
	}

	void Renderer3D::Shutdown()
	{
		HZ_PROFILE_FUNCTION();
	}

	void Renderer3D::BeginScene(const Camera& camera, const glm::mat4& transform)
	{
		HZ_PROFILE_FUNCTION();

		glm::mat4 viewProj = camera.GetProjection() * glm::inverse(transform);

		s_Data.TextureShader->Bind();
		s_Data.TextureShader->SetMat4("u_ViewProjection", viewProj);
	}

	void Renderer3D::EndScene()
	{
		HZ_PROFILE_FUNCTION();

		s_Data.TextureShader->Unbind();

		Flush();
	}

	void Renderer3D::Flush()
	{
	}

	void Renderer3D::DrawMesh(const Ref<Mesh>& mesh, const Mat4& transform, const glm::vec4& color)
	{
		s_Data.TextureShader->SetFloat4("u_Color", color);
		s_Data.TextureShader->SetMat4("u_Transform", transform);

		mesh->vertexArray->Bind();
		RenderCommand::DrawIndexed(mesh->vertexArray);

		s_Data.Stats.DrawCalls++;
	}

	void Renderer3D::ResetStats()
	{
		memset(&s_Data.Stats, 0, sizeof(Statistics));
	}

	Renderer3D::Statistics Renderer3D::GetStats()
	{
		return s_Data.Stats;
	}

}

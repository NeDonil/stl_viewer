#pragma once

#include <Core\Core.h>
#include <Core\Layer.h>
#include <Graphics\Framebuffer.h>
#include <Graphics\VertexArray.h>
#include <Graphics\Buffer.h>
#include <Graphics\Shader.h>

#include <glm\glm.hpp>

namespace Viewer
{
	struct Vertex
	{
		glm::vec3 Position;
	};

	class MainLayer : public Layer
	{
	public:
		MainLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		virtual void OnUpdate(Timestep ts) override;

		~MainLayer();
	private:
		Ref<Framebuffer> m_Framebuffer;

		Ref<VertexArray> va;
		Ref<VertexBuffer> vb;
		Ref<IndexBuffer> ib;

		Ref<Shader> m_TextureShader;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
	};
}

#pragma once

#include <Core\Core.h>
#include <Core\Layer.h>
#include <Graphics\Framebuffer.h>

#include <glm\glm.hpp>

namespace Viewer
{
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
		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
	};
}

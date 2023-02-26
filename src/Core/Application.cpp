#include "glfw/glfw3.h"
#include <Glad/glad.h>

#include "Application.h"
#include "Core/Log.h"
#include "Graphics/RenderCommand.h"
#include "Core/Timestep.h"

namespace Viewer
{

	Application* Application::s_Instance = nullptr;

	Application::Application(const char* name)
	{
		if(s_Instance)
			CORE_ERROR("Applicaiton is already exists");
		s_Instance = this;

		m_Window = Window::Create(WindowProps(name));

		//m_ImGuiLayer = new ImGuiLayer();
		//PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}


	void Application::Close()
	{
		m_Running = false;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timestep);

				//m_ImGuiLayer->Begin();
				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
				//m_ImGuiLayer->End();
			}
			m_Window->OnUpdate();

		}
	}

}
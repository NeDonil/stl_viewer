#pragma once

#include <Core/Core.h>
#include <Core/LayerStack.h>
#include <Core/Timestep.h>
#include <Graphics/Window.h>

namespace Viewer
{
	class Application
	{
	public:
		Application(const char* name = "Unknow Application");
		virtual ~Application();

		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		void Close();

		inline static Application& Get() { return *s_Instance; }
	private:
		Scope<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
#pragma once

#include <string>
#include <Core\Core.h>
#include <Graphics\GraphicsContext.h>

struct GLFWwindow;

namespace Viewer
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "STL Viewer",
			unsigned int width = 1280,
			unsigned int height = 720) :
			Title(title), Width(width), Height(height)
		{
		}
	};

	class Window
	{
	public:
		Window(const WindowProps& props);

		void OnUpdate();

		unsigned int GetWidth() const { return m_Data.Width; }
		unsigned int GetHeight() const { return m_Data.Height; }

		void SetVSync(bool enabled);
		bool IsVSync() const ;

		void* GetNativeWindow() const { return m_Window; };

		static Scope<Window> Create(const WindowProps& props = WindowProps());

		~Window();
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		Scope<GraphicsContext> m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

		};

		WindowData m_Data;
	};
}
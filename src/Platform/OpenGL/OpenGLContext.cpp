#include "OpenGLContext.h"

#include <glfw/glfw3.h>
#include <Glad/glad.h>

#include <Core\Log.h>

namespace Viewer
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) :
		m_WindowHandle(windowHandle)
	{
		if (!windowHandle)
		{
			CORE_ERROR("Handle is null!"); __debugbreak;
		}
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if (!status)
		{
			CORE_ERROR("Failed to initialize Glad!"); __debugbreak;
		}

		//CORE_INFO("OpenGL Renderer: {0}", glGetString(GL_VENDOR));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
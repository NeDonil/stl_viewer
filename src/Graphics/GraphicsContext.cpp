#include "GraphicsContext.h"

#include <Graphics/RendererAPI.h>
#include <Platform/OpenGL/OpenGLContext.h>
#include <Core\Log.h>

namespace Viewer
{
	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CORE_ERROR("RendererAPI::None is not supported"); __debugbreak; return nullptr;
		case RendererAPI::API::OpenGL: return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		CORE_ERROR("Unknow RendererAPI!"); __debugbreak;
		return nullptr;
	}
}
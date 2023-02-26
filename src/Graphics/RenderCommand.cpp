#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Viewer
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
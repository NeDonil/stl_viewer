#include <Graphics/VertexArray.h>
#include <Graphics/RendererAPI.h>
#include <Platform/OpenGL/OpenGLVertexArray.h>

namespace Viewer
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CORE_CRITICAL("RendererApi::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexArray>();
		}
		CORE_CRITICAL("Unknown RendereAPI!");
		return nullptr;
	}
}
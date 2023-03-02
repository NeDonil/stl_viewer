#include <Graphics/RendererAPI.h>
#include <Platform/OpenGL/OpenGLFramebuffer.h>

namespace Viewer
{
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CORE_CRITICAL("RendererAPI:None is not supported now"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLFramebuffer>(spec);
		}

		CORE_CRITICAL("Unknown RendereAPI!");
		return nullptr;
	}
}
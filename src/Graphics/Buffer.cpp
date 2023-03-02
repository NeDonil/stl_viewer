#include "Buffer.h"
#include "RendererAPI.h"
#include <Platform/OpenGL/OpenGLBuffer.h>

namespace Viewer
{
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CORE_CRITICAL("RendererAPI:None is not supported now"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexBuffer>(vertices, size);
		}

		CORE_CRITICAL("Unknown RendereAPI!");
		return nullptr;
	}

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CORE_CRITICAL("RendererAPI:None is not supported now"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexBuffer>(size);
		}

		CORE_CRITICAL("Unknown RendereAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CORE_CRITICAL("RendererAPI:None is not supported now"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLIndexBuffer>(indices, count);
		}

		CORE_CRITICAL("Unknown RendereAPI!");
		return nullptr;
	}

}
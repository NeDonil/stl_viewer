#include "Shader.h"
#include "RendererAPI.h"
#include <Platform/OpenGL/OpenGLShader.h>

namespace Viewer
{
	Ref<Shader> Shader::Create(const std::string& filepath)
	{
		switch (RendererAPI::GetAPI())
		{

		case RendererAPI::API::None: CORE_CRITICAL("Engine is not supported None API");
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(filepath);
		}

		CORE_CRITICAL("Unknown RendererAPI");
		return nullptr;
	}

	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CORE_CRITICAL("Engine is not supported None API");
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(name, vertexSrc, fragmentSrc);
		}

		CORE_CRITICAL("Unknown RendererAPI");
		return nullptr;
	}

}
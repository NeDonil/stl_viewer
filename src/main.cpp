#include <iostream>

#include <Core\Log.h>
#include <Graphics\Window.h>
#include <Graphics\GraphicsContext.h>
#include <Graphics\RenderCommand.h>

#include <glm\glm.hpp>

int main()
{
	using namespace Viewer;

	Log::Init();

	
	auto window = Window::Create();
	auto context = GraphicsContext::Create(window->GetNativeWindow());

	RenderCommand::SetClearColor({ 0.4f, 0.8f, 0.2f, 1.0f });
	while (true)
	{
		RenderCommand::Clear();
		window->OnUpdate();
	}

	system("pause");
	return 0;
}
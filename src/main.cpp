#include <iostream>

#include <Core/Log.h>
#include <Core/Application.h>

#include <glm\glm.hpp>

extern Viewer::Application* Viewer::CreateApplication();

int main()
{
	Viewer::Log::Init();

	auto app = Viewer::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
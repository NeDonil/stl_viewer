#include <iostream>

#include <Core\Log.h>
#include <Graphics\Window.h>

int main()
{
	using namespace Viewer;

	Log::Init();

	
	auto window = Window::Create();

	while (true)
	{
		window->OnUpdate();
	}

	system("pause");
	return 0;
}
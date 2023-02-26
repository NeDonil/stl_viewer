#include <Core\Application.h>
#include <Core\Layer.h>

#include "MainLayer.h"

class ViewerApplication : public Viewer::Application
{
public:
	ViewerApplication()
		: Application("STL Viewer")
	{
		PushLayer(new MainLayer());
	}

	~ViewerApplication()
	{

	}

};

Viewer::Application* Viewer::CreateApplication()
{
	return new ViewerApplication();
}


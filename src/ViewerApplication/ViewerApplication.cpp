#include <Core\Application.h>
#include <Core\Layer.h>

#include "MainLayer.h"

namespace Viewer
{

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

	Application* CreateApplication()
	{
		return new ViewerApplication();
	}

}


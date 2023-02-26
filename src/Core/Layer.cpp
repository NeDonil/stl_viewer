#pragma once

#include "Layer.h"

namespace Viewer
{
	Layer::Layer(const std::string& debugName) :
		m_DebugName(debugName)
	{
	}

	Layer::~Layer()
	{
	}
}
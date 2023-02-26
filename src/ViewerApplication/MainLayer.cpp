#pragma once

#include "MainLayer.h"
#include <Core\Timestep.h>
#include <Graphics\RenderCommand.h>

MainLayer::MainLayer()
{

}

void MainLayer::OnAttach()
{
	Viewer::RenderCommand::SetClearColor({ 0.8f, 0.6f, 0.2f, 1.0f });
}

void MainLayer::OnDetach()
{

}

void MainLayer::OnUpdate(Viewer::Timestep ts)
{
	Viewer::RenderCommand::Clear();
}

MainLayer::~MainLayer()
{

}
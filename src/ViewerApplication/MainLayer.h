#pragma once

#include <Core\Layer.h>

class MainLayer : public Viewer::Layer
{
public:
	MainLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnImGuiRender() override;
	virtual void OnUpdate(Viewer::Timestep ts) override;

	~MainLayer();
private:
};

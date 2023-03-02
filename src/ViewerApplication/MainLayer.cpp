#pragma once

#include "MainLayer.h"
#include <Core\Timestep.h>
#include <Graphics\RenderCommand.h>
#include <Core\Log.h>
#include <Core\Application.h>

#include <imgui.h>

namespace Viewer
{
	MainLayer::MainLayer()
	{

	}

	void MainLayer::OnAttach()
	{
		Viewer::RenderCommand::SetClearColor({ 0.8f, 0.6f, 0.2f, 1.0f });

		FramebufferSpecification fbSpec;

		fbSpec.Width = 1280;
		fbSpec.Height = 720;

		m_Framebuffer = Framebuffer::Create(fbSpec);

		m_TextureShader = Shader::Create("assets/shaders/Texture.glsl");
		m_TextureShader->Bind();

		va = VertexArray::Create();

		vb = VertexBuffer::Create(3 * sizeof(Vertex));
		vb->SetLayout({
			{ShaderDataType::Float3, "Position"}
			});

		Vertex vertices[3];

		vertices[0].Position = { -0.5f, -0.5f, 0.5f };
		vertices[1].Position = {  0.0f,  0.5f, 0.5f };
		vertices[2].Position = {  0.5f, -0.5f, 0.5f };

		vb->SetData(vertices, sizeof(vertices));

		va->AddVertexBuffer(vb);

		uint32_t triangleIndices[] = { 0, 1, 2 };

		ib = IndexBuffer::Create(triangleIndices, 3);
		va->SetIndexBuffer(ib);
	}

	void MainLayer::OnDetach()
	{

	}

	void MainLayer::OnImGuiRender()
	{
		static bool dockspaceOpen = true;
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}

		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

		ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
		ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				using namespace Viewer;
				if (ImGui::MenuItem("New", "Ctrl+N"))
					CORE_INFO("NEW FILE");

				if (ImGui::MenuItem("Open...", "Ctrl+O"))
					CORE_INFO("OPEN SCENE");

				if (ImGui::MenuItem("Save As...", "Ctrl+Shift+S"))
					CORE_INFO("SAVE SCENE AS");

				if (ImGui::MenuItem("Exit"))
					Application::Get().Close();

				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0.0f, 0.0f });

		ImGui::Begin("Viewport");

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		m_ViewportSize = { viewportPanelSize.x, viewportPanelSize.y };

		uint32_t textureID = m_Framebuffer->GetColorAttachmentRendererID();
		ImGui::Image((void*)textureID, ImVec2{ viewportPanelSize.x, viewportPanelSize.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });

		ImGui::End();

		ImGui::PopStyleVar();


		ImGui::End();
	}

	void MainLayer::OnUpdate(Viewer::Timestep ts)
	{
		if (FramebufferSpecification spec = m_Framebuffer->GetSpecification();
			m_ViewportSize.x > 0.0f && m_ViewportSize.y > 0.0f &&
			(spec.Width != m_ViewportSize.x || spec.Height != m_ViewportSize.y))
		{
			//Resize stuff
			m_Framebuffer->Resize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
		}

		m_Framebuffer->Bind();
		Viewer::RenderCommand::Clear();

		RenderCommand::DrawIndexed(va, 3);

		m_Framebuffer->Unbind();
	}


	MainLayer::~MainLayer()
	{

	}
}
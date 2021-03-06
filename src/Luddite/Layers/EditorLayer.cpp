#include "Luddite/Layers/EditorLayer.hpp"
#include "Luddite/Core/Profiler.hpp"
#include "Luddite/ECS/Modules/Graphics.hpp"
#include "Luddite/ECS/Modules/Physics.hpp"
#include "Luddite/ECS/Modules/Input.hpp"
#include "Luddite/ECS/Modules/Models.hpp"
#include "Luddite/ECS/Modules/Box2D.hpp"
#include "Luddite/ECS/Modules/Editor.hpp"
#include "Luddite/Layers/Editor/ViewportPanel.hpp"
#include "Luddite/Layers/Editor/HeirarchyPanel.hpp"
#include "Luddite/Layers/Editor/ComponentsPanel.hpp"
#include "Luddite/Utilities/ImportModelECS.hpp"
#include "imgui.h"

namespace Luddite
{
void EditorLayer::Initialize()
{
        m_World.import<Luddite::Systems>();
        m_World.import<Input::Systems>();
        m_World.import<Transform3D::Systems>();
        m_World.import<Models::Systems>();
        m_World.import<Graphics::Systems>();
        m_World.import<Box2D::Systems>();
        m_World.import<Editor::Components>();

        m_Ctx.world = &m_World;
        AddPanel<ViewportPanel>();
        AddPanel<HeirarchyPanel>();
        AddPanel<ComponentsPanel>();

        //for (int i = 0; i < 80; i++)
        {
                auto e = Luddite::Utils::ImportModelECS(Luddite::Assets::GetBasicModelLibrary().GetAssetSynchronous(14036193367729790258ULL), m_World, m_World.id<Luddite::Scene>().entity(), true)
                         .set<Transform3D::Rotation>({{glm::radians(180.), 0, 0}})
                         .set<Transform3D::Translation>({{0., 0., 0.}})
                         //.set<Transform3D::LocalRotation>({{glm::radians(90.), 0, glm::radians(180.)}})
                         //.set<Transform3D::LocalRotation>({{0, 0, glm::radians(180.)}})
                ;
                e.get_mut<Models::AnimationStack>()->PlayAnimation(0, -1);
        }
        {
                auto target = m_World.entity("Camera Target").child_of(m_World.id<Luddite::Scene>().entity())
                              .set<Transform3D::Translation>({})
                              .set<Transform3D::Rotation>({})
                              .set<Transform3D::Scale>({})
                              .add<Editor::CameraParent>();
                ;
                auto e = m_World.entity("Camera").child_of(target);
                //auto e = m_World.entity("Camera").child_of(m_World.id<Luddite::Scene>().entity());
                //e.set<Transform3D::Translation>({glm::vec3(0, 20, -10)});
                //e.set<Transform3D::Rotation>({glm::vec3(glm::radians(53.f), glm::radians(45.f), 0)});
                e.set<Transform3D::Translation>({});
                e.set<Transform3D::Rotation>({});
                e.set<Transform3D::LocalTranslation>({{0., -1., 0.}});
                e.set<Transform3D::LocalRotation>({});
                e.add<Graphics::Camera>();
                e.add<Graphics::RenderTarget>();
                e.add<Graphics::RenderToMainWindow>();
        }
        {
                auto e = m_World.entity("Cube").child_of(m_World.id<Luddite::Scene>().entity());
                e.add<Transform3D::Translation>();
                e.add<Transform3D::Rotation>();
                e.add<Transform3D::Scale>();
                e.set<Physics::LinearVelocity>({glm::vec3(1.00, 0, 0)});
                e.set<Physics::LinearDamping>({glm::vec3(0.50, 0, 0)});
                e.set<Models::Model>({Luddite::Assets::GetBasicModelLibrary().GetAsset(4049191577729022337ULL)});
        }
        for (int i = 0; i < 250; i++)
        {
                auto e = m_World.entity("Light").child_of(m_World.id<Luddite::Scene>().entity());
                //e.add<Transform3D::TransformMatrix>();
                e.add<Transform3D::Translation>();
                e.add<Graphics::PointLight>();
        }
}

void EditorLayer::HandleEvents()
{
        for (auto& panel : m_Panels)
                panel->HandleEvents(m_Ctx);
}
void EditorLayer::Update(double delta_time)
{
        ecs_set_pipeline(m_World, m_World.id<Luddite::UpdatePipeline>());
        m_World.progress(delta_time);
        for (auto& panel : m_Panels)
                panel->Update(m_Ctx);
}
void EditorLayer::FixedUpdate(double delta_time)
{
        ecs_set_pipeline(m_World, m_World.id<Luddite::SimulationPipeline>());
        m_World.progress(delta_time);
        for (auto& panel : m_Panels)
                panel->FixedUpdate(m_Ctx);
}
void EditorLayer::Render(double alpha, RenderTarget render_target)
{
        for (auto& panel : m_Panels)
                panel->OnRender(m_Ctx);
}
void EditorLayer::RenderImGui(double alpha, RenderTarget render_target)
{
        RenderDockSpace();
        for (auto& panel : m_Panels)
                panel->OnDraw(m_Ctx);
        ImGui::ShowDemoWindow();
}

void EditorLayer::RenderDockSpace()
{
        LD_PROFILE_FUNCTION();
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.f, 0.f));
        constexpr ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar
                                                  | ImGuiWindowFlags_NoDocking
                                                  | ImGuiWindowFlags_NoTitleBar
                                                  | ImGuiWindowFlags_NoCollapse
                                                  | ImGuiWindowFlags_NoResize
                                                  | ImGuiWindowFlags_NoMove
                                                  | ImGuiWindowFlags_NoBringToFrontOnFocus
                                                  | ImGuiWindowFlags_NoNavFocus
                                                  //| ImGuiWindowFlags_NoNavInputs
        ;
        ImGui::Begin("Dockspace", nullptr, window_flags);
        ImGui::PopStyleVar(3);

        constexpr ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode;
        ImGuiID dockspace_id = ImGui::GetID("Dockspace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.f, 0.f), dockspace_flags);

        //Render the Menubar
        if (ImGui::BeginMenuBar())
        {
                if (ImGui::BeginMenu("View"))
                {
                        for (auto& panel : m_Panels)
                                ImGui::MenuItem(panel->GetName(), NULL, &panel->open);
                        ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
        }

        ImGui::End();
}
void EditorLayer::AttachToLayer(std::shared_ptr<Layer> layer)
{
        LD_LOG_INFO("Editor Layer has attached to {}", (void*)layer.get());
        m_pAttachedLayer = layer;
        m_Ctx.world = &layer->GetWorld();
}
void EditorLayer::DetachLayer()
{
        m_pAttachedLayer = nullptr;
}
}

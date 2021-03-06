#include "Luddite/Platform/Window/Window.hpp"
#include "ThirdParty/lpng-1.6.17/contrib/tools/sRGB.h"

namespace Luddite
{
Window::Window()
{
}
Window::~Window() {}
void Window::OnWindowResize(int width, int height)
{
        m_WindowWidth = width;
        m_WindowHeight = height;
        Renderer::OnWindowResize(width, height);
        m_pSwapChain->Resize(width, height);
}

void Window::SwapBuffers()
{
        m_pSwapChain->Present(m_Vsync ? 1 : 0);
}

void Window::HandleEvents()
{
        {
        }
        unsigned int new_width = 0;
        unsigned int new_height = 0;
        for (auto& event : Events::GetList<WindowSizeEvent>())
        {
                new_width = event.width;
                new_height = event.height;
                event.SetHandled();
        }
        if (new_width != 0 && new_height != 0)
        {
                OnWindowResize(new_width, new_height);
        }
}

void Window::ImGuiSetup()
{
        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = "imgui.ini";
        //io.FontDefault = io.Fonts->AddFontFromFileTTF("Assets/Fonts/NunitoSans/NunitoSans-Regular.ttf", 16.0f); //[0]
        io.FontDefault = io.Fonts->AddFontFromFileTTF("Assets/Fonts/NunitoSans/NunitoSans-Bold.ttf", 16.0f); //[0]
        //io.Fonts->AddFontFromFileTTF("Assets/Fonts/NunitoSans/NunitoSans-Bold.ttf", 16.0f); //[1]
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        ImGuiSetDefaultColors();
        auto& style = ImGui::GetStyle();
        style.FrameRounding = 7;
        style.WindowRounding = 4;
        style.IndentSpacing = 8;
        style.ScrollbarSize = 11;
}

void Window::ImGuiSetDefaultColors()
{
        auto* colors = ImGui::GetStyle().Colors;
        // colors[ImGuiCol_WindowBg] = ImVec4{0.05f, 0.075f, 0.1f, 1.0f};
        // colors[ImGuiCol_WindowBg] = ImVec4{ 0.01f, 0.01f, 0.02f, 1.0f};
        #define IMCOLOR(r, g, b, a) ImVec4{static_cast<float>(linear_from_sRGB(r)), static_cast<float>(linear_from_sRGB(g)), static_cast<float>(linear_from_sRGB(b)), a \
}
        //auto ImColDark = IMCOLOR(0.11f, 0.10f, 0.16f, 1.0f);
        //auto ImColBase = IMCOLOR(0.16f, 0.15f, 0.25f, 1.0f);
        //auto ImColHovered = IMCOLOR(0.2f, 0.18f, 0.33f, 1.0f);
        //auto ImColActive = IMCOLOR(0.2f, 0.2f, 0.38f, 1.0f);
        //auto ImColBright = IMCOLOR(0.55f, 0.55f, 0.95f, 1.0f);
        //auto ImColHighlighted = IMCOLOR(0.95f, 0.1f, 0.35f, 0.5f);

        //colors[ImGuiCol_WindowBg] = ImColDark;

        //colors[ImGuiCol_TitleBg] = ImColBase;
        //colors[ImGuiCol_TitleBgActive] = ImColActive;
        //colors[ImGuiCol_TitleBgCollapsed] = ImColHovered;

        //colors[ImGuiCol_Tab] = ImColActive;
        //colors[ImGuiCol_TabHovered] = ImColHovered;
        //colors[ImGuiCol_TabActive] = ImColDark;
        //colors[ImGuiCol_TabUnfocused] = ImColBase;
        //colors[ImGuiCol_TabUnfocusedActive] = ImColDark;

        //colors[ImGuiCol_MenuBarBg] = ImColDark;

        //colors[ImGuiCol_Separator] = ImColBase;
        //colors[ImGuiCol_SeparatorHovered] = ImColActive;
        //colors[ImGuiCol_SeparatorActive] = ImColBright;

        //colors[ImGuiCol_DockingPreview] = ImColBright;

        //colors[ImGuiCol_PopupBg] = ImColBase;

        //colors[ImGuiCol_Button] = ImColBase;
        //colors[ImGuiCol_ButtonHovered] = ImColHovered;
        //colors[ImGuiCol_ButtonActive] = ImColActive;

        //colors[ImGuiCol_FrameBg] = ImColBase;
        //colors[ImGuiCol_FrameBgHovered] = ImColHovered;
        //colors[ImGuiCol_FrameBgActive] = ImColActive;

        //colors[ImGuiCol_Header] = ImColBase;
        //colors[ImGuiCol_HeaderHovered] = ImColHovered;
        //colors[ImGuiCol_HeaderActive] = ImColActive;

        //// colors[ImGuiCol_Text]
        //colors[ImGuiCol_TextSelectedBg] = ImColHighlighted;

        //// colors[ImGuiCol_WindowBg] = (ImVec4)ImColor(0xff291b1b);
        //// colors[ImGuiCol_WindowBg] *= 0.6347364189f;
        /* FIND AND REPLACE:
         * 1.00f, 1.00f, 1.00f    0.81f, 0.88f, 1.00f
         * 0.50f, 0.50f, 0.50f    0.50f, 0.50f, 0.50f
         * 0.06f, 0.06f, 0.06f    0.01f, 0.01f, 0.01f
         * 0.00f, 0.00f, 0.00f    0.00f, 0.00f, 0.00f
         * 0.08f, 0.08f, 0.08f    0.04f, 0.04f, 0.04f
         * 0.43f, 0.43f, 0.50f    0.05f, 0.05f, 0.05f
         * 0.16f, 0.29f, 0.48f    0.16f, 0.48f, 0.26f
         * 0.26f, 0.59f, 0.98f    0.26f, 0.98f, 0.50f
         * 0.04f, 0.04f, 0.04f    0.00f, 0.00f, 0.00f
         * 0.14f, 0.14f, 0.14f    0.02f, 0.02f, 0.02f
         * 0.02f, 0.02f, 0.02f    0.00f, 0.00f, 0.00f
         * 0.31f, 0.31f, 0.31f    0.01f, 0.01f, 0.01f
         * 0.41f, 0.41f, 0.41f    0.005f, 0.005f, 0.005f
         * 0.51f, 0.51f, 0.51f    0.00f, 0.00f, 0.00f
         * 0.24f, 0.52f, 0.88f    0.24f, 0.87f, 0.54f
         * 0.06f, 0.53f, 0.98f    0.06f, 0.98f, 0.50f
         * 0.18f, 0.35f, 0.58f    0.18f, 0.58f, 0.40f
         * 0.20f, 0.41f, 0.68f    0.20f, 0.68f, 0.41f
         * 0.07f, 0.10f, 0.15f    0.07f, 0.15f, 0.12f
         * 0.14f, 0.26f, 0.42f    0.14f, 0.42f, 0.28f
         * 0.20f, 0.20f, 0.20f    0.04f, 0.04f, 0.04f
         */
        colors[ImGuiCol_Text] = ImVec4(0.81f, 0.88f, 1.00f, 1.00f);
        colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
        colors[ImGuiCol_WindowBg] = ImVec4(0.01f, 0.01f, 0.01f, 0.94f);
        colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_PopupBg] = ImVec4(0.04f, 0.04f, 0.04f, 0.94f);
        colors[ImGuiCol_Border] = ImVec4(0.05f, 0.05f, 0.05f, 0.50f);
        colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.48f, 0.26f, 0.54f);
        colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.98f, 0.50f, 0.40f);
        colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.98f, 0.50f, 0.67f);
        colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
        colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.48f, 0.26f, 1.00f);
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
        colors[ImGuiCol_MenuBarBg] = ImVec4(0.02f, 0.02f, 0.02f, 1.00f);
        colors[ImGuiCol_ScrollbarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.53f);
        colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.01f, 0.01f, 0.01f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.005f, 0.005f, 0.005f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
        colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.98f, 0.50f, 1.00f);
        colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.87f, 0.54f, 1.00f);
        colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.98f, 0.50f, 1.00f);
        colors[ImGuiCol_Button] = ImVec4(0.26f, 0.98f, 0.50f, 0.40f);
        colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.98f, 0.50f, 1.00f);
        colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.98f, 0.50f, 1.00f);
        colors[ImGuiCol_Header] = ImVec4(0.26f, 0.98f, 0.50f, 0.31f);
        colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.98f, 0.50f, 0.80f);
        colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.98f, 0.50f, 1.00f);
        colors[ImGuiCol_Separator] = ImVec4(0.05f, 0.05f, 0.05f, 0.50f);
        colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
        colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
        colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.98f, 0.50f, 0.20f);
        colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.98f, 0.50f, 0.67f);
        colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.98f, 0.50f, 0.95f);
        colors[ImGuiCol_Tab] = ImVec4(0.18f, 0.58f, 0.40f, 0.86f);
        colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.98f, 0.50f, 0.80f);
        colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.68f, 0.41f, 1.00f);
        colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.15f, 0.12f, 0.97f);
        colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.42f, 0.28f, 1.00f);
        colors[ImGuiCol_DockingPreview] = ImVec4(0.26f, 0.98f, 0.50f, 0.70f);
        colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
        colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
        colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
        colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
        colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
        colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
        colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
        colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.98f, 0.50f, 0.35f);
        colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
        colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.98f, 0.50f, 1.00f);
        colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
        colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
        colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

ImGuiContext* Window::GetImGuiContext()
{
        return ImGui::GetCurrentContext();
};

glm::mat4x4 Window::GetAdjustedProjectionMatrix(float FOV, float NearPlane, float FarPlane) const
{
        const auto& SCDesc = m_pSwapChain->GetDesc();

        float AspectRatio = static_cast<float>(SCDesc.Width) / static_cast<float>(SCDesc.Height);
        float XScale, YScale;
        if (SCDesc.PreTransform == Diligent::SURFACE_TRANSFORM_ROTATE_90 ||
            SCDesc.PreTransform == Diligent::SURFACE_TRANSFORM_ROTATE_270 ||
            SCDesc.PreTransform == Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90 ||
            SCDesc.PreTransform == Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270)
        {
                // When the screen is rotated, vertical FOV becomes horizontal FOV
                XScale = 1.f / std::tan(FOV / 2.f);
                // Aspect ratio is inversed
                YScale = XScale * AspectRatio;
        }
        else
        {
                YScale = 1.f / std::tan(FOV / 2.f);
                XScale = YScale / AspectRatio;
        }


        // Diligent::float4x4 Proj;
        // Proj[1][1] = XScale;
        // Proj[2][2] = YScale;
        // Proj.SetNearFarClipPlanes(NearPlane, FarPlane, false);//m_pDevice->GetDeviceCaps().IsGLDevice());
        glm::mat4x4 Proj = glm::perspective(FOV, YScale / XScale, NearPlane, FarPlane);
        return Proj;
}

glm::mat4x4 Window::GetSurfacePretransformMatrix(const glm::vec3& f3CameraViewAxis) const
{
        const auto& SCDesc = m_pSwapChain->GetDesc();
        switch (SCDesc.PreTransform)
        {
        case Diligent::SURFACE_TRANSFORM_ROTATE_90:
                // The image content is rotated 90 degrees clockwise.
                return glm::rotate(glm::half_pi<float>(), f3CameraViewAxis);

        case Diligent::SURFACE_TRANSFORM_ROTATE_180:
                // The image content is rotated 180 degrees clockwise.
                return glm::rotate(-glm::pi<float>(), f3CameraViewAxis);

        case Diligent::SURFACE_TRANSFORM_ROTATE_270:
                // The image content is rotated 270 degrees clockwise.
                return glm::rotate(-3 * glm::half_pi<float>(), f3CameraViewAxis);

        case Diligent::SURFACE_TRANSFORM_OPTIMAL:
                UNEXPECTED("SURFACE_TRANSFORM_OPTIMAL is only valid as parameter during swap chain initialization.");
                return glm::mat4(1.f);
        // return Diligent::float4x4::Identity();

        case Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR:
        case Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90:
        case Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180:
        case Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270:
                UNEXPECTED("Mirror transforms are not supported");
                return glm::mat4x4(1.f);

        default:
                return glm::mat4x4(1.f);
        }
}
}

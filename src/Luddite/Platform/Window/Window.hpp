#pragma once
#include "Luddite/Core/pch.hpp"
#include "Luddite/Core/Core.hpp"
#include "Luddite/Core/LayerStack.hpp"
#include "Luddite/Core/EventPool.hpp"
#include "Luddite/Graphics/Renderer.hpp"
#include "Luddite/Graphics/RenderTarget.hpp"

namespace Luddite
{
class LUDDITE_API Window
{
        public:

        //settings - temp
        bool m_Vsync = false;


        Window();
        virtual ~Window();
        virtual void SetTitle(const std::string& title) {};
        virtual void Resize(uint32_t width, uint32_t height) {};
        inline uint32_t GetWidth() {return m_pSwapChain->GetDesc().Width;}
        inline uint32_t GetHeight() {return m_pSwapChain->GetDesc().Height;}
        LayerStack& GetLayerStack() {return m_LayerStack;}

        virtual void PollEvents() {};
        void HandleEvents();

        inline bool ShouldQuit() const {return Quit;}
        void SwapBuffers();

        inline RenderTarget GetRenderTarget() {
                auto& SCDesc = m_pSwapChain->GetDesc();
                return {
                        m_pSwapChain->GetCurrentBackBufferRTV(),
                        m_pSwapChain->GetDepthBufferDSV(),
                        SCDesc.Width,
                        SCDesc.Height,
                        true
                };
        }

        glm::mat4x4 GetAdjustedProjectionMatrix(float FOV, float NearPlane, float FarPlane) const;
        glm::mat4x4 GetSurfacePretransformMatrix(const glm::vec3& f3CameraViewAxis) const;

        void ImGuiSetup();
        void ImGuiSetDefaultColors();
        inline std::unique_ptr<Diligent::ImGuiImplDiligent>& GetImGuiImpl() {return m_pImGuiImpl;}
        inline void ImGuiNewFrame()
        {
                m_pImGuiImpl->NewFrame(m_WindowWidth, m_WindowHeight, m_pSwapChain->GetDesc().PreTransform);
        };
        ImGuiContext* GetImGuiContext();

        protected:
        void OnWindowResize(int width, int height);
        int m_WindowWidth = 0;
        int m_WindowHeight = 0;

        Diligent::RefCntAutoPtr<Diligent::ISwapChain> m_pSwapChain;
        bool Quit = false;

        std::unique_ptr<Diligent::ImGuiImplDiligent>  m_pImGuiImpl;

        LayerStack m_LayerStack;
};
}

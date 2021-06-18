#pragma once
#include "Luddite/Core/pch.hpp"
#include "Luddite/ECS/World.hpp"
#include "Luddite/Graphics/RenderTarget.hpp"

namespace Luddite
{
class LUDDITE_API LayerStack;
class LUDDITE_API Layer
{
        public:
        World& GetWorld() {return m_World;}
        virtual ~Layer() {}
        protected:
        friend class LayerStack;
        virtual void Initialize() {}
        virtual void HandleEvents() {}
        virtual void Update(double delta_time) {}
        virtual void Render(double alpha, RenderTarget render_target) {}
        virtual void RenderImGui(double alpha, RenderTarget render_target) {}
        virtual const char* GetName() {return "Unnamed";}
        World m_World;
        bool initialized;
};
class LUDDITE_API LayerStack
{
        public:
        void UpdateLayers(double delta_time);
        void RenderLayers(double alpha, Luddite::RenderTarget render_target);
        void RenderLayersImGui(double alpha, Luddite::RenderTarget render_target);
        void PushLayer(std::shared_ptr<Layer> layer);
        void PopLayer(std::shared_ptr<Layer> layer);
        std::vector<std::string> GetLayerNames();
        std::shared_ptr<Layer> GetLayerByName(const std::string& name);
        void UpdateStack();
        private:
        void DefferedPushLayer(std::shared_ptr<Layer> layer);
        void DefferedPopLayer(std::shared_ptr<Layer> layer);
        std::vector<std::shared_ptr<Layer> > m_stack{};
        std::vector<std::shared_ptr<Layer> > m_remove_queue{};
        std::vector<std::shared_ptr<Layer> > m_add_queue{};
};
}
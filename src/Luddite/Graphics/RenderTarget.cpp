#include "Luddite/Graphics/RenderTarget.hpp"
#include "Luddite/Graphics/Renderer.hpp"

namespace Luddite
{
glm::mat4 RenderTarget::GetViewProjection(const Camera& camera) const
{
        glm::mat4 ProjectionMatrix;
        float AspectRatio = static_cast<float>(width) / static_cast<float>(height);
        float XScale, YScale;
        if (PreTransform == Diligent::SURFACE_TRANSFORM_ROTATE_90 ||
            PreTransform == Diligent::SURFACE_TRANSFORM_ROTATE_270 ||
            PreTransform == Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90 ||
            PreTransform == Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270)
        {
                // When the screen is rotated, vertical FOV becomes horizontal FOV
                XScale = 1.f / std::tan(camera.FOV / 2.f);
                // Aspect ratio is inversed
                YScale = XScale * AspectRatio;
        }
        else
        {
                YScale = 1.f / std::tan(camera.FOV / 2.f);
                XScale = YScale / AspectRatio;
        }
        switch (camera.ProjectionType)
        {
        case Camera::ProjectionType::PERSPECTIVE:
        {
                // ProjectionMatrix[1][1] = XScale;
                // ProjectionMatrix[2][2] = YScale;
                // ProjectionMatrix.SetNearFarClipPlanes(camera.ClipNear, camera.ClipFar, Renderer::GetDevice()->GetDeviceCaps().IsGLDevice());
                ProjectionMatrix = glm::perspective(camera.FOV, YScale / XScale, camera.ClipNear, camera.ClipFar);
                break;
        }

        case Camera::ProjectionType::ORTHOGRAPHIC:
        {
                float ar = XScale / YScale;
                float half_width = camera.OrthoScale * 0.5f;
                float half_height = half_width * ar;
                ProjectionMatrix = glm::ortho(-half_width, half_width, half_height, -half_height);
                // ProjectionMatrix.Ortho(width, height, camera.ClipNear, camera.ClipFar, Renderer::GetDevice()->GetDeviceCaps().IsGLDevice());
                break;
        }
        }

        Diligent::float4x4 PreTransformMatrix;
        switch (PreTransform)
        {
        case Diligent::SURFACE_TRANSFORM_ROTATE_90:
                // The image content is rotated 90 degrees clockwise.
                PreTransformMatrix = Diligent::float4x4::RotationArbitrary(*(Diligent::float3*)&camera.ViewDirection, -Diligent::PI_F / 2.f);

        case Diligent::SURFACE_TRANSFORM_ROTATE_180:
                // The image content is rotated 180 degrees clockwise.
                PreTransformMatrix = Diligent::float4x4::RotationArbitrary(*(Diligent::float3*)&camera.ViewDirection, -Diligent::PI_F);

        case Diligent::SURFACE_TRANSFORM_ROTATE_270:
                // The image content is rotated 270 degrees clockwise.
                PreTransformMatrix = Diligent::float4x4::RotationArbitrary(*(Diligent::float3*)&camera.ViewDirection, -Diligent::PI_F * 3.f / 2.f);

        case Diligent::SURFACE_TRANSFORM_OPTIMAL:
                UNEXPECTED("SURFACE_TRANSFORM_OPTIMAL is only valid as parameter during swap chain initialization.");
                PreTransformMatrix = Diligent::float4x4::Identity();

        case Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR:
        case Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90:
        case Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180:
        case Diligent::SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270:
                UNEXPECTED("Mirror transforms are not supported");
                PreTransformMatrix = Diligent::float4x4::Identity();

        default:
                PreTransformMatrix = Diligent::float4x4::Identity();
        }

        glm::mat4 ViewMatrix = glm::lookAt(camera.Position, camera.Position + camera.ViewDirection, glm::vec3(0.f, 1.f, 0.f));
        // glm::mat4 ViewMatrix = glm::lookAt(camera.Position, glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
        // GLMViewMatrix = glm::transpose(GLMViewMatrix);
        // Diligent::float4x4 ViewMatrix = Diligent::float4x4::Translation(0.f, 0.f, 100.f);

        // Diligent::float4x4 vp = ViewMatrix * ProjectionMatrix;
        glm::mat4 vp = ProjectionMatrix * ViewMatrix;
        return vp;
}
}
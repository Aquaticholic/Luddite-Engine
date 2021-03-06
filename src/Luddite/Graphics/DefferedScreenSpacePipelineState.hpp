// #pragma once
// #include "Luddite/Core/pch.hpp"
// #include "Luddite/Core/Core.hpp"

// #include "Luddite/Graphics/Texture.hpp"
// #include "Luddite/Graphics/ShaderAttributeList.hpp"
// #include "Luddite/Graphics/MaterialLibrary.hpp"
// #include "Luddite/Core/AssetTypes/Model.hpp"

// #include "Luddite/Graphics/DiligentInclude.hpp"

// namespace Luddite
// {
// class DefferedScreenSpacePipelineState
// {
//         public:
//         void Initialize(
//                 Diligent::RefCntAutoPtr<Diligent::IRenderPass> pRenderPass,
//                 const std::string& VSFilePath,
//                 const std::string& PSFilePath,
//                 const std::string& Name,
//                 ShaderBufferDescription ConstantShaderAttributes,
//                 uint8_t Buffers
//                 );
//         void SetMaterial(MaterialHandle Material);
//         void PreRender(int SRBIndex);
//         void PrepareDraw(int SRBIndex);
//         void Draw();

//         inline ShaderBufferDescription& GetConstantDataDesc() {return m_ConstantShaderAttributes;}
//         inline ShaderBufferData& GetConstantData() {return m_ConstantShaderData;}

//         int CreateSRB(Diligent::ITextureView* ColorSRV,
//                       Diligent::ITextureView* NormalSRV,
//                       Diligent::ITextureView* DepthZSRV);
//         void ClearSRBs();
//         private:
//         Diligent::RefCntAutoPtr<Diligent::IPipelineState> m_pPSO;
//         std::vector<Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> > m_SRBs;

//         ShaderBufferDescription m_ConstantShaderAttributes;
//         ShaderBufferData m_ConstantShaderData;
//         Diligent::RefCntAutoPtr<Diligent::IBuffer> m_pShaderConstantsBuffer;
//         uint8_t m_Buffers;
//         // std::unique_ptr<MaterialLibrary> m_pMaterialLibrary;
//         // MaterialHandle m_pCurrentMaterial;
// };
// }
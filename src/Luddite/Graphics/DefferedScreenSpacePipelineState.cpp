// #include "Luddite/Graphics/DefferedScreenSpacePipelineState.hpp"
// #include "Luddite/Graphics/Renderer.hpp"
// #include "Graphics/GraphicsTools/interface/GraphicsUtilities.h"

// using namespace Diligent;
// namespace Luddite
// {
// void DefferedScreenSpacePipelineState::Initialize(
//         Diligent::RefCntAutoPtr<Diligent::IRenderPass> pRenderPass,
//         const std::string& VSFilePath,
//         const std::string& PSFilePath,
//         const std::string& Name,
//         ShaderBufferDescription ConstantShaderAttributes,
//         uint8_t Buffers
//         )
// {
//         m_ConstantShaderAttributes = ConstantShaderAttributes;
//         m_Buffers = Buffers;
//         GraphicsPipelineStateCreateInfo PSOCreateInfo;
//         PipelineStateDesc&              PSODesc = PSOCreateInfo.PSODesc;

//         PSODesc.Name = Name.c_str();
//         PSODesc.PipelineType = Diligent::PIPELINE_TYPE_GRAPHICS;

//         PSOCreateInfo.GraphicsPipeline.pRenderPass = pRenderPass;
//         PSOCreateInfo.GraphicsPipeline.SubpassIndex = 1; // This PSO will be used within the second subpass

//         PSOCreateInfo.GraphicsPipeline.PrimitiveTopology = PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
//         PSOCreateInfo.GraphicsPipeline.RasterizerDesc.CullMode = CULL_MODE_NONE;
//         PSOCreateInfo.GraphicsPipeline.DepthStencilDesc.DepthEnable = False; // Disable depth

//         ShaderCreateInfo ShaderCI;
//         ShaderCI.SourceLanguage = SHADER_SOURCE_LANGUAGE_HLSL;

//         ShaderCI.UseCombinedTextureSamplers = true;

//         ShaderCI.pShaderSourceStreamFactory = Renderer::GetShaderSourceFactory();
//         // Create a vertex shader
//         RefCntAutoPtr<IShader> pVS;
//         {
//                 ShaderCI.Desc.ShaderType = SHADER_TYPE_VERTEX;
//                 ShaderCI.EntryPoint = "main";
//                 ShaderCI.Desc.Name = "light VS";
//                 ShaderCI.FilePath = VSFilePath.c_str();
//                 Renderer::GetDevice()->CreateShader(ShaderCI, &pVS);
//                 VERIFY_EXPR(pVS != nullptr);
//         }

//         // const auto IsVulkan = m_pDevice->GetDeviceCaps().IsVulkanDevice();

//         // Create a pixel shader
//         RefCntAutoPtr<IShader> pPS;
//         {
//                 ShaderCI.SourceLanguage = SHADER_SOURCE_LANGUAGE_HLSL;
//                 ShaderCI.Desc.ShaderType = SHADER_TYPE_PIXEL;
//                 ShaderCI.EntryPoint = "main";
//                 ShaderCI.Desc.Name = "light PS";
//                 ShaderCI.FilePath = PSFilePath.c_str();
//                 Renderer::GetDevice()->CreateShader(ShaderCI, &pPS);
//                 VERIFY_EXPR(pPS != nullptr);
//         }

//         PSOCreateInfo.pVS = pVS;
//         PSOCreateInfo.pPS = pPS;

//         PSODesc.ResourceLayout.DefaultVariableType = SHADER_RESOURCE_VARIABLE_TYPE_STATIC;
//         bool UsingColorBuffer = m_Buffers & static_cast<uint8_t>(DefferedRenderer::G_BUFFER_FLAGS::COLOR);
//         bool UsingNormalBuffer = m_Buffers & static_cast<uint8_t>(DefferedRenderer::G_BUFFER_FLAGS::NORMAL);
//         bool UsingDepthBuffer = m_Buffers & static_cast<uint8_t>(DefferedRenderer::G_BUFFER_FLAGS::DEPTH);


//         SamplerDesc SamLinearClampDesc
//         {
//                 FILTER_TYPE_LINEAR, FILTER_TYPE_LINEAR, FILTER_TYPE_LINEAR,
//                 TEXTURE_ADDRESS_CLAMP, TEXTURE_ADDRESS_CLAMP, TEXTURE_ADDRESS_CLAMP
//         };
//         std::vector<ImmutableSamplerDesc> ImtblSamplers;
//         std::vector<ShaderResourceVariableDesc> Vars;
//         if (m_ConstantShaderAttributes.GetSize() > 0)
//                 Vars.push_back({SHADER_TYPE_PIXEL, "ShaderConstants", SHADER_RESOURCE_VARIABLE_TYPE_STATIC});
//         if (m_ConstantShaderAttributes.Textures.size() > 0)
//         {
//                 for (auto& tex_name : m_ConstantShaderAttributes.Textures)
//                 {
//                         Vars.push_back({SHADER_TYPE_PIXEL, tex_name.c_str(), SHADER_RESOURCE_VARIABLE_TYPE_MUTABLE});
//                         ImtblSamplers.push_back({SHADER_TYPE_PIXEL, tex_name.c_str(), SamLinearClampDesc});
//                 }
//                 PSODesc.ResourceLayout.ImmutableSamplers = ImtblSamplers.data();
//                 PSODesc.ResourceLayout.NumImmutableSamplers = ImtblSamplers.size();
//         }


//         if (UsingColorBuffer)
//                 Vars.push_back({SHADER_TYPE_PIXEL, "g_SubpassInputColor", SHADER_RESOURCE_VARIABLE_TYPE_MUTABLE});
//         if (UsingNormalBuffer)
//                 Vars.push_back({SHADER_TYPE_PIXEL, "g_SubpassInputNormal", SHADER_RESOURCE_VARIABLE_TYPE_MUTABLE});
//         if (UsingDepthBuffer)
//                 Vars.push_back({SHADER_TYPE_PIXEL, "g_SubpassInputDepthZ", SHADER_RESOURCE_VARIABLE_TYPE_MUTABLE});

//         if (Vars.size() > 0)
//         {
//                 PSODesc.ResourceLayout.Variables = Vars.data();
//                 PSODesc.ResourceLayout.NumVariables = Vars.size();
//         }

//         Renderer::GetDevice()->CreateGraphicsPipelineState(PSOCreateInfo, &m_pPSO);
//         VERIFY_EXPR(m_pPSO != nullptr);

//         m_ConstantShaderData = m_ConstantShaderAttributes.CreateData();
//         // m_ConstantShaderAttributes.SetDefaultAttribs(m_ConstantShaderData);

//         if (m_ConstantShaderAttributes.GetSize() > 0)
//         {
//                 CreateUniformBuffer(Renderer::GetDevice(), m_ConstantShaderAttributes.GetSize(), "ShaderConstants", &m_pShaderConstantsBuffer);
//                 StateTransitionDesc Barriers[] = //
//                 {
//                         {m_pShaderConstantsBuffer, RESOURCE_STATE_UNKNOWN, RESOURCE_STATE_CONSTANT_BUFFER, true}
//                 };

//                 Renderer::GetContext()->TransitionResourceStates(_countof(Barriers), Barriers);

//                 m_pPSO->GetStaticVariableByName(SHADER_TYPE_PIXEL, "ShaderConstants")->Set(m_pShaderConstantsBuffer);
//         }
// }
// void DefferedScreenSpacePipelineState::PreRender(int SRBIndex)
// {
//         // Renderer::GetContext()->SetPipelineState(m_pPSO);
//         // m_ConstantShaderAttributes.MapBuffer(m_ConstantShaderData, m_pShaderConstantsBuffer);
//         m_ConstantShaderAttributes.MapTextures(m_ConstantShaderData, m_SRBs[SRBIndex]);
//         // // m_SRBs[SRBIndex]->GetVariableByName(SHADER_TYPE_PIXEL, )


//         // Renderer::GetContext()->CommitShaderResources(m_SRBs[SRBIndex], RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
// }
// void DefferedScreenSpacePipelineState::PrepareDraw(int SRBIndex)
// {
//         Renderer::GetContext()->SetPipelineState(m_pPSO);
//         m_ConstantShaderAttributes.MapBuffer(m_ConstantShaderData, m_pShaderConstantsBuffer);
//         // m_ConstantShaderAttributes.MapTextures(m_ConstantShaderData, m_SRBs[SRBIndex]);
//         // m_SRBs[SRBIndex]->GetVariableByName(SHADER_TYPE_PIXEL, )


//         Renderer::GetContext()->CommitShaderResources(m_SRBs[SRBIndex], RESOURCE_STATE_TRANSITION_MODE_VERIFY);
// }
// void DefferedScreenSpacePipelineState::Draw()
// {
//         DrawAttribs DrawAttrs;
//         DrawAttrs.NumVertices = 4;
//         DrawAttrs.Flags = DRAW_FLAG_VERIFY_ALL;
//         Renderer::GetContext()->Draw(DrawAttrs);
// }
// int DefferedScreenSpacePipelineState::CreateSRB(Diligent::ITextureView* ColorSRV,
//                                                 Diligent::ITextureView* NormalSRV,
//                                                 Diligent::ITextureView* DepthZSRV
//                                                 )
// {
//         Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> new_SRB;

//         m_pPSO->CreateShaderResourceBinding(&new_SRB, true);
//         bool UsingColorBuffer = m_Buffers & static_cast<uint8_t>(DefferedRenderer::G_BUFFER_FLAGS::COLOR);
//         bool UsingNormalBuffer = m_Buffers & static_cast<uint8_t>(DefferedRenderer::G_BUFFER_FLAGS::NORMAL);
//         bool UsingDepthBuffer = m_Buffers & static_cast<uint8_t>(DefferedRenderer::G_BUFFER_FLAGS::DEPTH);

//         // std::vector<ShaderResourceVariableDesc> Vars;
//         // Vars.push_back({SHADER_TYPE_VERTEX, "ShaderConstants", SHADER_RESOURCE_VARIABLE_TYPE_STATIC});


//         if (UsingColorBuffer)
//                 new_SRB->GetVariableByName(SHADER_TYPE_PIXEL, "g_SubpassInputColor")->Set(ColorSRV);
//         if (UsingNormalBuffer)
//                 new_SRB->GetVariableByName(SHADER_TYPE_PIXEL, "g_SubpassInputNormal")->Set(NormalSRV);
//         if (UsingDepthBuffer)
//                 new_SRB->GetVariableByName(SHADER_TYPE_PIXEL, "g_SubpassInputDepthZ")->Set(DepthZSRV);

//         m_SRBs.push_back(new_SRB);
//         return m_SRBs.size() - 1;
// }
// void DefferedScreenSpacePipelineState::ClearSRBs()
// {
//         for (auto& pSRB : m_SRBs)
//                 pSRB.Release();
//         m_SRBs.clear();
// }
// }
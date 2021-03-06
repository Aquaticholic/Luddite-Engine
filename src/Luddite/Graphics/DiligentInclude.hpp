#pragma once
//Platform from Luddite
#include "Luddite/Platform/DiligentPlatform.hpp"

//diligent pch

#include "Primitives/interface/Errors.hpp"
#include "Platforms/Basic/interface/DebugUtilities.hpp"
#include "Common/interface/BasicMath.hpp"

// #include "Common/include/pch.h"
// #include "PlatformDefinitions.h"
// #include "BasicTypes.h"
// #include "Errors.hpp"
// #include "FileWrapper.hpp"
// #include "RefCntAutoPtr.hpp"



// class ImGuiImplDiligent;
//imgui
#define IMGUI_DEFINE_MATH_OPERATORS
#include "ThirdParty/imgui/imgui.h"
#include "Imgui/interface/ImGuiImplDiligent.hpp"
#include "Imgui/interface/ImGuiUtils.hpp"

#include "ImGuizmo.h"

//main
#include "Graphics/GraphicsEngine/interface/RenderDevice.h"
#include "Graphics/GraphicsEngine/interface/DeviceContext.h"
#include "Graphics/GraphicsEngine/interface/SwapChain.h"
#include "Graphics/GraphicsEngine/interface/Texture.h"

#include "Graphics/GraphicsTools/interface/DynamicTextureAtlas.h"
#include "Graphics/GraphicsTools/interface/GraphicsUtilities.h"
#include "TextureLoader/interface/TextureLoader.h"
#include "TextureLoader/interface/TextureUtilities.h"


//pointer
#include "Common/interface/RefCntAutoPtr.hpp"
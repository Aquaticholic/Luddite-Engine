# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/evan/Documents/Dev/Luddite-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evan/Documents/Dev/Luddite-Engine/build

# Include any dependencies generated for this target.
include ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/depend.make

# Include the progress variables for this target.
include ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/progress.make

# Include the compile flags for this target's objects.
include ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/flags.make

# Object files for target Diligent-GraphicsEngineOpenGL-shared
Diligent__GraphicsEngineOpenGL__shared_OBJECTS =

# External object files for target Diligent-GraphicsEngineOpenGL-shared
Diligent__GraphicsEngineOpenGL__shared_EXTERNAL_OBJECTS =

ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/build.make
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libDiligent-GraphicsEngineOpenGL-static.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Graphics/ShaderTools/libDiligent-ShaderTools.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/SPIRV-Cross/libspirv-cross-core.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/glslang/SPIRV/libSPIRV.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/opt/libSPIRV-Tools-opt.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/libSPIRV-Tools.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: /usr/lib/x86_64-linux-gnu/librt.so
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/glslang/glslang/libglslang.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/glslang/glslang/libMachineIndependent.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/glslang/glslang/libGenericCodeGen.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/glslang/OGLCompilersDLL/libOGLCompiler.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/glslang/glslang/OSDependent/Unix/libOSDependent.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Graphics/HLSL2GLSLConverterLib/libDiligent-HLSL2GLSLConverterLib.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Graphics/GraphicsEngine/libDiligent-GraphicsEngine.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Graphics/GraphicsAccessories/libDiligent-GraphicsAccessories.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Common/libDiligent-Common.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Platforms/Linux/libDiligent-LinuxPlatform.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Platforms/Basic/libDiligent-BasicPlatform.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Primitives/libDiligent-Primitives.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/ThirdParty/glew/libglew-static.a
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so: ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/evan/Documents/Dev/Luddite-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX shared library libGraphicsEngineOpenGL.so"
	cd /home/evan/Documents/Dev/Luddite-Engine/build/ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/build: ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/libGraphicsEngineOpenGL.so

.PHONY : ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/build

ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/clean:
	cd /home/evan/Documents/Dev/Luddite-Engine/build/ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL && $(CMAKE_COMMAND) -P CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/cmake_clean.cmake
.PHONY : ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/clean

ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/depend:
	cd /home/evan/Documents/Dev/Luddite-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evan/Documents/Dev/Luddite-Engine /home/evan/Documents/Dev/Luddite-Engine/ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL /home/evan/Documents/Dev/Luddite-Engine/build /home/evan/Documents/Dev/Luddite-Engine/build/ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL /home/evan/Documents/Dev/Luddite-Engine/build/ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ThirdParty/DiligentCore/Graphics/GraphicsEngineOpenGL/CMakeFiles/Diligent-GraphicsEngineOpenGL-shared.dir/depend

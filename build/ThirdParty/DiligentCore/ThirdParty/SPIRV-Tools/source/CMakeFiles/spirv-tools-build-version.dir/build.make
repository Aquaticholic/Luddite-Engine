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

# Utility rule file for spirv-tools-build-version.

# Include the progress variables for this target.
include ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version.dir/progress.make

ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version: ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/build-version.inc


ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/build-version.inc: ../ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/utils/update_build_version.py
ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/build-version.inc: ../ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/CHANGES
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/evan/Documents/Dev/Luddite-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Update build-version.inc in the SPIRV-Tools build directory (if necessary)."
	cd /home/evan/Documents/Dev/Luddite-Engine/build/ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source && /usr/bin/python3 /home/evan/Documents/Dev/Luddite-Engine/ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/utils/update_build_version.py /home/evan/Documents/Dev/Luddite-Engine/ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools /home/evan/Documents/Dev/Luddite-Engine/build/ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/build-version.inc

spirv-tools-build-version: ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version
spirv-tools-build-version: ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/build-version.inc
spirv-tools-build-version: ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version.dir/build.make

.PHONY : spirv-tools-build-version

# Rule to build all files generated by this target.
ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version.dir/build: spirv-tools-build-version

.PHONY : ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version.dir/build

ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version.dir/clean:
	cd /home/evan/Documents/Dev/Luddite-Engine/build/ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source && $(CMAKE_COMMAND) -P CMakeFiles/spirv-tools-build-version.dir/cmake_clean.cmake
.PHONY : ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version.dir/clean

ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version.dir/depend:
	cd /home/evan/Documents/Dev/Luddite-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evan/Documents/Dev/Luddite-Engine /home/evan/Documents/Dev/Luddite-Engine/ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source /home/evan/Documents/Dev/Luddite-Engine/build /home/evan/Documents/Dev/Luddite-Engine/build/ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source /home/evan/Documents/Dev/Luddite-Engine/build/ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ThirdParty/DiligentCore/ThirdParty/SPIRV-Tools/source/CMakeFiles/spirv-tools-build-version.dir/depend

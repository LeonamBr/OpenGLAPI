# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\mingw\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\OpenGLAPI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\OpenGLAPI\build

# Utility rule file for docs.

# Include any custom commands dependencies for this target.
include vendor/glfw/docs/CMakeFiles/docs.dir/compiler_depend.make

# Include the progress variables for this target.
include vendor/glfw/docs/CMakeFiles/docs.dir/progress.make

vendor/glfw/docs/html/index.html: vendor/glfw/docs/Doxyfile
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/include/GLFW/glfw3.h
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/include/GLFW/glfw3native.h
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/main.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/news.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/quick.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/moving.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/compile.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/build.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/intro.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/context.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/monitor.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/window.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/input.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/vulkan.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/compat.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/internal.md
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/DoxygenLayout.xml
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/header.html
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/footer.html
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/extra.css
vendor/glfw/docs/html/index.html: D:/OpenGLAPI/vendor/glfw/docs/spaces.svg
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating HTML documentation"
	cd /d D:\OpenGLAPI\build\vendor\glfw\docs && C:\mingw\bin\doxygen.exe

docs: vendor/glfw/docs/html/index.html
docs: vendor/glfw/docs/CMakeFiles/docs.dir/build.make
.PHONY : docs

# Rule to build all files generated by this target.
vendor/glfw/docs/CMakeFiles/docs.dir/build: docs
.PHONY : vendor/glfw/docs/CMakeFiles/docs.dir/build

vendor/glfw/docs/CMakeFiles/docs.dir/clean:
	cd /d D:\OpenGLAPI\build\vendor\glfw\docs && $(CMAKE_COMMAND) -P CMakeFiles\docs.dir\cmake_clean.cmake
.PHONY : vendor/glfw/docs/CMakeFiles/docs.dir/clean

vendor/glfw/docs/CMakeFiles/docs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\OpenGLAPI D:\OpenGLAPI\vendor\glfw\docs D:\OpenGLAPI\build D:\OpenGLAPI\build\vendor\glfw\docs D:\OpenGLAPI\build\vendor\glfw\docs\CMakeFiles\docs.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : vendor/glfw/docs/CMakeFiles/docs.dir/depend


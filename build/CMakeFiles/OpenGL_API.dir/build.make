# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build

# Include any dependencies generated for this target.
include CMakeFiles/OpenGL_API.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenGL_API.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGL_API.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGL_API.dir/flags.make

CMakeFiles/OpenGL_API.dir/codegen:
.PHONY : CMakeFiles/OpenGL_API.dir/codegen

CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.obj: CMakeFiles/OpenGL_API.dir/flags.make
CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.obj: CMakeFiles/OpenGL_API.dir/includes_CXX.rsp
CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.obj: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/src/sandbox.cpp
CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.obj: CMakeFiles/OpenGL_API.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.obj"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.obj -MF CMakeFiles\OpenGL_API.dir\src\sandbox.cpp.obj.d -o CMakeFiles\OpenGL_API.dir\src\sandbox.cpp.obj -c C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\sandbox.cpp

CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.i"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\sandbox.cpp > CMakeFiles\OpenGL_API.dir\src\sandbox.cpp.i

CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.s"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\sandbox.cpp -o CMakeFiles\OpenGL_API.dir\src\sandbox.cpp.s

CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.obj: CMakeFiles/OpenGL_API.dir/flags.make
CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.obj: CMakeFiles/OpenGL_API.dir/includes_CXX.rsp
CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.obj: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/src/renderer/shader.cpp
CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.obj: CMakeFiles/OpenGL_API.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.obj"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.obj -MF CMakeFiles\OpenGL_API.dir\src\renderer\shader.cpp.obj.d -o CMakeFiles\OpenGL_API.dir\src\renderer\shader.cpp.obj -c C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\shader.cpp

CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.i"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\shader.cpp > CMakeFiles\OpenGL_API.dir\src\renderer\shader.cpp.i

CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.s"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\shader.cpp -o CMakeFiles\OpenGL_API.dir\src\renderer\shader.cpp.s

CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.obj: CMakeFiles/OpenGL_API.dir/flags.make
CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.obj: CMakeFiles/OpenGL_API.dir/includes_CXX.rsp
CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.obj: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/src/renderer/camera.cpp
CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.obj: CMakeFiles/OpenGL_API.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.obj"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.obj -MF CMakeFiles\OpenGL_API.dir\src\renderer\camera.cpp.obj.d -o CMakeFiles\OpenGL_API.dir\src\renderer\camera.cpp.obj -c C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\camera.cpp

CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.i"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\camera.cpp > CMakeFiles\OpenGL_API.dir\src\renderer\camera.cpp.i

CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.s"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\camera.cpp -o CMakeFiles\OpenGL_API.dir\src\renderer\camera.cpp.s

CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.obj: CMakeFiles/OpenGL_API.dir/flags.make
CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.obj: CMakeFiles/OpenGL_API.dir/includes_CXX.rsp
CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.obj: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/src/renderer/mesh.cpp
CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.obj: CMakeFiles/OpenGL_API.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.obj"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.obj -MF CMakeFiles\OpenGL_API.dir\src\renderer\mesh.cpp.obj.d -o CMakeFiles\OpenGL_API.dir\src\renderer\mesh.cpp.obj -c C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\mesh.cpp

CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.i"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\mesh.cpp > CMakeFiles\OpenGL_API.dir\src\renderer\mesh.cpp.i

CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.s"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\mesh.cpp -o CMakeFiles\OpenGL_API.dir\src\renderer\mesh.cpp.s

CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.obj: CMakeFiles/OpenGL_API.dir/flags.make
CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.obj: CMakeFiles/OpenGL_API.dir/includes_CXX.rsp
CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.obj: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/src/renderer/meshFactory.cpp
CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.obj: CMakeFiles/OpenGL_API.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.obj"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.obj -MF CMakeFiles\OpenGL_API.dir\src\renderer\meshFactory.cpp.obj.d -o CMakeFiles\OpenGL_API.dir\src\renderer\meshFactory.cpp.obj -c C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\meshFactory.cpp

CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.i"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\meshFactory.cpp > CMakeFiles\OpenGL_API.dir\src\renderer\meshFactory.cpp.i

CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.s"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\renderer\meshFactory.cpp -o CMakeFiles\OpenGL_API.dir\src\renderer\meshFactory.cpp.s

CMakeFiles/OpenGL_API.dir/src/core/log.cpp.obj: CMakeFiles/OpenGL_API.dir/flags.make
CMakeFiles/OpenGL_API.dir/src/core/log.cpp.obj: CMakeFiles/OpenGL_API.dir/includes_CXX.rsp
CMakeFiles/OpenGL_API.dir/src/core/log.cpp.obj: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/src/core/log.cpp
CMakeFiles/OpenGL_API.dir/src/core/log.cpp.obj: CMakeFiles/OpenGL_API.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OpenGL_API.dir/src/core/log.cpp.obj"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_API.dir/src/core/log.cpp.obj -MF CMakeFiles\OpenGL_API.dir\src\core\log.cpp.obj.d -o CMakeFiles\OpenGL_API.dir\src\core\log.cpp.obj -c C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\core\log.cpp

CMakeFiles/OpenGL_API.dir/src/core/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGL_API.dir/src/core/log.cpp.i"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\core\log.cpp > CMakeFiles\OpenGL_API.dir\src\core\log.cpp.i

CMakeFiles/OpenGL_API.dir/src/core/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGL_API.dir/src/core/log.cpp.s"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\core\log.cpp -o CMakeFiles\OpenGL_API.dir\src\core\log.cpp.s

CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.obj: CMakeFiles/OpenGL_API.dir/flags.make
CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.obj: CMakeFiles/OpenGL_API.dir/includes_CXX.rsp
CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.obj: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/src/openGL/openGLContext.cpp
CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.obj: CMakeFiles/OpenGL_API.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.obj"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.obj -MF CMakeFiles\OpenGL_API.dir\src\openGL\openGLContext.cpp.obj.d -o CMakeFiles\OpenGL_API.dir\src\openGL\openGLContext.cpp.obj -c C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\openGL\openGLContext.cpp

CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.i"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\openGL\openGLContext.cpp > CMakeFiles\OpenGL_API.dir\src\openGL\openGLContext.cpp.i

CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.s"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\openGL\openGLContext.cpp -o CMakeFiles\OpenGL_API.dir\src\openGL\openGLContext.cpp.s

CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.obj: CMakeFiles/OpenGL_API.dir/flags.make
CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.obj: CMakeFiles/OpenGL_API.dir/includes_CXX.rsp
CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.obj: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/src/window/windowSystem.cpp
CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.obj: CMakeFiles/OpenGL_API.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.obj"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.obj -MF CMakeFiles\OpenGL_API.dir\src\window\windowSystem.cpp.obj.d -o CMakeFiles\OpenGL_API.dir\src\window\windowSystem.cpp.obj -c C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\window\windowSystem.cpp

CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.i"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\window\windowSystem.cpp > CMakeFiles\OpenGL_API.dir\src\window\windowSystem.cpp.i

CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.s"
	C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\src\window\windowSystem.cpp -o CMakeFiles\OpenGL_API.dir\src\window\windowSystem.cpp.s

CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.obj: CMakeFiles/OpenGL_API.dir/flags.make
CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.obj: CMakeFiles/OpenGL_API.dir/includes_C.rsp
CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.obj: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/vendor/glad/src/glad.c
CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.obj: CMakeFiles/OpenGL_API.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.obj"
	C:\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.obj -MF CMakeFiles\OpenGL_API.dir\vendor\glad\src\glad.c.obj.d -o CMakeFiles\OpenGL_API.dir\vendor\glad\src\glad.c.obj -c C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\vendor\glad\src\glad.c

CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.i"
	C:\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\vendor\glad\src\glad.c > CMakeFiles\OpenGL_API.dir\vendor\glad\src\glad.c.i

CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.s"
	C:\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\vendor\glad\src\glad.c -o CMakeFiles\OpenGL_API.dir\vendor\glad\src\glad.c.s

# Object files for target OpenGL_API
OpenGL_API_OBJECTS = \
"CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.obj" \
"CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.obj" \
"CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.obj" \
"CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.obj" \
"CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.obj" \
"CMakeFiles/OpenGL_API.dir/src/core/log.cpp.obj" \
"CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.obj" \
"CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.obj" \
"CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.obj"

# External object files for target OpenGL_API
OpenGL_API_EXTERNAL_OBJECTS =

C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/src/sandbox.cpp.obj
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/src/renderer/shader.cpp.obj
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/src/renderer/camera.cpp.obj
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/src/renderer/mesh.cpp.obj
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/src/renderer/meshFactory.cpp.obj
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/src/core/log.cpp.obj
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/src/openGL/openGLContext.cpp.obj
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/src/window/windowSystem.cpp.obj
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/vendor/glad/src/glad.c.obj
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/build.make
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: vendor/glfw/src/libglfw3.a
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: vendor/glm/glm/libglm.a
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: vendor/spdlog/libspdlogd.a
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/linkLibs.rsp
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/objects1.rsp
C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe: CMakeFiles/OpenGL_API.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\OpenGL_API.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OpenGL_API.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGL_API.dir/build: C:/Users/E-FUTEBOLDERUA/Desktop/OpenGLAPI/OpenGL_API.exe
.PHONY : CMakeFiles/OpenGL_API.dir/build

CMakeFiles/OpenGL_API.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OpenGL_API.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OpenGL_API.dir/clean

CMakeFiles/OpenGL_API.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build C:\Users\E-FUTEBOLDERUA\Desktop\OpenGLAPI\build\CMakeFiles\OpenGL_API.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/OpenGL_API.dir/depend


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

# Include any dependencies generated for this target.
include vendor/spdlog/CMakeFiles/spdlog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.make

# Include the progress variables for this target.
include vendor/spdlog/CMakeFiles/spdlog.dir/progress.make

# Include the compile flags for this target's objects.
include vendor/spdlog/CMakeFiles/spdlog.dir/flags.make

vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/includes_CXX.rsp
vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.obj: D:/OpenGLAPI/vendor/spdlog/src/spdlog.cpp
vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.obj"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.obj -MF CMakeFiles\spdlog.dir\src\spdlog.cpp.obj.d -o CMakeFiles\spdlog.dir\src\spdlog.cpp.obj -c D:\OpenGLAPI\vendor\spdlog\src\spdlog.cpp

vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/spdlog.cpp.i"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OpenGLAPI\vendor\spdlog\src\spdlog.cpp > CMakeFiles\spdlog.dir\src\spdlog.cpp.i

vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/spdlog.cpp.s"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\OpenGLAPI\vendor\spdlog\src\spdlog.cpp -o CMakeFiles\spdlog.dir\src\spdlog.cpp.s

vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/includes_CXX.rsp
vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.obj: D:/OpenGLAPI/vendor/spdlog/src/stdout_sinks.cpp
vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.obj"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.obj -MF CMakeFiles\spdlog.dir\src\stdout_sinks.cpp.obj.d -o CMakeFiles\spdlog.dir\src\stdout_sinks.cpp.obj -c D:\OpenGLAPI\vendor\spdlog\src\stdout_sinks.cpp

vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.i"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OpenGLAPI\vendor\spdlog\src\stdout_sinks.cpp > CMakeFiles\spdlog.dir\src\stdout_sinks.cpp.i

vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.s"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\OpenGLAPI\vendor\spdlog\src\stdout_sinks.cpp -o CMakeFiles\spdlog.dir\src\stdout_sinks.cpp.s

vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/includes_CXX.rsp
vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.obj: D:/OpenGLAPI/vendor/spdlog/src/color_sinks.cpp
vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.obj"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.obj -MF CMakeFiles\spdlog.dir\src\color_sinks.cpp.obj.d -o CMakeFiles\spdlog.dir\src\color_sinks.cpp.obj -c D:\OpenGLAPI\vendor\spdlog\src\color_sinks.cpp

vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/color_sinks.cpp.i"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OpenGLAPI\vendor\spdlog\src\color_sinks.cpp > CMakeFiles\spdlog.dir\src\color_sinks.cpp.i

vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/color_sinks.cpp.s"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\OpenGLAPI\vendor\spdlog\src\color_sinks.cpp -o CMakeFiles\spdlog.dir\src\color_sinks.cpp.s

vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/includes_CXX.rsp
vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.obj: D:/OpenGLAPI/vendor/spdlog/src/file_sinks.cpp
vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.obj"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.obj -MF CMakeFiles\spdlog.dir\src\file_sinks.cpp.obj.d -o CMakeFiles\spdlog.dir\src\file_sinks.cpp.obj -c D:\OpenGLAPI\vendor\spdlog\src\file_sinks.cpp

vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/file_sinks.cpp.i"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OpenGLAPI\vendor\spdlog\src\file_sinks.cpp > CMakeFiles\spdlog.dir\src\file_sinks.cpp.i

vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/file_sinks.cpp.s"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\OpenGLAPI\vendor\spdlog\src\file_sinks.cpp -o CMakeFiles\spdlog.dir\src\file_sinks.cpp.s

vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/includes_CXX.rsp
vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.obj: D:/OpenGLAPI/vendor/spdlog/src/async.cpp
vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.obj"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.obj -MF CMakeFiles\spdlog.dir\src\async.cpp.obj.d -o CMakeFiles\spdlog.dir\src\async.cpp.obj -c D:\OpenGLAPI\vendor\spdlog\src\async.cpp

vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/async.cpp.i"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OpenGLAPI\vendor\spdlog\src\async.cpp > CMakeFiles\spdlog.dir\src\async.cpp.i

vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/async.cpp.s"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\OpenGLAPI\vendor\spdlog\src\async.cpp -o CMakeFiles\spdlog.dir\src\async.cpp.s

vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/includes_CXX.rsp
vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.obj: D:/OpenGLAPI/vendor/spdlog/src/cfg.cpp
vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.obj"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.obj -MF CMakeFiles\spdlog.dir\src\cfg.cpp.obj.d -o CMakeFiles\spdlog.dir\src\cfg.cpp.obj -c D:\OpenGLAPI\vendor\spdlog\src\cfg.cpp

vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/cfg.cpp.i"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OpenGLAPI\vendor\spdlog\src\cfg.cpp > CMakeFiles\spdlog.dir\src\cfg.cpp.i

vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/cfg.cpp.s"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\OpenGLAPI\vendor\spdlog\src\cfg.cpp -o CMakeFiles\spdlog.dir\src\cfg.cpp.s

vendor/spdlog/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/spdlog/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/includes_CXX.rsp
vendor/spdlog/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.obj: D:/OpenGLAPI/vendor/spdlog/src/bundled_fmtlib_format.cpp
vendor/spdlog/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.obj: vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object vendor/spdlog/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.obj"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/spdlog/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.obj -MF CMakeFiles\spdlog.dir\src\bundled_fmtlib_format.cpp.obj.d -o CMakeFiles\spdlog.dir\src\bundled_fmtlib_format.cpp.obj -c D:\OpenGLAPI\vendor\spdlog\src\bundled_fmtlib_format.cpp

vendor/spdlog/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.i"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OpenGLAPI\vendor\spdlog\src\bundled_fmtlib_format.cpp > CMakeFiles\spdlog.dir\src\bundled_fmtlib_format.cpp.i

vendor/spdlog/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.s"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\OpenGLAPI\vendor\spdlog\src\bundled_fmtlib_format.cpp -o CMakeFiles\spdlog.dir\src\bundled_fmtlib_format.cpp.s

# Object files for target spdlog
spdlog_OBJECTS = \
"CMakeFiles/spdlog.dir/src/spdlog.cpp.obj" \
"CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.obj" \
"CMakeFiles/spdlog.dir/src/color_sinks.cpp.obj" \
"CMakeFiles/spdlog.dir/src/file_sinks.cpp.obj" \
"CMakeFiles/spdlog.dir/src/async.cpp.obj" \
"CMakeFiles/spdlog.dir/src/cfg.cpp.obj" \
"CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.obj"

# External object files for target spdlog
spdlog_EXTERNAL_OBJECTS =

vendor/spdlog/libspdlogd.a: vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.obj
vendor/spdlog/libspdlogd.a: vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.obj
vendor/spdlog/libspdlogd.a: vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.obj
vendor/spdlog/libspdlogd.a: vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.obj
vendor/spdlog/libspdlogd.a: vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.obj
vendor/spdlog/libspdlogd.a: vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.obj
vendor/spdlog/libspdlogd.a: vendor/spdlog/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.obj
vendor/spdlog/libspdlogd.a: vendor/spdlog/CMakeFiles/spdlog.dir/build.make
vendor/spdlog/libspdlogd.a: vendor/spdlog/CMakeFiles/spdlog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\OpenGLAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libspdlogd.a"
	cd /d D:\OpenGLAPI\build\vendor\spdlog && $(CMAKE_COMMAND) -P CMakeFiles\spdlog.dir\cmake_clean_target.cmake
	cd /d D:\OpenGLAPI\build\vendor\spdlog && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\spdlog.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vendor/spdlog/CMakeFiles/spdlog.dir/build: vendor/spdlog/libspdlogd.a
.PHONY : vendor/spdlog/CMakeFiles/spdlog.dir/build

vendor/spdlog/CMakeFiles/spdlog.dir/clean:
	cd /d D:\OpenGLAPI\build\vendor\spdlog && $(CMAKE_COMMAND) -P CMakeFiles\spdlog.dir\cmake_clean.cmake
.PHONY : vendor/spdlog/CMakeFiles/spdlog.dir/clean

vendor/spdlog/CMakeFiles/spdlog.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\OpenGLAPI D:\OpenGLAPI\vendor\spdlog D:\OpenGLAPI\build D:\OpenGLAPI\build\vendor\spdlog D:\OpenGLAPI\build\vendor\spdlog\CMakeFiles\spdlog.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : vendor/spdlog/CMakeFiles/spdlog.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/deb/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/deb/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/deb/workspace/cgol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deb/workspace/cgol

# Include any dependencies generated for this target.
include CMakeFiles/cgol.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/cgol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cgol.dir/flags.make

CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.o: CMakeFiles/cgol.dir/flags.make
CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.o: cgol_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deb/workspace/cgol/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.o -c /home/deb/workspace/cgol/cgol_autogen/mocs_compilation.cpp

CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deb/workspace/cgol/cgol_autogen/mocs_compilation.cpp > CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.i

CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deb/workspace/cgol/cgol_autogen/mocs_compilation.cpp -o CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.s

CMakeFiles/cgol.dir/widget.cpp.o: CMakeFiles/cgol.dir/flags.make
CMakeFiles/cgol.dir/widget.cpp.o: widget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deb/workspace/cgol/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cgol.dir/widget.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgol.dir/widget.cpp.o -c /home/deb/workspace/cgol/widget.cpp

CMakeFiles/cgol.dir/widget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgol.dir/widget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deb/workspace/cgol/widget.cpp > CMakeFiles/cgol.dir/widget.cpp.i

CMakeFiles/cgol.dir/widget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgol.dir/widget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deb/workspace/cgol/widget.cpp -o CMakeFiles/cgol.dir/widget.cpp.s

CMakeFiles/cgol.dir/app.cpp.o: CMakeFiles/cgol.dir/flags.make
CMakeFiles/cgol.dir/app.cpp.o: app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deb/workspace/cgol/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cgol.dir/app.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgol.dir/app.cpp.o -c /home/deb/workspace/cgol/app.cpp

CMakeFiles/cgol.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgol.dir/app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deb/workspace/cgol/app.cpp > CMakeFiles/cgol.dir/app.cpp.i

CMakeFiles/cgol.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgol.dir/app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deb/workspace/cgol/app.cpp -o CMakeFiles/cgol.dir/app.cpp.s

# Object files for target cgol
cgol_OBJECTS = \
"CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/cgol.dir/widget.cpp.o" \
"CMakeFiles/cgol.dir/app.cpp.o"

# External object files for target cgol
cgol_EXTERNAL_OBJECTS =

cgol: CMakeFiles/cgol.dir/cgol_autogen/mocs_compilation.cpp.o
cgol: CMakeFiles/cgol.dir/widget.cpp.o
cgol: CMakeFiles/cgol.dir/app.cpp.o
cgol: CMakeFiles/cgol.dir/build.make
cgol: /home/deb/Qt/6.1.3/gcc_64/lib/libQt6Widgets.so.6.1.3
cgol: /home/deb/Qt/6.1.3/gcc_64/lib/libQt6Gui.so.6.1.3
cgol: /usr/lib/x86_64-linux-gnu/libGL.so
cgol: /home/deb/Qt/6.1.3/gcc_64/lib/libQt6Core.so.6.1.3
cgol: CMakeFiles/cgol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/deb/workspace/cgol/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cgol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cgol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cgol.dir/build: cgol
.PHONY : CMakeFiles/cgol.dir/build

CMakeFiles/cgol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cgol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cgol.dir/clean

CMakeFiles/cgol.dir/depend:
	cd /home/deb/workspace/cgol && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deb/workspace/cgol /home/deb/workspace/cgol /home/deb/workspace/cgol /home/deb/workspace/cgol /home/deb/workspace/cgol/CMakeFiles/cgol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cgol.dir/depend


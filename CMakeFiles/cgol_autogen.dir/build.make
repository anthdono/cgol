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
CMAKE_SOURCE_DIR = /home/deb/localdir/cgol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deb/localdir/cgol

# Utility rule file for cgol_autogen.

# Include the progress variables for this target.
include CMakeFiles/cgol_autogen.dir/progress.make

CMakeFiles/cgol_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/deb/localdir/cgol/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target cgol"
	/usr/bin/cmake -E cmake_autogen /home/deb/localdir/cgol/CMakeFiles/cgol_autogen.dir/AutogenInfo.json ""

cgol_autogen: CMakeFiles/cgol_autogen
cgol_autogen: CMakeFiles/cgol_autogen.dir/build.make

.PHONY : cgol_autogen

# Rule to build all files generated by this target.
CMakeFiles/cgol_autogen.dir/build: cgol_autogen

.PHONY : CMakeFiles/cgol_autogen.dir/build

CMakeFiles/cgol_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cgol_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cgol_autogen.dir/clean

CMakeFiles/cgol_autogen.dir/depend:
	cd /home/deb/localdir/cgol && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deb/localdir/cgol /home/deb/localdir/cgol /home/deb/localdir/cgol /home/deb/localdir/cgol /home/deb/localdir/cgol/CMakeFiles/cgol_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cgol_autogen.dir/depend


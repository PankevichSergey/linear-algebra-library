# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/honeybadger/hse/linal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/honeybadger/hse/linal/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linal.dir/flags.make

CMakeFiles/linal.dir/main.cpp.o: CMakeFiles/linal.dir/flags.make
CMakeFiles/linal.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/honeybadger/hse/linal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linal.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linal.dir/main.cpp.o -c /Users/honeybadger/hse/linal/main.cpp

CMakeFiles/linal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linal.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/honeybadger/hse/linal/main.cpp > CMakeFiles/linal.dir/main.cpp.i

CMakeFiles/linal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linal.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/honeybadger/hse/linal/main.cpp -o CMakeFiles/linal.dir/main.cpp.s

CMakeFiles/linal.dir/Num.cpp.o: CMakeFiles/linal.dir/flags.make
CMakeFiles/linal.dir/Num.cpp.o: ../Num.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/honeybadger/hse/linal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/linal.dir/Num.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linal.dir/Num.cpp.o -c /Users/honeybadger/hse/linal/Num.cpp

CMakeFiles/linal.dir/Num.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linal.dir/Num.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/honeybadger/hse/linal/Num.cpp > CMakeFiles/linal.dir/Num.cpp.i

CMakeFiles/linal.dir/Num.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linal.dir/Num.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/honeybadger/hse/linal/Num.cpp -o CMakeFiles/linal.dir/Num.cpp.s

CMakeFiles/linal.dir/Mat.cpp.o: CMakeFiles/linal.dir/flags.make
CMakeFiles/linal.dir/Mat.cpp.o: ../Mat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/honeybadger/hse/linal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/linal.dir/Mat.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linal.dir/Mat.cpp.o -c /Users/honeybadger/hse/linal/Mat.cpp

CMakeFiles/linal.dir/Mat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linal.dir/Mat.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/honeybadger/hse/linal/Mat.cpp > CMakeFiles/linal.dir/Mat.cpp.i

CMakeFiles/linal.dir/Mat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linal.dir/Mat.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/honeybadger/hse/linal/Mat.cpp -o CMakeFiles/linal.dir/Mat.cpp.s

CMakeFiles/linal.dir/Vec.cpp.o: CMakeFiles/linal.dir/flags.make
CMakeFiles/linal.dir/Vec.cpp.o: ../Vec.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/honeybadger/hse/linal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/linal.dir/Vec.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linal.dir/Vec.cpp.o -c /Users/honeybadger/hse/linal/Vec.cpp

CMakeFiles/linal.dir/Vec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linal.dir/Vec.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/honeybadger/hse/linal/Vec.cpp > CMakeFiles/linal.dir/Vec.cpp.i

CMakeFiles/linal.dir/Vec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linal.dir/Vec.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/honeybadger/hse/linal/Vec.cpp -o CMakeFiles/linal.dir/Vec.cpp.s

CMakeFiles/linal.dir/trash.cpp.o: CMakeFiles/linal.dir/flags.make
CMakeFiles/linal.dir/trash.cpp.o: ../trash.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/honeybadger/hse/linal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/linal.dir/trash.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linal.dir/trash.cpp.o -c /Users/honeybadger/hse/linal/trash.cpp

CMakeFiles/linal.dir/trash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linal.dir/trash.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/honeybadger/hse/linal/trash.cpp > CMakeFiles/linal.dir/trash.cpp.i

CMakeFiles/linal.dir/trash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linal.dir/trash.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/honeybadger/hse/linal/trash.cpp -o CMakeFiles/linal.dir/trash.cpp.s

CMakeFiles/linal.dir/Perm.cpp.o: CMakeFiles/linal.dir/flags.make
CMakeFiles/linal.dir/Perm.cpp.o: ../Perm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/honeybadger/hse/linal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/linal.dir/Perm.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linal.dir/Perm.cpp.o -c /Users/honeybadger/hse/linal/Perm.cpp

CMakeFiles/linal.dir/Perm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linal.dir/Perm.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/honeybadger/hse/linal/Perm.cpp > CMakeFiles/linal.dir/Perm.cpp.i

CMakeFiles/linal.dir/Perm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linal.dir/Perm.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/honeybadger/hse/linal/Perm.cpp -o CMakeFiles/linal.dir/Perm.cpp.s

CMakeFiles/linal.dir/Poly.cpp.o: CMakeFiles/linal.dir/flags.make
CMakeFiles/linal.dir/Poly.cpp.o: ../Poly.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/honeybadger/hse/linal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/linal.dir/Poly.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linal.dir/Poly.cpp.o -c /Users/honeybadger/hse/linal/Poly.cpp

CMakeFiles/linal.dir/Poly.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linal.dir/Poly.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/honeybadger/hse/linal/Poly.cpp > CMakeFiles/linal.dir/Poly.cpp.i

CMakeFiles/linal.dir/Poly.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linal.dir/Poly.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/honeybadger/hse/linal/Poly.cpp -o CMakeFiles/linal.dir/Poly.cpp.s

# Object files for target linal
linal_OBJECTS = \
"CMakeFiles/linal.dir/main.cpp.o" \
"CMakeFiles/linal.dir/Num.cpp.o" \
"CMakeFiles/linal.dir/Mat.cpp.o" \
"CMakeFiles/linal.dir/Vec.cpp.o" \
"CMakeFiles/linal.dir/trash.cpp.o" \
"CMakeFiles/linal.dir/Perm.cpp.o" \
"CMakeFiles/linal.dir/Poly.cpp.o"

# External object files for target linal
linal_EXTERNAL_OBJECTS =

linal: CMakeFiles/linal.dir/main.cpp.o
linal: CMakeFiles/linal.dir/Num.cpp.o
linal: CMakeFiles/linal.dir/Mat.cpp.o
linal: CMakeFiles/linal.dir/Vec.cpp.o
linal: CMakeFiles/linal.dir/trash.cpp.o
linal: CMakeFiles/linal.dir/Perm.cpp.o
linal: CMakeFiles/linal.dir/Poly.cpp.o
linal: CMakeFiles/linal.dir/build.make
linal: CMakeFiles/linal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/honeybadger/hse/linal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable linal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linal.dir/build: linal

.PHONY : CMakeFiles/linal.dir/build

CMakeFiles/linal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linal.dir/clean

CMakeFiles/linal.dir/depend:
	cd /Users/honeybadger/hse/linal/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/honeybadger/hse/linal /Users/honeybadger/hse/linal /Users/honeybadger/hse/linal/cmake-build-debug /Users/honeybadger/hse/linal/cmake-build-debug /Users/honeybadger/hse/linal/cmake-build-debug/CMakeFiles/linal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linal.dir/depend

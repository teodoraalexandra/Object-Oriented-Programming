# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/teodoradan/CLionProjects/Inheritance

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Inheritance.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Inheritance.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Inheritance.dir/flags.make

CMakeFiles/Inheritance.dir/main.cpp.o: CMakeFiles/Inheritance.dir/flags.make
CMakeFiles/Inheritance.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Inheritance.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Inheritance.dir/main.cpp.o -c /Users/teodoradan/CLionProjects/Inheritance/main.cpp

CMakeFiles/Inheritance.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Inheritance.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/Inheritance/main.cpp > CMakeFiles/Inheritance.dir/main.cpp.i

CMakeFiles/Inheritance.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Inheritance.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/Inheritance/main.cpp -o CMakeFiles/Inheritance.dir/main.cpp.s

CMakeFiles/Inheritance.dir/Animal.cpp.o: CMakeFiles/Inheritance.dir/flags.make
CMakeFiles/Inheritance.dir/Animal.cpp.o: ../Animal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Inheritance.dir/Animal.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Inheritance.dir/Animal.cpp.o -c /Users/teodoradan/CLionProjects/Inheritance/Animal.cpp

CMakeFiles/Inheritance.dir/Animal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Inheritance.dir/Animal.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/Inheritance/Animal.cpp > CMakeFiles/Inheritance.dir/Animal.cpp.i

CMakeFiles/Inheritance.dir/Animal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Inheritance.dir/Animal.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/Inheritance/Animal.cpp -o CMakeFiles/Inheritance.dir/Animal.cpp.s

CMakeFiles/Inheritance.dir/Penguin.cpp.o: CMakeFiles/Inheritance.dir/flags.make
CMakeFiles/Inheritance.dir/Penguin.cpp.o: ../Penguin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Inheritance.dir/Penguin.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Inheritance.dir/Penguin.cpp.o -c /Users/teodoradan/CLionProjects/Inheritance/Penguin.cpp

CMakeFiles/Inheritance.dir/Penguin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Inheritance.dir/Penguin.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/Inheritance/Penguin.cpp > CMakeFiles/Inheritance.dir/Penguin.cpp.i

CMakeFiles/Inheritance.dir/Penguin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Inheritance.dir/Penguin.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/Inheritance/Penguin.cpp -o CMakeFiles/Inheritance.dir/Penguin.cpp.s

CMakeFiles/Inheritance.dir/Dog.cpp.o: CMakeFiles/Inheritance.dir/flags.make
CMakeFiles/Inheritance.dir/Dog.cpp.o: ../Dog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Inheritance.dir/Dog.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Inheritance.dir/Dog.cpp.o -c /Users/teodoradan/CLionProjects/Inheritance/Dog.cpp

CMakeFiles/Inheritance.dir/Dog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Inheritance.dir/Dog.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/Inheritance/Dog.cpp > CMakeFiles/Inheritance.dir/Dog.cpp.i

CMakeFiles/Inheritance.dir/Dog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Inheritance.dir/Dog.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/Inheritance/Dog.cpp -o CMakeFiles/Inheritance.dir/Dog.cpp.s

# Object files for target Inheritance
Inheritance_OBJECTS = \
"CMakeFiles/Inheritance.dir/main.cpp.o" \
"CMakeFiles/Inheritance.dir/Animal.cpp.o" \
"CMakeFiles/Inheritance.dir/Penguin.cpp.o" \
"CMakeFiles/Inheritance.dir/Dog.cpp.o"

# External object files for target Inheritance
Inheritance_EXTERNAL_OBJECTS =

Inheritance: CMakeFiles/Inheritance.dir/main.cpp.o
Inheritance: CMakeFiles/Inheritance.dir/Animal.cpp.o
Inheritance: CMakeFiles/Inheritance.dir/Penguin.cpp.o
Inheritance: CMakeFiles/Inheritance.dir/Dog.cpp.o
Inheritance: CMakeFiles/Inheritance.dir/build.make
Inheritance: CMakeFiles/Inheritance.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Inheritance"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Inheritance.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Inheritance.dir/build: Inheritance

.PHONY : CMakeFiles/Inheritance.dir/build

CMakeFiles/Inheritance.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Inheritance.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Inheritance.dir/clean

CMakeFiles/Inheritance.dir/depend:
	cd /Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/teodoradan/CLionProjects/Inheritance /Users/teodoradan/CLionProjects/Inheritance /Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug /Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug /Users/teodoradan/CLionProjects/Inheritance/cmake-build-debug/CMakeFiles/Inheritance.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Inheritance.dir/depend


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
CMAKE_SOURCE_DIR = /Users/teodoradan/CLionProjects/quiz2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/teodoradan/CLionProjects/quiz2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/quiz2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/quiz2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quiz2.dir/flags.make

CMakeFiles/quiz2.dir/main.cpp.o: CMakeFiles/quiz2.dir/flags.make
CMakeFiles/quiz2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/quiz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quiz2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quiz2.dir/main.cpp.o -c /Users/teodoradan/CLionProjects/quiz2/main.cpp

CMakeFiles/quiz2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quiz2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/quiz2/main.cpp > CMakeFiles/quiz2.dir/main.cpp.i

CMakeFiles/quiz2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quiz2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/quiz2/main.cpp -o CMakeFiles/quiz2.dir/main.cpp.s

CMakeFiles/quiz2.dir/controller.cpp.o: CMakeFiles/quiz2.dir/flags.make
CMakeFiles/quiz2.dir/controller.cpp.o: ../controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/quiz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/quiz2.dir/controller.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quiz2.dir/controller.cpp.o -c /Users/teodoradan/CLionProjects/quiz2/controller.cpp

CMakeFiles/quiz2.dir/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quiz2.dir/controller.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/quiz2/controller.cpp > CMakeFiles/quiz2.dir/controller.cpp.i

CMakeFiles/quiz2.dir/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quiz2.dir/controller.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/quiz2/controller.cpp -o CMakeFiles/quiz2.dir/controller.cpp.s

CMakeFiles/quiz2.dir/repository.cpp.o: CMakeFiles/quiz2.dir/flags.make
CMakeFiles/quiz2.dir/repository.cpp.o: ../repository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/quiz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/quiz2.dir/repository.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quiz2.dir/repository.cpp.o -c /Users/teodoradan/CLionProjects/quiz2/repository.cpp

CMakeFiles/quiz2.dir/repository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quiz2.dir/repository.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/quiz2/repository.cpp > CMakeFiles/quiz2.dir/repository.cpp.i

CMakeFiles/quiz2.dir/repository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quiz2.dir/repository.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/quiz2/repository.cpp -o CMakeFiles/quiz2.dir/repository.cpp.s

CMakeFiles/quiz2.dir/question.cpp.o: CMakeFiles/quiz2.dir/flags.make
CMakeFiles/quiz2.dir/question.cpp.o: ../question.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/quiz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/quiz2.dir/question.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quiz2.dir/question.cpp.o -c /Users/teodoradan/CLionProjects/quiz2/question.cpp

CMakeFiles/quiz2.dir/question.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quiz2.dir/question.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/quiz2/question.cpp > CMakeFiles/quiz2.dir/question.cpp.i

CMakeFiles/quiz2.dir/question.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quiz2.dir/question.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/quiz2/question.cpp -o CMakeFiles/quiz2.dir/question.cpp.s

CMakeFiles/quiz2.dir/participant.cpp.o: CMakeFiles/quiz2.dir/flags.make
CMakeFiles/quiz2.dir/participant.cpp.o: ../participant.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/quiz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/quiz2.dir/participant.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quiz2.dir/participant.cpp.o -c /Users/teodoradan/CLionProjects/quiz2/participant.cpp

CMakeFiles/quiz2.dir/participant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quiz2.dir/participant.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/quiz2/participant.cpp > CMakeFiles/quiz2.dir/participant.cpp.i

CMakeFiles/quiz2.dir/participant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quiz2.dir/participant.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/quiz2/participant.cpp -o CMakeFiles/quiz2.dir/participant.cpp.s

CMakeFiles/quiz2.dir/presentergui.cpp.o: CMakeFiles/quiz2.dir/flags.make
CMakeFiles/quiz2.dir/presentergui.cpp.o: ../presentergui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/quiz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/quiz2.dir/presentergui.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quiz2.dir/presentergui.cpp.o -c /Users/teodoradan/CLionProjects/quiz2/presentergui.cpp

CMakeFiles/quiz2.dir/presentergui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quiz2.dir/presentergui.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/quiz2/presentergui.cpp > CMakeFiles/quiz2.dir/presentergui.cpp.i

CMakeFiles/quiz2.dir/presentergui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quiz2.dir/presentergui.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/quiz2/presentergui.cpp -o CMakeFiles/quiz2.dir/presentergui.cpp.s

CMakeFiles/quiz2.dir/participantgui.cpp.o: CMakeFiles/quiz2.dir/flags.make
CMakeFiles/quiz2.dir/participantgui.cpp.o: ../participantgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodoradan/CLionProjects/quiz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/quiz2.dir/participantgui.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quiz2.dir/participantgui.cpp.o -c /Users/teodoradan/CLionProjects/quiz2/participantgui.cpp

CMakeFiles/quiz2.dir/participantgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quiz2.dir/participantgui.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodoradan/CLionProjects/quiz2/participantgui.cpp > CMakeFiles/quiz2.dir/participantgui.cpp.i

CMakeFiles/quiz2.dir/participantgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quiz2.dir/participantgui.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodoradan/CLionProjects/quiz2/participantgui.cpp -o CMakeFiles/quiz2.dir/participantgui.cpp.s

# Object files for target quiz2
quiz2_OBJECTS = \
"CMakeFiles/quiz2.dir/main.cpp.o" \
"CMakeFiles/quiz2.dir/controller.cpp.o" \
"CMakeFiles/quiz2.dir/repository.cpp.o" \
"CMakeFiles/quiz2.dir/question.cpp.o" \
"CMakeFiles/quiz2.dir/participant.cpp.o" \
"CMakeFiles/quiz2.dir/presentergui.cpp.o" \
"CMakeFiles/quiz2.dir/participantgui.cpp.o"

# External object files for target quiz2
quiz2_EXTERNAL_OBJECTS =

quiz2: CMakeFiles/quiz2.dir/main.cpp.o
quiz2: CMakeFiles/quiz2.dir/controller.cpp.o
quiz2: CMakeFiles/quiz2.dir/repository.cpp.o
quiz2: CMakeFiles/quiz2.dir/question.cpp.o
quiz2: CMakeFiles/quiz2.dir/participant.cpp.o
quiz2: CMakeFiles/quiz2.dir/presentergui.cpp.o
quiz2: CMakeFiles/quiz2.dir/participantgui.cpp.o
quiz2: CMakeFiles/quiz2.dir/build.make
quiz2: CMakeFiles/quiz2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/teodoradan/CLionProjects/quiz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable quiz2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quiz2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quiz2.dir/build: quiz2

.PHONY : CMakeFiles/quiz2.dir/build

CMakeFiles/quiz2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quiz2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quiz2.dir/clean

CMakeFiles/quiz2.dir/depend:
	cd /Users/teodoradan/CLionProjects/quiz2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/teodoradan/CLionProjects/quiz2 /Users/teodoradan/CLionProjects/quiz2 /Users/teodoradan/CLionProjects/quiz2/cmake-build-debug /Users/teodoradan/CLionProjects/quiz2/cmake-build-debug /Users/teodoradan/CLionProjects/quiz2/cmake-build-debug/CMakeFiles/quiz2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quiz2.dir/depend


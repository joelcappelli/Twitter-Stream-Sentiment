# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joel/Documents/Twitter-Stream-Sentiment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joel/Documents/Twitter-Stream-Sentiment/build

# Include any dependencies generated for this target.
include CMakeFiles/twitdash.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/twitdash.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/twitdash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/twitdash.dir/flags.make

CMakeFiles/twitdash.dir/src/dashboard.cpp.o: CMakeFiles/twitdash.dir/flags.make
CMakeFiles/twitdash.dir/src/dashboard.cpp.o: ../src/dashboard.cpp
CMakeFiles/twitdash.dir/src/dashboard.cpp.o: CMakeFiles/twitdash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joel/Documents/Twitter-Stream-Sentiment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/twitdash.dir/src/dashboard.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/twitdash.dir/src/dashboard.cpp.o -MF CMakeFiles/twitdash.dir/src/dashboard.cpp.o.d -o CMakeFiles/twitdash.dir/src/dashboard.cpp.o -c /home/joel/Documents/Twitter-Stream-Sentiment/src/dashboard.cpp

CMakeFiles/twitdash.dir/src/dashboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/twitdash.dir/src/dashboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joel/Documents/Twitter-Stream-Sentiment/src/dashboard.cpp > CMakeFiles/twitdash.dir/src/dashboard.cpp.i

CMakeFiles/twitdash.dir/src/dashboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/twitdash.dir/src/dashboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joel/Documents/Twitter-Stream-Sentiment/src/dashboard.cpp -o CMakeFiles/twitdash.dir/src/dashboard.cpp.s

# Object files for target twitdash
twitdash_OBJECTS = \
"CMakeFiles/twitdash.dir/src/dashboard.cpp.o"

# External object files for target twitdash
twitdash_EXTERNAL_OBJECTS =

twitdash: CMakeFiles/twitdash.dir/src/dashboard.cpp.o
twitdash: CMakeFiles/twitdash.dir/build.make
twitdash: CMakeFiles/twitdash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joel/Documents/Twitter-Stream-Sentiment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable twitdash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/twitdash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/twitdash.dir/build: twitdash
.PHONY : CMakeFiles/twitdash.dir/build

CMakeFiles/twitdash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/twitdash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/twitdash.dir/clean

CMakeFiles/twitdash.dir/depend:
	cd /home/joel/Documents/Twitter-Stream-Sentiment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joel/Documents/Twitter-Stream-Sentiment /home/joel/Documents/Twitter-Stream-Sentiment /home/joel/Documents/Twitter-Stream-Sentiment/build /home/joel/Documents/Twitter-Stream-Sentiment/build /home/joel/Documents/Twitter-Stream-Sentiment/build/CMakeFiles/twitdash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/twitdash.dir/depend


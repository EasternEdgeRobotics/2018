# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/eer/moos-ivp/ivp/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/eer/moos-ivp/build

# Include any dependencies generated for this target.
include app_alogeplot/CMakeFiles/alogeplot.dir/depend.make

# Include the progress variables for this target.
include app_alogeplot/CMakeFiles/alogeplot.dir/progress.make

# Include the compile flags for this target's objects.
include app_alogeplot/CMakeFiles/alogeplot.dir/flags.make

app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o: app_alogeplot/CMakeFiles/alogeplot.dir/flags.make
app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o: /home/nick/eer/moos-ivp/ivp/src/app_alogeplot/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/eer/moos-ivp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o"
	cd /home/nick/eer/moos-ivp/build/app_alogeplot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/alogeplot.dir/main.cpp.o -c /home/nick/eer/moos-ivp/ivp/src/app_alogeplot/main.cpp

app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alogeplot.dir/main.cpp.i"
	cd /home/nick/eer/moos-ivp/build/app_alogeplot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/eer/moos-ivp/ivp/src/app_alogeplot/main.cpp > CMakeFiles/alogeplot.dir/main.cpp.i

app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alogeplot.dir/main.cpp.s"
	cd /home/nick/eer/moos-ivp/build/app_alogeplot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/eer/moos-ivp/ivp/src/app_alogeplot/main.cpp -o CMakeFiles/alogeplot.dir/main.cpp.s

app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o.requires:

.PHONY : app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o.requires

app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o.provides: app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o.requires
	$(MAKE) -f app_alogeplot/CMakeFiles/alogeplot.dir/build.make app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o.provides.build
.PHONY : app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o.provides

app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o.provides.build: app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o


app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o: app_alogeplot/CMakeFiles/alogeplot.dir/flags.make
app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o: /home/nick/eer/moos-ivp/ivp/src/app_alogeplot/EPlotEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/eer/moos-ivp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o"
	cd /home/nick/eer/moos-ivp/build/app_alogeplot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o -c /home/nick/eer/moos-ivp/ivp/src/app_alogeplot/EPlotEngine.cpp

app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alogeplot.dir/EPlotEngine.cpp.i"
	cd /home/nick/eer/moos-ivp/build/app_alogeplot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/eer/moos-ivp/ivp/src/app_alogeplot/EPlotEngine.cpp > CMakeFiles/alogeplot.dir/EPlotEngine.cpp.i

app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alogeplot.dir/EPlotEngine.cpp.s"
	cd /home/nick/eer/moos-ivp/build/app_alogeplot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/eer/moos-ivp/ivp/src/app_alogeplot/EPlotEngine.cpp -o CMakeFiles/alogeplot.dir/EPlotEngine.cpp.s

app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o.requires:

.PHONY : app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o.requires

app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o.provides: app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o.requires
	$(MAKE) -f app_alogeplot/CMakeFiles/alogeplot.dir/build.make app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o.provides.build
.PHONY : app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o.provides

app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o.provides.build: app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o


# Object files for target alogeplot
alogeplot_OBJECTS = \
"CMakeFiles/alogeplot.dir/main.cpp.o" \
"CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o"

# External object files for target alogeplot
alogeplot_EXTERNAL_OBJECTS =

/home/nick/eer/moos-ivp/bin/alogeplot: app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o
/home/nick/eer/moos-ivp/bin/alogeplot: app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o
/home/nick/eer/moos-ivp/bin/alogeplot: app_alogeplot/CMakeFiles/alogeplot.dir/build.make
/home/nick/eer/moos-ivp/bin/alogeplot: /home/nick/eer/moos-ivp/lib/liblogutils.a
/home/nick/eer/moos-ivp/bin/alogeplot: /home/nick/eer/moos-ivp/lib/libencounters.a
/home/nick/eer/moos-ivp/bin/alogeplot: /home/nick/eer/moos-ivp/lib/libmbutil.a
/home/nick/eer/moos-ivp/bin/alogeplot: app_alogeplot/CMakeFiles/alogeplot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/eer/moos-ivp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/nick/eer/moos-ivp/bin/alogeplot"
	cd /home/nick/eer/moos-ivp/build/app_alogeplot && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alogeplot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app_alogeplot/CMakeFiles/alogeplot.dir/build: /home/nick/eer/moos-ivp/bin/alogeplot

.PHONY : app_alogeplot/CMakeFiles/alogeplot.dir/build

app_alogeplot/CMakeFiles/alogeplot.dir/requires: app_alogeplot/CMakeFiles/alogeplot.dir/main.cpp.o.requires
app_alogeplot/CMakeFiles/alogeplot.dir/requires: app_alogeplot/CMakeFiles/alogeplot.dir/EPlotEngine.cpp.o.requires

.PHONY : app_alogeplot/CMakeFiles/alogeplot.dir/requires

app_alogeplot/CMakeFiles/alogeplot.dir/clean:
	cd /home/nick/eer/moos-ivp/build/app_alogeplot && $(CMAKE_COMMAND) -P CMakeFiles/alogeplot.dir/cmake_clean.cmake
.PHONY : app_alogeplot/CMakeFiles/alogeplot.dir/clean

app_alogeplot/CMakeFiles/alogeplot.dir/depend:
	cd /home/nick/eer/moos-ivp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/eer/moos-ivp/ivp/src /home/nick/eer/moos-ivp/ivp/src/app_alogeplot /home/nick/eer/moos-ivp/build /home/nick/eer/moos-ivp/build/app_alogeplot /home/nick/eer/moos-ivp/build/app_alogeplot/CMakeFiles/alogeplot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app_alogeplot/CMakeFiles/alogeplot.dir/depend


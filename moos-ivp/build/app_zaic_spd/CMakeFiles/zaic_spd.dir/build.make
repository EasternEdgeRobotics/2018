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
include app_zaic_spd/CMakeFiles/zaic_spd.dir/depend.make

# Include the progress variables for this target.
include app_zaic_spd/CMakeFiles/zaic_spd.dir/progress.make

# Include the compile flags for this target's objects.
include app_zaic_spd/CMakeFiles/zaic_spd.dir/flags.make

app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o: app_zaic_spd/CMakeFiles/zaic_spd.dir/flags.make
app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o: /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/eer/moos-ivp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zaic_spd.dir/main.cpp.o -c /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/main.cpp

app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zaic_spd.dir/main.cpp.i"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/main.cpp > CMakeFiles/zaic_spd.dir/main.cpp.i

app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zaic_spd.dir/main.cpp.s"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/main.cpp -o CMakeFiles/zaic_spd.dir/main.cpp.s

app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o.requires:

.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o.requires

app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o.provides: app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o.requires
	$(MAKE) -f app_zaic_spd/CMakeFiles/zaic_spd.dir/build.make app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o.provides.build
.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o.provides

app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o.provides.build: app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o


app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o: app_zaic_spd/CMakeFiles/zaic_spd.dir/flags.make
app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o: /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/ZAIC_SPD_GUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/eer/moos-ivp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o -c /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/ZAIC_SPD_GUI.cpp

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.i"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/ZAIC_SPD_GUI.cpp > CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.i

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.s"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/ZAIC_SPD_GUI.cpp -o CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.s

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o.requires:

.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o.requires

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o.provides: app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o.requires
	$(MAKE) -f app_zaic_spd/CMakeFiles/zaic_spd.dir/build.make app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o.provides.build
.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o.provides

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o.provides.build: app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o


app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o: app_zaic_spd/CMakeFiles/zaic_spd.dir/flags.make
app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o: /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/ZAIC_SPD_Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/eer/moos-ivp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o -c /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/ZAIC_SPD_Model.cpp

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.i"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/ZAIC_SPD_Model.cpp > CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.i

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.s"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd/ZAIC_SPD_Model.cpp -o CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.s

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o.requires:

.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o.requires

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o.provides: app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o.requires
	$(MAKE) -f app_zaic_spd/CMakeFiles/zaic_spd.dir/build.make app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o.provides.build
.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o.provides

app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o.provides.build: app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o


# Object files for target zaic_spd
zaic_spd_OBJECTS = \
"CMakeFiles/zaic_spd.dir/main.cpp.o" \
"CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o" \
"CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o"

# External object files for target zaic_spd
zaic_spd_EXTERNAL_OBJECTS =

/home/nick/eer/moos-ivp/bin/zaic_spd: app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o
/home/nick/eer/moos-ivp/bin/zaic_spd: app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o
/home/nick/eer/moos-ivp/bin/zaic_spd: app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o
/home/nick/eer/moos-ivp/bin/zaic_spd: app_zaic_spd/CMakeFiles/zaic_spd.dir/build.make
/home/nick/eer/moos-ivp/bin/zaic_spd: /home/nick/eer/moos-ivp/lib/libzaicview.a
/home/nick/eer/moos-ivp/bin/zaic_spd: /home/nick/eer/moos-ivp/lib/libivpbuild.a
/home/nick/eer/moos-ivp/bin/zaic_spd: /home/nick/eer/moos-ivp/lib/libmbutil.a
/home/nick/eer/moos-ivp/bin/zaic_spd: /home/nick/eer/moos-ivp/lib/libivpcore.a
/home/nick/eer/moos-ivp/bin/zaic_spd: /home/nick/eer/moos-ivp/lib/libivpsolve.a
/home/nick/eer/moos-ivp/bin/zaic_spd: app_zaic_spd/CMakeFiles/zaic_spd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/eer/moos-ivp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable /home/nick/eer/moos-ivp/bin/zaic_spd"
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zaic_spd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app_zaic_spd/CMakeFiles/zaic_spd.dir/build: /home/nick/eer/moos-ivp/bin/zaic_spd

.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/build

app_zaic_spd/CMakeFiles/zaic_spd.dir/requires: app_zaic_spd/CMakeFiles/zaic_spd.dir/main.cpp.o.requires
app_zaic_spd/CMakeFiles/zaic_spd.dir/requires: app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_GUI.cpp.o.requires
app_zaic_spd/CMakeFiles/zaic_spd.dir/requires: app_zaic_spd/CMakeFiles/zaic_spd.dir/ZAIC_SPD_Model.cpp.o.requires

.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/requires

app_zaic_spd/CMakeFiles/zaic_spd.dir/clean:
	cd /home/nick/eer/moos-ivp/build/app_zaic_spd && $(CMAKE_COMMAND) -P CMakeFiles/zaic_spd.dir/cmake_clean.cmake
.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/clean

app_zaic_spd/CMakeFiles/zaic_spd.dir/depend:
	cd /home/nick/eer/moos-ivp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/eer/moos-ivp/ivp/src /home/nick/eer/moos-ivp/ivp/src/app_zaic_spd /home/nick/eer/moos-ivp/build /home/nick/eer/moos-ivp/build/app_zaic_spd /home/nick/eer/moos-ivp/build/app_zaic_spd/CMakeFiles/zaic_spd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app_zaic_spd/CMakeFiles/zaic_spd.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/lokendra/c++/c++_opencv/day3/hit_miss

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lokendra/c++/c++_opencv/day3/hit_miss

# Include any dependencies generated for this target.
include CMakeFiles/HitMiss.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HitMiss.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HitMiss.dir/flags.make

CMakeFiles/HitMiss.dir/HitMiss.cpp.o: CMakeFiles/HitMiss.dir/flags.make
CMakeFiles/HitMiss.dir/HitMiss.cpp.o: HitMiss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lokendra/c++/c++_opencv/day3/hit_miss/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HitMiss.dir/HitMiss.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HitMiss.dir/HitMiss.cpp.o -c /home/lokendra/c++/c++_opencv/day3/hit_miss/HitMiss.cpp

CMakeFiles/HitMiss.dir/HitMiss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HitMiss.dir/HitMiss.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lokendra/c++/c++_opencv/day3/hit_miss/HitMiss.cpp > CMakeFiles/HitMiss.dir/HitMiss.cpp.i

CMakeFiles/HitMiss.dir/HitMiss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HitMiss.dir/HitMiss.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lokendra/c++/c++_opencv/day3/hit_miss/HitMiss.cpp -o CMakeFiles/HitMiss.dir/HitMiss.cpp.s

# Object files for target HitMiss
HitMiss_OBJECTS = \
"CMakeFiles/HitMiss.dir/HitMiss.cpp.o"

# External object files for target HitMiss
HitMiss_EXTERNAL_OBJECTS =

HitMiss: CMakeFiles/HitMiss.dir/HitMiss.cpp.o
HitMiss: CMakeFiles/HitMiss.dir/build.make
HitMiss: /usr/local/lib/libopencv_gapi.so.4.5.3
HitMiss: /usr/local/lib/libopencv_stitching.so.4.5.3
HitMiss: /usr/local/lib/libopencv_aruco.so.4.5.3
HitMiss: /usr/local/lib/libopencv_barcode.so.4.5.3
HitMiss: /usr/local/lib/libopencv_bgsegm.so.4.5.3
HitMiss: /usr/local/lib/libopencv_bioinspired.so.4.5.3
HitMiss: /usr/local/lib/libopencv_ccalib.so.4.5.3
HitMiss: /usr/local/lib/libopencv_dnn_objdetect.so.4.5.3
HitMiss: /usr/local/lib/libopencv_dnn_superres.so.4.5.3
HitMiss: /usr/local/lib/libopencv_dpm.so.4.5.3
HitMiss: /usr/local/lib/libopencv_face.so.4.5.3
HitMiss: /usr/local/lib/libopencv_freetype.so.4.5.3
HitMiss: /usr/local/lib/libopencv_fuzzy.so.4.5.3
HitMiss: /usr/local/lib/libopencv_hfs.so.4.5.3
HitMiss: /usr/local/lib/libopencv_img_hash.so.4.5.3
HitMiss: /usr/local/lib/libopencv_intensity_transform.so.4.5.3
HitMiss: /usr/local/lib/libopencv_line_descriptor.so.4.5.3
HitMiss: /usr/local/lib/libopencv_mcc.so.4.5.3
HitMiss: /usr/local/lib/libopencv_quality.so.4.5.3
HitMiss: /usr/local/lib/libopencv_rapid.so.4.5.3
HitMiss: /usr/local/lib/libopencv_reg.so.4.5.3
HitMiss: /usr/local/lib/libopencv_rgbd.so.4.5.3
HitMiss: /usr/local/lib/libopencv_saliency.so.4.5.3
HitMiss: /usr/local/lib/libopencv_stereo.so.4.5.3
HitMiss: /usr/local/lib/libopencv_structured_light.so.4.5.3
HitMiss: /usr/local/lib/libopencv_superres.so.4.5.3
HitMiss: /usr/local/lib/libopencv_surface_matching.so.4.5.3
HitMiss: /usr/local/lib/libopencv_tracking.so.4.5.3
HitMiss: /usr/local/lib/libopencv_videostab.so.4.5.3
HitMiss: /usr/local/lib/libopencv_wechat_qrcode.so.4.5.3
HitMiss: /usr/local/lib/libopencv_xfeatures2d.so.4.5.3
HitMiss: /usr/local/lib/libopencv_xobjdetect.so.4.5.3
HitMiss: /usr/local/lib/libopencv_xphoto.so.4.5.3
HitMiss: /usr/local/lib/libopencv_shape.so.4.5.3
HitMiss: /usr/local/lib/libopencv_highgui.so.4.5.3
HitMiss: /usr/local/lib/libopencv_datasets.so.4.5.3
HitMiss: /usr/local/lib/libopencv_plot.so.4.5.3
HitMiss: /usr/local/lib/libopencv_text.so.4.5.3
HitMiss: /usr/local/lib/libopencv_ml.so.4.5.3
HitMiss: /usr/local/lib/libopencv_phase_unwrapping.so.4.5.3
HitMiss: /usr/local/lib/libopencv_optflow.so.4.5.3
HitMiss: /usr/local/lib/libopencv_ximgproc.so.4.5.3
HitMiss: /usr/local/lib/libopencv_video.so.4.5.3
HitMiss: /usr/local/lib/libopencv_videoio.so.4.5.3
HitMiss: /usr/local/lib/libopencv_dnn.so.4.5.3
HitMiss: /usr/local/lib/libopencv_imgcodecs.so.4.5.3
HitMiss: /usr/local/lib/libopencv_objdetect.so.4.5.3
HitMiss: /usr/local/lib/libopencv_calib3d.so.4.5.3
HitMiss: /usr/local/lib/libopencv_features2d.so.4.5.3
HitMiss: /usr/local/lib/libopencv_flann.so.4.5.3
HitMiss: /usr/local/lib/libopencv_photo.so.4.5.3
HitMiss: /usr/local/lib/libopencv_imgproc.so.4.5.3
HitMiss: /usr/local/lib/libopencv_core.so.4.5.3
HitMiss: CMakeFiles/HitMiss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lokendra/c++/c++_opencv/day3/hit_miss/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HitMiss"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HitMiss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HitMiss.dir/build: HitMiss

.PHONY : CMakeFiles/HitMiss.dir/build

CMakeFiles/HitMiss.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HitMiss.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HitMiss.dir/clean

CMakeFiles/HitMiss.dir/depend:
	cd /home/lokendra/c++/c++_opencv/day3/hit_miss && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lokendra/c++/c++_opencv/day3/hit_miss /home/lokendra/c++/c++_opencv/day3/hit_miss /home/lokendra/c++/c++_opencv/day3/hit_miss /home/lokendra/c++/c++_opencv/day3/hit_miss /home/lokendra/c++/c++_opencv/day3/hit_miss/CMakeFiles/HitMiss.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HitMiss.dir/depend

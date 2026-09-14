cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)
project(gz-demo-math VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The libgz-math9-dev deb installs the CMake package unversioned, as
# gz-math-config.cmake under .../cmake/gz-math/, exporting the target
# gz-math::gz-math (headers live under include/gz/math9, but the CMake
# package/target names carry no suffix). Verified via
# `dpkg -L libgz-math9-dev | grep cmake` inside the Jetty (ubuntu:resolute)
# container. The rosdistro package name in the distribution file is also
# unversioned (gz-math) but is a separate namespace from this CMake name;
# they happen to coincide here.
#
# Because the CMake package name carries no major version, an unversioned
# find_package(gz-math) would silently accept any Gazebo collection, not just
# Jetty's gz-math 9 -- defeating the point of this package. Requesting the
# major version explicitly (a bare "9", not EXACT) restores that check:
# gz-math-config-version.cmake uses standard SameMajorVersion semantics, so a
# bare "9" accepts any 9.x.y (this container installs 9.3.0) and rejects a
# different major such as a Rotary nightly's 10.0.0, while EXACT would also
# reject 9.3.0 itself.
find_package(gz-math 9 REQUIRED)

add_executable(gz_demo_math src/main.cc)
target_link_libraries(gz_demo_math PRIVATE gz-math::gz-math)

install(TARGETS gz_demo_math RUNTIME DESTINATION bin)

# include(CTest) defines BUILD_TESTING, default ON. The buildfarm job passes
# -DBUILD_TESTING=ON explicitly; nothing here is package-specific.
include(CTest)
if(BUILD_TESTING)
  find_package(GTest REQUIRED)
  add_executable(pose_test test/pose_test.cc)
  target_link_libraries(pose_test PRIVATE gz-math::gz-math GTest::gtest_main)
  add_test(NAME pose_test COMMAND pose_test)
endif()

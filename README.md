# gz-demo-math

A trivial consumer of Gazebo Math, written for one purpose: to be the single
package in `my_gazebo_demo_distribution`, a rosdistro distribution with no ROS
lineage that extends Gazebo Jetty through the REP-2015 `extends` mechanism.

`package.xml` depends on `gz-math` — the package name in Jetty's distribution
file, not a rosdep key. That dependency is what forces the rosdistro
dependency walker through the extended parent, so a buildfarm job for this
package is a test of the extension.

Build it like any CMake project, against a Jetty installation:

    cmake -B build -S . -DBUILD_TESTING=ON && cmake --build build && ctest --test-dir build

// Copyright 2026 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>

#include <gz/math/Helpers.hh>
#include <gz/math/Pose3.hh>

int main()
{
  // Pure translations compose by adding; no rotation is involved.
  const gz::math::Pose3d a{1, 2, 3, 0, 0, 0};
  const gz::math::Pose3d b{10, 20, 30, 0, 0, 0};
  std::cout << "a * b       = " << (a * b) << std::endl;

  // A quarter turn about Z rotates the child's offset into the parent frame.
  const gz::math::Pose3d yaw{0, 0, 0, 0, 0, GZ_PI_2};
  const gz::math::Pose3d unitX{1, 0, 0, 0, 0, 0};
  std::cout << "yaw * unitX = " << (yaw * unitX) << std::endl;

  return 0;
}

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

#include <gtest/gtest.h>

#include <gz/math/Helpers.hh>
#include <gz/math/Pose3.hh>
#include <gz/math/Vector3.hh>

// Pose3d::operator* returns Pose3(b.CoordPositionAdd(a), a.q * b.q), which
// places b in a's frame: position = a.p + a.q * b.p.
TEST(Pose3d, PureTranslationsAdd)
{
  const gz::math::Pose3d a{1, 2, 3, 0, 0, 0};
  const gz::math::Pose3d b{10, 20, 30, 0, 0, 0};
  EXPECT_EQ(gz::math::Pose3d(11, 22, 33, 0, 0, 0), a * b);
}

TEST(Pose3d, YawRotatesTheChildOffset)
{
  const gz::math::Pose3d yaw{0, 0, 0, 0, 0, GZ_PI_2};
  const gz::math::Pose3d unitX{1, 0, 0, 0, 0, 0};
  const gz::math::Vector3d got = (yaw * unitX).Pos();
  EXPECT_NEAR(0.0, got.X(), 1e-9);
  EXPECT_NEAR(1.0, got.Y(), 1e-9);
  EXPECT_NEAR(0.0, got.Z(), 1e-9);
}

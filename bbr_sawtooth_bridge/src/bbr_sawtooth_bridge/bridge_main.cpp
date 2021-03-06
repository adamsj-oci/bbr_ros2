// Copyright 2019, Ruffin White.
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

#include <inttypes.h>
#include <memory>
#include "bbr_sawtooth_bridge/bridge_node.hpp"
#include "rclcpp/rclcpp.hpp"

using Bridge = bbr_sawtooth_bridge::Bridge;

int main(int argc, char * argv[])
{
  auto other_args = rclcpp::init_and_remove_ros_arguments(argc, argv);
//  TODO: Use a proper c++ argparse
// https://github.com/ros2/rcpputils/issues/15

  std::string signer_key_path = other_args[1];
  std::string batcher_key_path = other_args[2];

  rclcpp::spin(std::make_shared<Bridge>(
      "bbr_sawtooth_bridge",
      signer_key_path,
      batcher_key_path));
  rclcpp::shutdown();
  return 0;
}

/**
 *  MIT License
 *
 *  Copyright (c) 2019 Charan Karthikeyan P V, Nagireddi Jagadesh Nischal
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without
 *  limitation the rights to use, copy, modify, merge, publish, distribute,
 *  sublicense, and/or sell copies of the Software, and to permit persons to
 *  whom the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */

/**
 * @file TurtlebotController.cpp
 * @author Charan Karthikeyan P V (Driver), Nagireddi Jagadesh Nischal (Navigator)
 * @copyright MIT License.
 * @date 3/12/2019
 * @brief The Initialization file to send control messages from the move_base
 * to the turtlebot.
 */

#include "../include/warehouse_material_handling_turtlebot/TurtlebotController.h"

TurtlebotController::TurtlebotController() {
}

TurtlebotController::~TurtlebotController() {
}

void TurtlebotController::readVel() {
  subscribeVel = nodeH.subscribe("/navigation_velocity_smoother/raw_cmd_vel",
                        200, &TurtlebotController::velocityMsgCallback, this);
}

geometry_msgs::Twist TurtlebotController::getVel() {
  return cmdVelocity;
}

void TurtlebotController::velocityMsgCallback(
    const geometry_msgs::Twist::ConstPtr& msg) {
  cmdVelocity = *(msg);
}

void TurtlebotController::writeVel() {
  publishVel.publish(cmdVelocity);
}

// Author(s): Kelvin Kang (kelvinkang@cmu.edu)
// This file is subject to the terms and conditions defined in the file 'LICENSE',
// which is part of this source code package

// always add include guard for all .h files
#pragma once

// std libraries
#include <iostream>
#include <vector>
#include <cmath>

// ROS libraries
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>

/**
 * @brief transform IMU msg from camera convention to ENU convention for acc and ang vel only
 * @return publish another IMU msg
 */
class ImuCoordinateTransformer
{
public:
  ImuCoordinateTransformer();
  ~ImuCoordinateTransformer() {}

private:
  /////////////////////// State variables ///////////////////////

  /// current IMU data transformed
  sensor_msgs::Imu transformedImu_;

  // ROS and node related variables
  ros::NodeHandle nh_, private_nh_;
  ros::Subscriber imuSub_;
  ros::Publisher imuPub_;

  // Boiler plate ROS functions
  void initRos();
 
  /**
   * @brief where the transform happens
   * @param imuMsg
   */
  void imuCallback(const sensor_msgs::Imu& imuMsg);
};

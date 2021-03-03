// Author(s): Kelvin Kang (kelvinkang@cmu.edu)
// This file is subject to the terms and conditions defined in the file 'LICENSE',
// which is part of this source code package

#include "imu_coordinate_transformer.h"

// convention is to put Constructor at the very top
ImuCoordinateTransformer::ImuCoordinateTransformer() : private_nh_("~")
{
  // put boiler plate ROS stuff in this function
  initRos();
}

void ImuCoordinateTransformer::imuCallback(const sensor_msgs::Imu& imuMsg)
{
  transformedImu_ = imuMsg;
  transformedImu_.header.frame_id = "imu_link";
  transformedImu_.linear_acceleration.z = -imuMsg.linear_acceleration.y;
  transformedImu_.linear_acceleration.y = -imuMsg.linear_acceleration.z;
  transformedImu_.angular_velocity.z = -imuMsg.angular_velocity.y;
  transformedImu_.angular_velocity.y = -imuMsg.angular_velocity.z;
  
  imuPub_.publish(transformedImu_);
}

void ImuCoordinateTransformer::initRos()
{
  // set subscriber
  imuSub_ = nh_.subscribe("/camera/imu", 1, &ImuCoordinateTransformer::imuCallback, this);

  // set publisher
  imuPub_ = nh_.advertise<sensor_msgs::Imu>("/imu", 2);
}

// keep the main function as clean as possible
int main(int argc, char** argv)
{
  ros::init(argc, argv, "ImuCoordinateTransformer");
  ImuCoordinateTransformer node;
  while (ros::ok())
    ros::spinOnce();
  return 0;
}

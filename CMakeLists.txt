cmake_minimum_required(VERSION 3.10.2)
project(imu_coordinate_transformer VERSION 0.0.1)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  rostest
  rosunit
)

catkin_package(CATKIN_DEPENDS
  roscpp
  rospy
  std_msgs
  sensor_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

# add executables from your source code, i.e. compile it
# .py code are not included here as they do not need to be compiled
add_executable(imu_coordinate_transformer 
  src/imu_coordinate_transformer.cpp
)

target_link_libraries(imu_coordinate_transformer
  ${catkin_LIBRARIES}
  )

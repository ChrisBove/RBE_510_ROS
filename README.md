# RBE_580_ROS
Provides a ROS wrapper for the WPI RBE 580 course utilizing the Sparki Robots

## Packages
* sparki_field_computer - ROS interface for Sparki field computer.
* sparki_control - ROS controller for sparki-related movements
* sparki_bringup - launch files for starting sparki-related processes or samples

## Setup
Clone this repo into your catkin workspace. Build with catkin_make, and make sure your workspace devel/setup.bash has been sourced.

## Running
We provide an RVIZ configuration for quickly viewing the pertinent information available on the field. Using the 2D Nav Goal button will send the pose stamped message on the `/robot/goal` topic.
```
roslaunch sparki_bringup rviz_field.launch
```

A static TF tree of the robots and field can be brought up with:
```
roslaunch sparki_bringup test_sparki_tf.launch
``` 

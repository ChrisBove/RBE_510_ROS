# RBE_580_ROS
Provides a ROS implementation for the WPI RBE 580 course utilizing the Sparki Robots. In this configuration, a Logitech webcam observes a table with the Sparki robots on top, equipped with AR Tags.

## Packages
* sparki_field_computer - ROS interface for Sparki field computer.
* sparki_control - ROS controller for sparki-related movements
* sparki_bringup - launch files for starting sparki-related processes or samples

## Setup
Install the dependencies (newer distros of ROS may work, but this was tested on Ubuntu 14.04 with Indigo):
```
sudo apt-get install ros-indigo-desktop-full
sudo apt-get install ros-indigo-usb-cam ros-indigo-image-proc ros-indigo-camera-calibration ros-indigo-aruco ros-indigo-ar-track-alvar
```

Clone this repo into your catkin workspace. Build with catkin_make, and make sure your workspace devel/setup.bash has been sourced.

## Running
We provide an RVIZ configuration for quickly viewing the pertinent information available on the field. Using the 2D Nav Goal button will send the pose stamped message on the `/robot/goal` topic. Also note the information that will eventually be available in this implementation: field camera image, occupancy grid map, tf data, and entity marker array.
```
roslaunch sparki_bringup rviz_field.launch
```

A static TF tree of the robots and field can be brought up with:
```
roslaunch sparki_bringup test_sparki_tf.launch
``` 

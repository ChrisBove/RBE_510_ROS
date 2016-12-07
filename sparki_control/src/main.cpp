//
// Created by carlh on 12/6/16.
//

#include <ros/ros.h>
#include <sparki_pid.hpp>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "Sparki_PID");
    ros::NodeHandle privateNode("~");
    std::string name;

    privateNode.getParam("name", name);
    SparkiPID pid(name);
    ROS_ERROR("I got the ros named: %s", name.c_str());
    ros::Rate rate(10);
    while(ros::ok()) {
        pid.publishMessage();
        ros::spinOnce();
        rate.sleep();
    }
}
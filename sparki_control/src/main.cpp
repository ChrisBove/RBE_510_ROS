//
// Created by carlh on 12/6/16.
//

#include <ros/ros.h>
#include <sparki_pid.hpp>
#include <geometry_msgs/Pose2D.h>
#include <iostream>

using namespace std;
using namespace SparkiControl;

void testAdvertiser(Publisher pub) {
    geometry_msgs::Pose2D msg;
    msg.theta = 0;
    msg.x = 100;
    msg.y = 200;
    ros::Rate rate(1);
    while(ros::ok()) {
        ROS_INFO("Publishing Message");
        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
    }
}

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "Sparki_PID");
    ros::NodeHandle privateNode("~");
    std::string name = "pid";

    NodeHandle nodeHandle(name);
    Publisher pub = nodeHandle.advertise<geometry_msgs::Pose2D>("robot_pose", 10);

    // Some RAII here, acquiring the pid hooks up hooks up its messages and gets it ready to rock-and-roll
    SparkiPID pid(name);

    testAdvertiser(pub);
}

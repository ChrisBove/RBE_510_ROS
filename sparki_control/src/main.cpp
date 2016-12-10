//
// Created by carlh on 12/6/16.
//

#include <ros/ros.h>
#include <sparki_set_pose.hpp>
#include <geometry_msgs/PointStamped.h>

using namespace std;
using namespace SparkiControl;
//
//void testAdvertiser(Publisher pub) {
//    geometry_msgs::PointStamped msg;
//    msg.header.stamp = ros::Time::now();
//    msg.header.frame_id = "world";
//    msg.point.x = 100;
//    msg.point.y = 200;
//    msg.point.z = 0;
//    ros::Rate rate(1);
//    while(ros::ok()) {
//        ROS_INFO("Publishing Message");
//        pub.publish(msg);
//        ros::spinOnce();
//        rate.sleep();
//    }
//}

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "Sparki_PID");

    //NodeHandle nodeHandle;
    //Publisher pub = nodeHandle.advertise<geometry_msgs::PointStamped>("go_to_point", 10);

    // Some RAII here, acquiring the pid hooks up hooks up its messages and gets it ready to rock-and-roll
    SparkiSetPose gotopoint;
    ros::Rate rate(10);
    while(ros::ok()) {
        ros::spinOnce();
        rate.sleep();
    }

   // testAdvertiser(pub);
}

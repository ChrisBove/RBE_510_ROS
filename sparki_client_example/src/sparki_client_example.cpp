//
// Created by carlh on 12/10/16.
//

#include <sparki_client_example.h>
#include <ros/ros.h>
#include <geometry_msgs/PointStamped.h>
#include <vector>
#include <string>

#define NUM_SPARKIS 3
#define SPARKI_PREFIX "/sparki"

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "TestClient");
    std::vector<ros::Publisher> publishers;
    ros::NodeHandle node;

    for (size_t i = 0; i < NUM_SPARKIS; i++) {
        std::stringstream topicName;
        topicName << SPARKI_PREFIX << i+1 << "/go_to_point";
        publishers.push_back(node.advertise<geometry_msgs::PointStamped>(topicName.str(), 10));
    }

    ros::Rate rate(1);
    while (ros::ok()) {
        for (size_t i = 0; i < NUM_SPARKIS; i++) {
            geometry_msgs::PointStamped point;
            point.header.stamp = ros::Time::now();
            point.point.x = 100;
            point.point.y = 200;
            point.point.x = 0;
            publishers[i].publish(point);
        }
        ros::spinOnce();
        rate.sleep();
    }
}

//
// Created by carlh on 12/10/16.
//

#include <sparki_client_example.h>
#include <ros/ros.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/PoseStamped.h>
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
        topicName << SPARKI_PREFIX << i+1 << "/set_pose";
        publishers.push_back(node.advertise<geometry_msgs::PoseStamped>(topicName.str(), 10));
    }

    ros::Rate rate(1);
    while (ros::ok()) {
        for (size_t i = 0; i < NUM_SPARKIS; i++) {
            // This is where you would run your path planning algorithm.  Each sparki publishes a /tf message
            // which can be used in your A* (for example) algorithm to guide your Sparki to its destination.
        }
        ros::spinOnce();
        rate.sleep();
    }
}

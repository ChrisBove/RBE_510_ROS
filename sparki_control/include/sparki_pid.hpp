#ifndef SPARKI_PID_HPP
#define SPARKI_PID_HPP

#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <geometry_msgs/Twist.h>
#include <string>

using namespace std;
using namespace ros;

    class SparkiPID {
    private:
        tf2_ros::TransformBroadcaster m_broadcaster;
        NodeHandle* m_node;
        Publisher m_publisher;
        int m_counter;
    public:
        SparkiPID(string name);
        void publishMessage();
    };

#endif
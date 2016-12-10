#ifndef SPARKI_PID_HPP
#define SPARKI_PID_HPP

#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/Pose2D.h>
#include <string>

using namespace std;
using namespace ros;

namespace SparkiControl {
    class SparkiPID {
    private:
        tf2_ros::TransformBroadcaster m_broadcaster;
        NodeHandle* m_node;
        Publisher m_publisher;
        Subscriber m_poseSubscriber;
        int m_counter;

    private: // Lifecycle methods
        void ConnectSubscribers();
        void DisconnectSubscribers();
        void AdvertisePublishers(string name);
        void UnAdvertisePublishers();

    private: // Callbacks
        void poseCallback(const geometry_msgs::Pose2DConstPtr& message);

    public:
        SparkiPID(string name);
        ~SparkiPID();

        void publishMessage(geometry_msgs::TwistStampedConstPtr twist);
    };
}
#endif
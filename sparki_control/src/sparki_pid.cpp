//
// Created by carlh on 12/6/16.
//

#include <sparki_pid.hpp>

using namespace SparkiControl;

void SparkiPID::poseCallback(const geometry_msgs::Pose2DConstPtr &message) {
    ROS_INFO("Updating Pose");
    geometry_msgs::TwistStamped twist;
    // TODO - Twist will actually be created by the real PID
    twist.twist.angular.x = 1.0;
    twist.twist.angular.y = 5.0;
    twist.twist.angular.z = 0.0;
    twist.twist.linear.x = 100;
    twist.twist.linear.y = 200;
    twist.twist.linear.z = 0;
    twist.header.stamp = ros::Time::now();
    geometry_msgs::TwistStampedConstPtr ptr(new geometry_msgs::TwistStamped(twist));
    publishMessage(ptr);
}

SparkiPID::SparkiPID(string name) {
    ROS_INFO("Initializing SparkiPID");
    m_counter = 0;
    m_node = new NodeHandle(name);
    ConnectSubscribers();
    AdvertisePublishers(name);
    ROS_INFO("SparkiPID is ready");
}

SparkiPID::~SparkiPID() {
    ROS_INFO("Destroying the PID");
    DisconnectSubscribers(); // Probably don't need this?  I think it'll automatically unsubscribe when this goes out of scope.
    UnAdvertisePublishers();
    m_node->shutdown();
}

void SparkiPID::ConnectSubscribers() {
    m_poseSubscriber = m_node->subscribe<geometry_msgs::Pose2D>("robot_pose", 10, &SparkiPID::poseCallback, this);
}

void SparkiPID::DisconnectSubscribers() {
    m_poseSubscriber.shutdown();
}

void SparkiPID::AdvertisePublishers(string name) {
    m_publisher = m_node->advertise<geometry_msgs::TwistStamped>(name+"/twist", 10);
}

void SparkiPID::UnAdvertisePublishers() {
    m_publisher.shutdown();
}

void SparkiPID::publishMessage(geometry_msgs::TwistStampedConstPtr twist) {
    if (m_node->ok()) {
        ROS_INFO("Publishing twist: %i", m_counter++);
        m_publisher.publish(twist);
    }
}
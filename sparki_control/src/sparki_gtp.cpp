//
// Created by carlh on 12/6/16.
//

#include <sparki_gtp.hpp>
#include <geometry_msgs/PointStamped.h>

using namespace SparkiControl;

void SparkiGTP::poseCallback(const geometry_msgs::PointStampedConstPtr& message) {
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

SparkiGTP::SparkiGTP() {
    ROS_INFO("Initializing SparkiGTP");
    m_counter = 0;
    m_node = new NodeHandle();
    ConnectSubscribers();
    AdvertisePublishers();
    ROS_INFO("SparkiGTP is ready");
}

SparkiGTP::~SparkiGTP() {
    ROS_INFO("Destroying the PID");
    DisconnectSubscribers(); // Probably don't need this?  I think it'll automatically unsubscribe when this goes out of scope.
    UnAdvertisePublishers();
    m_node->shutdown();
}

void SparkiGTP::ConnectSubscribers() {
    m_poseSubscriber = m_node->subscribe<geometry_msgs::PointStamped>("go_to_point", 10, &SparkiGTP::poseCallback, this);
}

void SparkiGTP::DisconnectSubscribers() {
    m_poseSubscriber.shutdown();
}

void SparkiGTP::AdvertisePublishers() {
    m_publisher = m_node->advertise<geometry_msgs::TwistStamped>("cmd_vel", 10);
}

void SparkiGTP::UnAdvertisePublishers() {
    m_publisher.shutdown();
}

void SparkiGTP::publishMessage(geometry_msgs::TwistStampedConstPtr twist) {
    if (m_node->ok()) {
        ROS_INFO("Publishing twist: %i", m_counter++);
        m_publisher.publish(twist);
    }
}
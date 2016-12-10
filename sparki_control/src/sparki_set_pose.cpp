//
// Created by carlh on 12/6/16.
//

#include <sparki_set_pose.hpp>
#include <PID.h>

using namespace SparkiControl;

static PID pid(0.01, 0.005, 0.00005);

void SparkiSetPose::poseCallback(const geometry_msgs::PoseStampedConstPtr& poseStamped) {
    ROS_INFO("Updating Pose\n");
    float err = pid.update(1);


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

SparkiSetPose::SparkiSetPose() {
    ROS_INFO("Initializing SparkiSetPose");
    m_counter = 0;
    m_node = new NodeHandle();
    ConnectSubscribers();
    AdvertisePublishers();
    ROS_INFO("SparkiSetPose is ready");
}

SparkiSetPose::~SparkiSetPose() {
    ROS_INFO("Destroying the PID");
    DisconnectSubscribers(); // Probably don't need this?  I think it'll automatically unsubscribe when this goes out of scope.
    UnAdvertisePublishers();
    m_node->shutdown();
}

void SparkiSetPose::ConnectSubscribers() {
    m_poseSubscriber = m_node->subscribe<geometry_msgs::PoseStamped>("set_pose", 10, &SparkiSetPose::poseCallback, this);
}

void SparkiSetPose::DisconnectSubscribers() {
    m_poseSubscriber.shutdown();
}

void SparkiSetPose::AdvertisePublishers() {
    m_publisher = m_node->advertise<geometry_msgs::TwistStamped>("cmd_vel", 10);
}

void SparkiSetPose::UnAdvertisePublishers() {
    m_publisher.shutdown();
}

void SparkiSetPose::publishMessage(geometry_msgs::TwistStampedConstPtr twist) {
    if (m_node->ok()) {
        ROS_INFO("Publishing twist: %i", m_counter++);
        m_publisher.publish(twist);
    }
}
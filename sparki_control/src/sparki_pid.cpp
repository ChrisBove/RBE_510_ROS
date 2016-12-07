//
// Created by carlh on 12/6/16.
//

#include <sparki_pid.hpp>

SparkiPID::SparkiPID(string name) {
    m_counter = 0;
    m_node = new NodeHandle("pid");
    m_publisher = m_node->advertise<geometry_msgs::Twist>(name+"/twist", 10);
}

void SparkiPID::publishMessage() {
    if (m_node->ok()) {
        ROS_INFO("Publishing twist: %i", m_counter++);
        geometry_msgs::Twist twistMessage;
        twistMessage.angular.x = 1.0;
        twistMessage.angular.y = 5.0;
        twistMessage.angular.z = 0.0;
        twistMessage.linear.x = 100;
        twistMessage.linear.y = 200;
        twistMessage.linear.z = 0;
        m_publisher.publish(twistMessage);
    }
}
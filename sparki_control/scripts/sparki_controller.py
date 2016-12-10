#!/usr/bin/env python

import rospy
from geometry_msgs.msg import TwistStamped


class SparkiController:
    def __init__(self):
        self.node = rospy.init_node('controller')
        rospy.Subscriber("cmd_vel", TwistStamped, self.callback)
        rospy.spin()

    def callback(self, data):
        rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.twist)

if __name__ == "__main__":
    try:
        cnt = SparkiController()
    except rospy.ROSInterruptException:
        pass

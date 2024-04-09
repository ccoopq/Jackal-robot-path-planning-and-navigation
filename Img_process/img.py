#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from geometry_msgs.msg import PoseStamped, TransformStamped, Pose
import tf2_ros
import tf2_geometry_msgs
import random
from std_msgs.msg import Int32

class ObjectDetector:
    def __init__(self):
        self.bridge = CvBridge()
        self.image_sub = rospy.Subscriber("/front/image_raw", Image, self.image_callback)
        self.map_frame = "map"
        self.robot_pose_sub = rospy.Subscriber("/me5413_world/pose_world_robot", Pose, self.robot_pose_callback)
        self.robot_pose = Pose()
        self.search_point_pub = rospy.Publisher("/search_world_goal", PoseStamped, queue_size=10)
        self.detect_flag_pub = rospy.Publisher("/detect_box_flag", Int32, queue_size=10)

    def image_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        except Exception as e:
            print(e)
        
        if  1 == 1 : # not detect! 
            # Publish origin point
                search_world_goal = PoseStamped()
                search_world_goal.header.stamp = rospy.Time.now()
                search_world_goal.header.frame_id = self.map_frame 
                search_world_goal.pose =  self.robot_pose
                self.search_point_pub.publish(search_world_goal)
                self.detect_flag_pub.publish(0)
        else :
            # object detection code
            object_boxes = [(100, 100, 50, 50)]

            for (x, y, w, h) in object_boxes:
                # Calculate object box center coordinates
                object_center_x = x + w / 2
                object_center_y = y + h / 2

                # Get image center coordinates
                image_center_x = cv_image.shape[1] / 2
                image_center_y = cv_image.shape[0] / 2

                # Calculate distance to center
                distance_to_center = np.sqrt((object_center_x - image_center_x)**2 + (object_center_y - image_center_y)**2)

                # Draw bounding box and center point on the image
                cv2.rectangle(cv_image, (x, y), (x + w, y + h), (0, 255, 0), 2)
                cv2.circle(cv_image, (int(object_center_x), int(object_center_y)), 5, (0, 0, 255), -1)

                # Display distance to center on the image
                # cv2.putText(cv_image, f"Distance to center: {distance_to_center}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

                # Display object box size on the image
                # cv2.putText(cv_image, f"Object box size: {w}x{h}", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

                # Generate search point
                search_world_goal = self.generateNewSearchPoint(object_center_x, object_center_y, w, h, cv_image)
                
                # Publish search point
                self.search_point_pub.publish(search_world_goal)
                self.detect_flag_pub.publish(1)

        # Show the image
        cv2.imshow("Image", cv_image)
        cv2.waitKey(1)

    def robot_pose_callback(self, msg):
        self.robot_pose = msg

    def generateNewSearchPoint(self, object_center_x, object_center_y, w, h, cv_image):
        search_world_goal = PoseStamped()
        search_world_goal.header.stamp = rospy.Time.now()
        search_world_goal.header.frame_id = self.map_frame

        # Get robot pose
        robot_pose = self.robot_pose

        # Set default search point position and orientation based on robot position
        search_world_goal.pose.position.x = robot_pose.position.x
        search_world_goal.pose.position.y = robot_pose.position.y
        search_world_goal.pose.position.z = robot_pose.position.z
        search_world_goal.pose.orientation = robot_pose.orientation

        # Adjust x based on object box size
        threshold_area = 200*200
        if w * h < threshold_area:
            search_world_goal.pose.position.x += 0.5  # Adjust x by a small value if object box size is small
            # Adjust y based on object box center position
            if object_center_x > cv_image.shape[1] / 2:
                search_world_goal.pose.position.y -= (object_center_x - cv_image.shape[1] / 2) / 100  # Adjust y based on deviation from center
            else:
                search_world_goal.pose.position.y += (cv_image.shape[1] / 2 - object_center_x) / 100

        return search_world_goal

def main():
    rospy.init_node('object_detector', anonymous=True)
    od = ObjectDetector()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down")
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()

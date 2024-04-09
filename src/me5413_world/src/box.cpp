#include <iostream>
#include <string>
#include <vector>

#include <ros/ros.h>
#include <ros/console.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TransformStamped.h>

#include <tf2/convert.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <visualization_msgs/MarkerArray.h>

class BoxGoalPublisher {
public:
    BoxGoalPublisher() : tf2_listener_(tf2_buffer_)
    {
        sub_goal_name_ = nh_.subscribe("/rviz_panel/goal_name", 1, &BoxGoalPublisher::goalNameCallback, this);
        pub_goal_ = nh_.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1);
        sub_box_markers_ = nh_.subscribe("/gazebo/ground_truth/box_markers", 1, &BoxGoalPublisher::boxMarkersCallback, this);
        sub_robot_odom_ = nh_.subscribe("/gazebo/ground_truth/state", 1, &BoxGoalPublisher::robotOdomCallback, this);
    }

    void goalNameCallback(const std_msgs::String::ConstPtr& msg) {
        std::string goal_name = msg->data;
        std::string goal_type = goal_name.substr(0, 3); // Assuming goal_type is first 3 characters
        int goal_box_id = std::stoi(goal_name.substr(3, 1)); // Assuming box_id is single digit after goal_type
        
        if (goal_type == "box") {
            geometry_msgs::PoseStamped P_world_goal;
            if (goal_box_id <= box_poses_.size()) {
                P_world_goal = box_poses_[goal_box_id - 1];
                pose_world_goal_ = P_world_goal.pose;

                // Get the Transform from world to map from the tf_listener
                geometry_msgs::TransformStamped transform_map_world;
                try
                {
                    transform_map_world = tf2_buffer_.lookupTransform(map_frame_, world_frame_, ros::Time(0));
                }
                catch (tf2::TransformException& ex)
                {
                    ROS_WARN("%s", ex.what());
                    return;
                }

                // Transform the goal pose to map frame
                geometry_msgs::PoseStamped P_map_goal;
                tf2::doTransform(P_world_goal, P_map_goal, transform_map_world);
                P_map_goal.header.stamp = ros::Time::now();
                P_map_goal.header.frame_id = map_frame_;
                // Publish the goal
                pub_goal_.publish(P_map_goal);
            } else {
                ROS_WARN("Goal box ID %d exceeds available boxes", goal_box_id);
            }
        } else {
            ROS_WARN("Unknown goal type: %s", goal_type.c_str());
        }
    }

    void boxMarkersCallback(const visualization_msgs::MarkerArray::ConstPtr& box_markers)
    {
        if (box_markers->markers.empty()) {
            ROS_WARN("No box markers received");
            return;
        }
        box_poses_.clear();
        for (const auto& box : box_markers->markers)
        {
            geometry_msgs::PoseStamped pose;
            pose.pose = box.pose;
            box_poses_.emplace_back(pose);
        }
    };

    void robotOdomCallback(const nav_msgs::Odometry::ConstPtr& odom)
    {
        if (!odom) {
            ROS_WARN("Empty odometry message received");
            return;
        }
        world_frame_ = odom->header.frame_id;
    };

private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_goal_name_;
    ros::Publisher pub_goal_;
    ros::Subscriber sub_box_markers_;
    ros::Subscriber sub_robot_odom_;
    std::vector<geometry_msgs::PoseStamped> box_poses_;
    geometry_msgs::PoseStamped P_map_goal; // Define your goal pose here
    geometry_msgs::Pose pose_world_goal_;
    std::string world_frame_ = "world";
    std::string map_frame_ = "map";
    tf2_ros::Buffer tf2_buffer_;
    tf2_ros::TransformListener tf2_listener_;
};

int main(int argc, char **argv) {
    ros::init(argc, argv, "box");
    BoxGoalPublisher box;
    ros::spin();
    return 0;
}

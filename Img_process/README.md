////////////////////////////////////////////////////
//////////////////    Vision Part    //////////////////
///////////////////////////////////////////////////

================= Step1. ==================== 
When a goal is detected as a box, the function geometry_msgs::PoseStamped GoalPublisherNode::generateNewSearchPoint() is called.
------------Below is the corresponding pseudocode-------------
Function searchForNextTarget() {
  Initialize start_goal with a predefined position and orientation in the map frame;
  Calculate the error between the robot's current pose and start_goal;

  If the error is large and the robot hasn't reached the starting point:
    Return start_goal;

  Otherwise:
    If it's the first time searching:
      Generate a new search point;
    
    If the robot has found the target box:
      Return the path to the box;
    
    Otherwise:
      If the robot hasn't reached the current search point:
        Return the current search point;
      Else:
        Generate a new search point and return it;
}

Here, the random point generation function geometry_msgs::PoseStamped GoalPublisherNode::generateNewSearchPoint() is called, which randomly generates a search point within a certain range. When the car automatically navigates to this point, the next search point is generated automatically until the car's camera detects the target box's ID.


================= Step2. ===================== 
The topic /front/camera_raw published by the car's camera will be subscribed by the img.py program (python-ros), where digit detection is executed.

================= Step3. =====================
Digit detection occurs in the def image_callback(self, msg) function, which obtains the area and center coordinates of the target object box. Then, the self.generateNewSearchPoint(object_center_x, object_center_y, w, h, cv_image) function is called. This function automatically generates a PoseStamped type search point based on the information of the object box and broadcasts it to the C++ main program through the topic.

---------------Below is the core segment in generateNewSearchPoint()--------------
// Set the search point's position and orientation based on the robot's position
  // Adjust the x-coordinate based on the object box size
  // If box size is smaller than the  threshold, it means the camera is far from the target, thus move forward
  // Else, the camera is near enough to the targer, which means it already reach the goal point
  threshold_area = 200 * 200
  if w * h < threshold_area {
    // Adjust x by a small value if the object box size is small
    search_world_goal.position.x += 0.5
    
    // Adjust y based on the object box center position
    if object_center_x > cv_image.width / 2 {
      // Adjust y based on deviation from the center
      search_world_goal.position.y -= (object_center_x - cv_image.width / 2) / 100
    } else {
      search_world_goal.position.y += (cv_image.width / 2 - object_center_x) / 100
    }
  }
}


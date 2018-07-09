#include <ros/ros.h>
#include <std_msgs/Int32.h>

void subCB(const std_msgs::Int32ConstPtr& ptr){
    ROS_INFO("got : %d", ptr->data);
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "simple_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("simple_pub_msgs", 10, subCB);

    ros::spin();
}
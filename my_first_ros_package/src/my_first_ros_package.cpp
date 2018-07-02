#include <ros/ros.h>

int main(int argc, char *argv[]){
    ros::init(argc, argv, "my_first_ros_package");
    ros::NodeHandle nh;

    ros::Rate loop_rate(10); //10hz
    while(true){
        ROS_INFO("Hello World!");
        loop_rate.sleep();
    }
    return 0;
}

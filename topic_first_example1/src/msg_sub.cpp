#include <ros/ros.h>
#include "topic_first_example1/encoder_speed.h"

ros::Time last_time;
double distance = 0;

void encoder_speed_CB(const topic_first_example1::encoder_speedConstPtr& ptr){
    //calc distance 
    ros::Time cur_time = ros::Time::now();
    double dt = (cur_time - last_time).toSec();
    last_time = cur_time;
    distance += ptr->speed * dt;

    ROS_INFO("frame_id : %s", ptr->header.frame_id.c_str());
    ROS_INFO("time : %d(s)",ptr->header.stamp.sec);
    ROS_INFO("seq : %u", ptr->header.seq);
    ROS_INFO("speed : %d", ptr->speed);
    ROS_INFO("driving distance : %lf", distance);
    ROS_INFO("==================");
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "msg_sub");
    ros::NodeHandle nh;

    last_time = ros::Time::now();
    ros::Subscriber sub = nh.subscribe("msg_pub", 10, encoder_speed_CB);
    ros::spin();


}
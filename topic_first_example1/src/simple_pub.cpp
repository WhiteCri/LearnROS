#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char *argv[]){
    ros::init(argc, argv, "simple_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("simple_pub_msgs", 10);
    std_msgs::Int32 msg;
    msg.data = 1;
    
    ros::Rate loop_rate(10);

    while(true){
        pub.publish(msg);
        msg.data = -msg.data;
        loop_rate.sleep();
    }
}
#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char *argv[]){
    ros::init(argc, argv, "simple_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("simple_pub_msgs", 10);
    std_msgs::Int32 msg;
    msg.data = 1;
    
    int frequency;
    nh.param("/frequency", frequency, 10);
    ros::Rate loop_rate(frequency);

    while(true){
        pub.publish(msg);
        msg.data = -msg.data;
        loop_rate.sleep();
    }
}
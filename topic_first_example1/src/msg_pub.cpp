#include <ros/ros.h>
#include <cstdlib>
#include <topic_first_example1/encoder_speed.h>

int main(int argc, char *argv[]){
    ros::init(argc, argv, "msg_pub");
    ros::NodeHandle nh;
    srand((unsigned)time(NULL));

    ros::Publisher pub = nh.advertise<topic_first_example1::encoder_speed>("msg_pub", 10);
    topic_first_example1::encoder_speed msg;
    size_t seq = 0;

    ros::Rate loop_rate(10);
    while(true){
        msg.header.stamp = ros::Time::now();
        msg.header.seq = seq++;
        msg.header.frame_id = "base_link";

        msg.speed = rand() % 11;
        pub.publish(msg);

        loop_rate.sleep();
    }
}
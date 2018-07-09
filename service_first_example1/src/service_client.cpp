#include <ros/ros.h>
#include <service_first_example1/simple_srv.h>

int main(int argc, char *argv[]){
    if(argc < 3) {
        ROS_WARN("Usage : %s [num1] [num2]", argv[0]);
        return -1;
    }
    ros::init(argc, argv, "service_client");
    ros::NodeHandle nh;

    ros::ServiceClient cli = nh.serviceClient<service_first_example1::simple_srv>
        ("simple_service_msg");
    
    service_first_example1::simple_srv msg;
    msg.request.a = atoi(argv[1]);
    msg.request.b = atoi(argv[2]);
    ROS_INFO("make a request - a, b: %d %d", msg.request.a, msg.request.b);

    if (cli.call(msg)){
        ROS_INFO("got response : %d", msg.response.result);
    }
    else{
        ROS_WARN("falied to get a response");
    }
    
}
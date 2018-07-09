#include <ros/ros.h>
#include <service_first_example1/simple_srv.h>

bool Server_add(service_first_example1::simple_srv::Request& req,
    service_first_example1::simple_srv::Response& res){
        ROS_INFO("got request a, b : %d %d",req.a, req.b);
        res.result = req.a + req.b;

        return true;
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "simple_server");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("simple_service_msg", 
        Server_add);
    ROS_INFO("run server!");
    ros::spin();
    return 0;

}
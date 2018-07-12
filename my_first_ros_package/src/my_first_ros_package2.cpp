#include <ros/ros.h>
#include <deque>

int main(int argc, char *argv[]){
    ros::init(argc, argv, "my_first_ros_package");
    ros::NodeHandle nh;

    ros::Rate loop_rate(10); //10hz
    
    std::deque<int> ary{1, 1, 2, 3};
    while(true){
        ROS_INFO("ary[0] : %d, ary[1] : %d, ary[2] : %d, ary[3] : %d", 
            ary[0], ary[1], ary[2], ary[3]);        
        // int next = ary[0] + ary[1];
        // ary[0] = ary[1];
        // ary[1] = next;

        // next = ary[2] + ary[3];
        // ary[2] = ary[3];
        // ary[3] = next;
        ary.push_back(ary[2] + ary[3]);
        ary.pop_front();
        loop_rate.sleep();
    }
    return 0;
}

#include "ros/ros.h"                        //使用ros必須要加此標頭檔
#include "std_msgs/String.h"                //你要使用的msg檔案
#include <sstream>
int main(int argc, char **argv){
ros::init(argc, argv, "talker");          //node名稱定義
ros::NodeHandle n;                        //nodehandle名稱定義
                                         
ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000); //pub定義
ros::Rate loop_rate(10);

int count = 0;
    while (ros::ok()){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(msg);//此行將訊息發布，括號內格式須與ros::publisher定義的相同
        ros::spinOnce();         //此行執行所有callback
        loop_rate.sleep();
        ++count;
    }
    return 0;
}

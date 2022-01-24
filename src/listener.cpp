#include "ros/ros.h"                    //使用ros必須要加此標頭檔
#include "std_msgs/String.h"            //你要使用的msg檔案

void chatterCallback(const std_msgs::String::ConstPtr& msg){                                   //callback function
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv){

  ros::init(argc, argv, "listener");    //node名稱定義
  ros::NodeHandle n;                    //nodehandle名稱定義
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);//subscriber定義
  ros::spin();                          //將程式固定在此行，並重複執行所有callback
  return 0;
}

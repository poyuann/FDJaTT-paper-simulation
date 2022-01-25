#include "ros/ros.h"                    //使用ros必須要加此標頭檔
#include "geometry_msgs/Point.h"            //你要使用的msg檔案

void posCallback(const geometry_msgs::Point::ConstPtr& msg){                                   //callback function
  ROS_INFO("uav pos: [%f,%f,%f]", msg->x,msg->y,msg->z);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "uav_sub");    //node名稱定義
  ros::NodeHandle n;                    //nodehandle名稱定義
  ros::Subscriber sub = n.subscribe("uav_pos", 1000, posCallback);//subscriber定義
  ros::spin();                          //將程式固定在此行，並重複執行所有callback
  return 0;
}
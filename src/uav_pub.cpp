#include "ros/ros.h"                        //使用ros必須要加此標頭檔
#include "geometry_msgs/Point.h"                //你要使用的msg檔案



int main(int argc, char **argv){
    ros::init(argc, argv, "uav_pub");          //node名稱定義
    ros::NodeHandle n;                        //nodehandle名稱定義
                                            
    ros::Publisher pos_pub = n.advertise<geometry_msgs::Point>("uav_pos", 1000); //pub定義

    ros::NodeHandle nh;
    int param = 1;
    nh.getParam("/param_name", param);
    ros::Rate loop_rate(param);

    geometry_msgs::Point msg;
    msg.x = 0.0;
    msg.y = 0.0;
    msg.z = 0.0;
    while (ros::ok()){
        msg.x +=1;
        msg.y -=1;
        msg.z +=1;
        pos_pub.publish(msg);//此行將訊息發布，括號內格式須與ros::publisher定義的相同
        ros::spinOnce();         //此行執行所有callback
        loop_rate.sleep();
    }
    return 0;
}

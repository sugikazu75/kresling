#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String pub_msg;
ros::Publisher pub("publisher", &pub_msg);

void subscriberCallback(const std_msgs::String& msg){
  pub_msg.data = msg.data;
  pub.publish( &pub_msg );
}

ros::Subscriber<std_msgs::String> sub("subscriber", &subscriberCallback);

void setup()
{
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();

  nh.logdebug("Debug Statement");
  delay(500);
  nh.loginfo("Program info");
  delay(500);
  nh.logwarn("Warnings.");
  delay(500);
  nh.logerror("Errors..");
  delay(500);
  nh.logfatal("Fatalities!");
  delay(500);
}
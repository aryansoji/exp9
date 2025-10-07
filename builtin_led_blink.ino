#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle nh;

const int led_pin = 13; // Built-in LED
bool led_state = LOW;

void messageCb(const std_msgs::Empty& toggle_msg){
  led_state = !led_state; // Toggle the state
  digitalWrite(led_pin, led_state);
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb);

void setup() {
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, led_state);
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
  delay(100);
}

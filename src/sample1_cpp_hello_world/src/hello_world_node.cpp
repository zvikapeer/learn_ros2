#include <memory>
#include "rclcpp/rclcpp.hpp"

class HelloWorldNode : public rclcpp::Node
{
public:
  HelloWorldNode()
  : Node("hello_world_node")
  {
    RCLCPP_INFO(this->get_logger(), "Hello, ROS2 Lyrical! Node has started.");

    // Create a timer that fires every 1 second
    timer_ = this->create_wall_timer(
      std::chrono::seconds(1),
      std::bind(&HelloWorldNode::timer_callback, this));
  }

private:
  void timer_callback()
  {
    RCLCPP_INFO(this->get_logger(), "Hello World! - ROS2 Lyrical");
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloWorldNode>());
  rclcpp::shutdown();
  return 0;
}


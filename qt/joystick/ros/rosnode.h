#ifndef ROS_NODE_H
#define ROS_NODE_H

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "project_type.h"

using stringMsg = example_interfaces::msg::String;
using twistMsg  = geometry_msgs::msg::Twist;

class RosNode: public QObject , public rclcpp::Node{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
public:
    RosNode();
    ~RosNode();
    QString getName() const;
    void setName(const QString &newName);
    void setJoyName(const stringMsg::SharedPtr msg);
    Q_INVOKABLE void buttonCallback(int number);
    Q_INVOKABLE void ballStateCallback(int x, int y);
signals:
    void nameChanged();
private:
    rclcpp::Subscription<stringMsg>::SharedPtr  joy_name_sub;
    rclcpp::Publisher<stringMsg>::SharedPtr button_pub;
    rclcpp::Publisher<twistMsg>::SharedPtr ball_pub;

    void rosSpin();
    std::thread spin_thread;
    std::string joy_name;
    QString name;
};
#endif

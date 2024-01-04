#include <iostream>
#include <string>
#include <gz/msgs.hh>
#include <gz/transport.hh>
void cb(const gz::msgs::StringMsg &_msg)
{
  std::cout << "Msg: " << _msg.data() << std::endl << std::endl;
}
int main(int argc, char **argv)
{
  gz::transport::Node node;
  std::string topic = "/foo";
  // Subscribe to a topic by registering a callback.
  if (!node.Subscribe(topic, cb))
  {
    std::cerr << "Error subscribing to topic [" << topic << "]" << std::endl;
    return -1;
  }
  // Zzzzzz.
  gz::transport::waitForShutdown();
  return 0;
}
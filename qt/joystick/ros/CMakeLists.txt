find_package(rclcpp REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)

add_library(ros_node rosnode.cpp rosnode.h)

target_link_libraries(ros_node ${PROJECT_NAME} mylibs)
target_include_directories(ros_node PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
ament_target_dependencies(ros_node rclcpp std_msgs example_interfaces geometry_msgs )
target_include_directories(ros_node PUBLIC ${PROJECT_SOURCE_DIR}/inc)

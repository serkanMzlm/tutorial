cmake_minimum_required(VERSION 3.12)
project(MAVlinkComm)

list(APPEND CMAKE_PREFIX_PATH "/home/serkan/source_code/example_code/mavlink/install")
find_package(MAVLink REQUIRED)

add_executable(client client.cpp)
add_executable(server server.cpp)
add_executable(publisher publisher.cpp)
add_executable(subscriber subscriber.cpp)

target_link_libraries(client PUBLIC MAVLink::mavlink)
target_link_libraries(server PUBLIC MAVLink::mavlink)
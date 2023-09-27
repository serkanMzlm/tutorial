## ROS2 HUMBLE
- Baket Oluşturma: `--dependencies` kısmından sonra yazılan paketler sisteme eklenmesi sağlanır. 
    - `RCL` Ros Client Library.
```
ros2 pkg create --build-type  ament_cmake  cpp_node --dependencies rclcpp
ros2 pkg create --build-type  ament_python cpp_node --dependencies rclpy
```
- Kodlarda yazılan `RCLCPP_DEBUG` kısımları sadece parametre olarak bu kısımların gözükmesini istediğinizde ekranda görüntülenir.
```
ros2 run [pkg] [executable_file] --ros-args --log-level debug      (Bütün pakette bulunan)
ros2 run [pkg] [executable_file] --ros-args --log-level [node_name]:=debug  (Sadece belirli bir node)
```
- ROS2'da kullandığımız `RCLCPP_DEBUG, RCLCPP_INFO, RCLCPP_WARN, RCLCPP_ERROR` komut çıktılarını ekranda görürken aynı zamanda bilgisayarda `~/.ros/log` klasörünede yazılır.
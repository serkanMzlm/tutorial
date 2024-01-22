## Tutorial

### Table of Contents

- C
- C++
- CMake
- Python
- Linux (Bash)
- Matlab
- ROS2
- Gazebo
- QT
- IPC (Inter Process Commonication)
- Serial
- MAVLink
- gstreamer

---

### C++

- The appearance of outputs for packages with loading bars

  - `loading_bar_1.cpp`
    ![image_1](images/loadbar_1.png)
  - `loading_bar_2.cpp`
    ![image_2](images/loadbar_2.png)
  - `loading_bar_3.cpp`
    ![image_3](images/loadbar_3.png)
  - `loading_bar_color_1.cpp`
    ![image_4](images/loadbar_color_y_1.png)
    ![image_4](images/loadbar_color_r_1.png)
    ![image_4](images/loadbar_color_g_1.png)
  - `loading_bar_color_2.cpp`
    ![image_4](images/loadbar_color_r_2.png)
    ![image_4](images/loadbar_color_y_2.png)
    ![image_4](images/loadbar_color_g_2.png)

- The code `g++ -o yaml_parser yaml_parser.cpp -lyaml-cpp` is used in the build process of packages that read data from YAML files
- To align the specified texts on the same lines, use the content of write_on_the_same_line.cpp code
```
\033[B     Move the cursor one lines down
\033[2B    Move the cursor two lines down
 
\033[A      Move the cursor one lines up
\033[2A     Move the cursor one lines up
``` 



```
#!/bin/bash
var="$(xxd -ps /sys/class/i2c-adapter/i2c-1/of_node/clock-frequency)"
var=${var//[[:blank:].\}]/}

```

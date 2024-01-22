## GSTREAMER

> **basic_tutorial_1.c:** For GStreamer, hello world

> **basic_tutorial_2.c:** Source - sink - pipeline

> **basic_tutorial_3.c:** Demuxer: Audio and video were separated.

> **basic_tutorial_4.c:** Time management

> **basic_tutorial_5.c:** GUI toolkit integration

> **basic_tutorial_6.c:** Media formats and Pad Capabilities `gst-inspect-1.0`

> **basic_tutorial_7.c:** Multithreading and Pad Availability

> **basic_tutorial_8.c:** Short-cutting the pipeline

> **basic_tutorial_9.c:** Multithreading and Pad Availability

> **basic_tutorial_10.c:** Multithreading and Pad Availability


### Build
```
gcc [code_file].c -o main `pkg-config --cflags --libs gstreamer-1.0`
```

### Error Resolutions
- **fatal error:** gtk/gtk.h: No such file or directory `#include <gtk/gtk.h>`
```
sudo apt update
sudo apt upgrade
sudo apt install sudo apt-get install libgtk-3-dev
```
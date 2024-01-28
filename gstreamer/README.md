## GSTREAMER

### Basic:
> **tutorial_1.c:** For GStreamer, hello world

> **tutorial_2.c:** Source - sink - pipeline

> **tutorial_3.c:** Demuxer: Audio and video were separated.

> **tutorial_4.c:** Time management

> **tutorial_5.c:** GUI toolkit integration

> **tutorial_6.c:** Media formats and Pad Capabilities `gst-inspect-1.0`

> **tutorial_7.c:** Multithreading and Pad Availability

> **tutorial_8.c:** Short-cutting the pipeline

> **tutorial_9.c:** Media information gathering

> **tutorial_10.c:** Streaming

> **tutorial_11.c:** Playback speed

> **tutorial_12.c:** Streaming


### Playback

> **tutorial_1.c:** Playbin usage

> **tutorial_2.c:** Subtitle management

> **tutorial_3.c:** Short-cutting the pipeline

> **tutorial_4.c:** Progressive streaming

> **tutorial_5.c:** Color Balance

> **tutorial_6.c:** Audio visualization

> **tutorial_7.c:** Custom playbin sinks


### Build

```
gcc [code_file].c -o main `pkg-config --cflags --libs gstreamer-1.0`
```

### Error Resolutions

- **fatal error:** gtk/gtk.h: No such file or directory `#include <gtk/gtk.h>`

```
sudo apt update
sudo apt upgrade
sudo apt install libgtk-3-dev
```

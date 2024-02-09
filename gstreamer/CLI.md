# Örnek Gstreamer Terminal Kodları
- Kamera -> UDP (jpeg)
```bash 
gst-launch-1.0 v4l2src device=/dev/video0 ! 'video/x-raw' ! videoconvert ! jpegenc ! rtpjpegpay ! udpsink host=10.223.6.6 port=3000
```

- Kamera -> UDP (h265)
```bash
gst-launch-1.0 v4l2src device=/dev/video0 ! 'video/x-raw' ! decodebin ! videoconvert ! x264enc tune=zerolatency ! rtph264pay ! udpsink host=10.223.6.6 port=5000
```
```bash
gst-launch-1.0 v4l2src device=/dev/video0 ! 'video/x-raw' ! videoconvert ! nvvidconv ! 'video/x-raw(memory:NVMM), format=NV12' ! nvv4l2h265enc ! h265parse ! rtph265pay config-interval=1 pt=96 ! udpsink host=192.168.20.116 port=3000
```
```bash
gst-launch-1.0 -v v4l2src device=/dev/video0 ! image/jpeg, width=640, height=480, framerate=30/1 !  queue ! jpegdec ! nvvidconv ! 'video/x-raw(memory:NVMM),format=NV12' ! nvv4l2h265enc bitrate=4000000 ! h265parse ! rtph265pay config-interval=1 pt=96 ! udpsink host=192.168.20.116 port=3000
```

- UPD(jpeg) -> Ekran
```bash
gst-launch-1.0 udpsrc port=3000 ! application/x-rtp, encoding-name=JPEG,payload=26 ! rtpjpegdepay ! jpegdec ! autovideosink
```

- UDP (h265) -> Ekran
```bash
gst-launch-1.0 udpsrc port=5000 ! application/x-rtp,media=video,clock-rate=90000,encoding-name=H264,payload=96 ! rtph264depay ! avdec_h264 ! autovideosink
```

- SIYI kamera RTSP -> ekran
```bash
gst-launch-1.0 rtspsrc location=rtsp://192.168.144.25:8554/main.264 latency=100 ! decodebin ! autovideosink
```
```bash
gst-launch-1.0 -v rtspsrc location=rtsp://192.168.144.25:8554/main.264 latency=100 ! decodebin ! autovideosink # -v çıktının daha detaylı olmasını dağlar.
```

```bash
gst-launch-1.0 rtspsrc location=rtsp://192.168.144.25:8554/main.264 ! rtph265depay ! h265parse ! avdec_h265  ! autovideosink
```

- RTSP -> UDP
```bash
gst-launch-1.0 rtspsrc location=rtsp://192.168.144.25:8554/main.264  latency=50 ! udpsink host=10.223.6.6 port=3000
```

```bash
gst-launch-1.0 rtspsrc location=rtsp://192.168.144.25:8554/main.264 latency=100 ! decodebin ! videoconvert ! video/x-raw,format=I420 ! udpsink host=10.223.6.6 port=5000
```

- RTSP -> UDP (jpeg)
    - dec_h265 yerine avdec_h265 yazılabilir.
```bash
gst-launch-1.0 rtspsrc location=rtsp://192.168.144.25:8554/main.264 latency=100  ! rtph265depay ! h265parse ! dec_h265 ! videoconvert ! jpegenc ! rtpjpegpay ! udpsink host=10.223.6.6 port=3000
```

```bash
gst-launch-1.0 rtspsrc location=rtsp://192.168.144.25:8554/main.264 latency=100 ! decodebin ! videoconvert ! video/x-raw,format=I420 ! videoconvert ! jpegenc ! rtpjpegpay ! udpsink host=10.223.6.6 port=3000
```

```bash
gst-launch-1.0 rtspsrc location=rtsp://192.168.144.25:8554/main.264  latency=10 ! rtph265depay ! h265parse ! avdec_h265 ! videoconvert ! nvvidconv ! 'video/x-raw(memory:NVMM),format=NV12' ! nvv4l2h265enc ! h265parse ! rtph265pay config-interval=1 pt=96 ! udpsink host=10.223.6.6 port=3000
```
- Bitrate ayrası sayesinde veri boyutu azaltılır.
```bash
gst-launch-1.0 rtspsrc location=rtsp://192.168.144.25:8554/main.264  latency=10 ! rtph265depay ! h265parse ! avdec_h265 ! videoconvert ! queue  ! nvvidconv ! 'video/x-raw(memory:NVMM),format=NV12' ! nvv4l2h265enc bitrate=600000 ! h265parse ! rtph265pay config-interval=1 pt=96 ! udpsink host=10.223.6.6 port=3000
```

```bash
gst-launch-1.0 rtspsrc location=rtsp://192.168.144.25:8554/main.264  latency=1 ! rtph265depay ! h265parse ! avdec_h265 !  nvvidconv ! 'video/x-raw(memory:NVMM),width=1280,height=720' ! nvv4l2h264enc  bitrate=600000 insert-sps-pps=1 idrinterval=15 ! h264parse ! rtph264pay config-interval=1 pt=96 ! udpsink host=10.223.9.9 port=3000 sync=false async=false
```
## GSTREAMER
- `gst-inspect-1.0 [ELEMENT]` öğe sınıflarını ve öğe plugin'lerini incelemek ve hakkında bilgi almak için kullanılır.
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


## Genel Bilgiler

---

GStreamer, çoklu ortam işleme çerçevesidir ve ses, video ve diğer multimedya verilerini işlemek, kodlamak, dönüştürmek ve akış oluşturmak için kullanılan bir yazılım kütüphanesidir.

**Elements:** Medya işleme işlevselliğini sağlayan temel yapı taşlarıdır. Bu öğeler, medya dosyalarını okumak, kodlamak, dönüştürmek, sesi işlemek, videoyu oynatmak gibi çeşitli görevleri yerine getirir.

![bin-element.png](image/bin-element.png)

**Pad:** Öğeler arasındaki veri akışı pad'lar aracılığıyla gerçekleşir. Pads, öğeler arasındaki bağlantıları ve veri akışını tanımlar. Bir pad, bir öğenin işlevselliğini ve rolünü belirler. Örneğin, bir öğe genellikle giriş pad'ına veri alır ve çıkış pad'ından veri gönderir.

**GstQuery:** Verinin sorgulanmasını sağlar.

**`gst-discoverer-1.0` :** GStreamer Multimedya Çerçevesi'nde medya dosyalarının özelliklerini ve içeriğini keşfetmek için kullanılan bir araçtır.

```bash
# Terminal üzerinden c dosyasını build etmek için kullanılan komutlar.
gcc main.c -o main `pkg-config --cflags --libs gstreamer-1.0`
gcc main.c -o main `pkg-config --cflags --libs gtk+-3.0 gstreamer-1.0`
#Bu komut sayesinde  parametreleri öğreniriz.
gst-inspect nvarguscamerasrc 
 
gst-discoverer-1.0  rtsp://192.168.144.25:8554/main.264
```

- source -> filter -> sink şeklinde kodlaması yapılır.
- `gst-launch-1.0 videotestsrc ! ximagesink` doğru bir şekilde kullanıldığını göstermek için kullanılır.
- `sudo service nvargus-daemon restart` Kamera servisini resetlememizi sağlar.
- `v4l2-ctl --list-devices` Bağlı olan çihazları listeler
- `v4l2-ctl -d /dev/video0 --all` Belirtilen çihaz hakkında detaylı bilgi verir.
- `v4l2-ctl -d /dev/video0 --list-formats-ext` En temel ve anlaşılır bilgilerini gösterir.
- `export DISPLAY=:0` ssh ile doğrudan bilgisayarda yazılamadığı durumlarda kullanılır.

## C

---

- **`gst_init` :** GStreamer'ı başlatmak ve kullanılabilir eklentileri yüklemek için kullanılan işlevdir.
- **`gst_parse_launch`** : Bir GStreamer pipeline'ını bir metin dizisi olarak tanımlayarak ve bu metni yürütülür bir hale getirerek bir GStreamer pipeline'ını oluşturmayı sağlayan bir işlevdir. Pipeline kısa olduğu durumlarda kullanılışlıdır.
    - `playpin`: medya dosyalarını oynatmak için kullanılan basit ve etkili bir araçtır ve GStreamer'da oynatma işlevselliğini hızlı ve kolay bir şekilde uygulamanıza olanak tanır.

```c
gst_init(&argc, &argv);
pipeline = gst_parse_launch("playbin uri=https://gstreamer.freedesktop.org/data/media/sintel_trailer-480p.webm", NULL);
```

- **`gst_element_set_state`** : Bir GStreamer elementinin durumunu değiştirmek için kullanılan işlevdir. GStreamer'da bir medya akışının oynatılması veya durdurulması gibi çeşitli durumları yönetmek için kullanılır.
    - `GST_STATE_NULL`, Elementin kaynakları serbest bırakılmış ve tüm kaynaklar silinmiştir. Yani, bu durum, bir elementin henüz oluşturulmadığı veya kullanılmadığı anlamına gelir.
    - `GST_STATE_READY`, element hazır durumdadır ancak henüz çalışma zamanı kaynakları kullanmamaktadır. Yani, elementin gerekli başlangıç ayarları yapılmıştır ve başlamaya hazırdır.
    - `GST_STATE_PAUSED`, elementin işleme akışı duraklatılmıştır. Veri akışı hala mevcut olabilir, ancak işleme geçici olarak durdurulmuştur
    - `GST_STATE_PLAYING`, elementin işleme akışı aktif ve çalışıyor demektir. Veri akışı işlenir ve gerektiğinde çıktı oluşturulur.

```c
gst_element_set_state (pipeline, GST_STATE_PLAYING);
```

- **`gst_element_get_bus`** : Bir GStreamer elementinin olayları ve mesajları yakalamak için kullanılan bir iletişime erişim sağlar.
- **`gst_bus_timed_pop_filtered`** : GStreamer iletişimi belirli bir süre boyunca veya bir hata oluşuncaya kadar belirli bir türdeki olayları veya mesajları almak için kullanılır. İlk parametre olarak pipeline hattı ikinci parametre ise ne kadar süre çalışaçağını belirler.

```c
bus = gst_element_get_bus(pipeline);
gst_bus_timed_pop_filtered(bus,GST_CLOCK_TIME_NONE,GST_MESSAGE_ERROR)
gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,GST_MESSAGE_ERROR | GST_MESSAGE_EOS)
/*
GST_CLOCK_TIME_NONE bir hata oluşana kadar çalışır. Bu kısımda direkt süre girilebilir. 
*/
```

- **`gst_message_unref`** : GStreamer mesajı için ayrılmış belleği serbest bırakır.
- **`gst_object_unref`** : GStreamer nesnesi için ayrılmış belleği serbest bırakır.
- **`gst_object_unref`** : GStreamer pipeline'ı için ayrılan belleği serbest bırakır.

```c
gst_message_unref (msg);
gst_object_unref (bus);
gst_element_set_state (pipeline, GST_STATE_NULL);
gst_object_unref (pipeline);
```

- **`gst_element_factory_make`** : Belirli bir elementin bir örneğini oluşturmak için kullanılan bir işlevdir. İlk parametre oluşturulucak öğenin türüdür. İkinci parametre ise oluşturulan öğeye verilicek isimdir.

```c
source = gst_element_farctory_make("nvarguscamerasrc","source");
sink = gst_element_farctory_make("autovideosink","sink");
```

- **`gst_pipeline_new`** : İşlevi, yeni bir pipeline oluşturur ve bu pipeline'ın başlatılması ve işlenmesi için gerekli temel ayarları yapar.
- `gst_bin_add_many` : Elementleri ardışık düzende eklemek için kullanılır. Elementleri ekleme sırası önemlidir. İşlevin sona ermesini belirtmek için son parametre olarak **`NULL`** kullanılır.
- `gst_element_link` : Elementlerin birbiriyle bağlantı kurmasını sağlar.

```c
pipeline = gst_pipeline_new(" pipeline_1");	
gst_bin_add_many (GST_BIN (pipeline), source, sink, NULL);
if (gst_element_link (source, sink) != TRUE) {
    g_printerr ("Elements could not be linked.\n");
    gst_object_unref (pipeline);
    return -1;
}
```

- **`g_object_set` :** GObject tabanlı bir nesnenin özelliklerini ayarlamak için kullanılan bir işlevidir. Son paramatre `NULL`  olmak zorundadır.
- **`gst_object_get` :** Bir GStreamer nesnesinin belirli bir özelliğini almak için kullanılan bir işlevdir.

```c
g_object_set(sink, "host", "10.223.20.20",NULL);
g_object_set(sink, "port", 5000,NULL);

/* Bu iki parametreyi tek koda yazmak istersek */
g_object_set(sink, "host", "10.223.20.20","port", 5000, NULL);

/*başka bir yazım şekli*/
g_object_set(G_OBJECT(sink), "host", "10.223.20.20",NULL);

element = gst_element_factory_make("queue", "my_queue");
g_object_get(G_OBJECT(element), "silent", &value, NULL);
```

- **`gst_message_parse_error` :** Bir GStreamer mesajından hata ayrıntılarını almak için kullanılan bir yardımcı işlevidir. GStreamer, medya işleme sırasında çeşitli hata mesajları oluşturabilir. Bu işlev, bu hata mesajlarından ayrıntıları almak için kullanılır.
- **`g_signal_connect` :** GLib kütüphanesinin olay işleme sisteminde sinyal-sağlayıcı (signal-provider) ve sinyal-alıcı (signal-receiver) arasında bağlantı kurmak için kullanılan bir işlevidir. Bu işlev, bir nesnenin belirli bir sinyaline bir işlevi (geri arama fonksiyonunu) bağlar.

```c
g_signal_connect(G_OBJECT(nesne), "sinyal-adı", G_CALLBACK(islev), kullanıcı-verileri);
```

- **`gst_element_get_static_pad`** : İşlevi, bir öğeden belirli bir pad'ı almak için kullanılır. İşlev, öğenin bağlantı noktalarının listesinden bir pad seçer ve bu pad'ı döndürür. Bu pad daha sonra bağlantı yapmak veya öğe arası veri akışı kurmak için kullanılabilir.
- **`gst_element_query_position`:** Bu işlev, bir GStreamer öğesinin mevcut oynatma pozisyonunu sorgular. Özellikle, oynatma konumunu belirlemek için kullanılır.
- **`gst_element_query_duration`:** Bu işlev, bir GStreamer öğesinin içerdiği medya dosyasının toplam süresini sorgular. Özellikle, bir medya dosyasının ne kadar süreyle oynatılabileceğini belirlemek için kullanılır.
- **`gst_element_seek_simple`**, bir GStreamer öğesinde basit bir şekilde sıçrama (seek) işlemi gerçekleştirmek için kullanılan bir işlevidir.
    - GST_FORMAT_TIME
    - GST_SEEK_FLAG_FLUSH
    - GST_SEEK_FLAG_KEY_UNIT
    - GST_SEEK_FLAG_ACCURATE
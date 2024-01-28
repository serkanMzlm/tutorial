#include <gst/gst.h>

int main (int argc, char *argv[]) {
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

    gst_init(&argc, &argv); // Tüm iç yapıları başlatır.

    /*
    * gst_parse_launch: multimedya akışlarını yönetmek için kullanılır
    * source kısmından sink kısmına kadar her şeyi içeren pipeline kısmıdır.
    * playbin: mediayi oynatmak için gerekli olan tüm unsurları oluşturur ve bağlar.
    */ 
    pipeline = gst_parse_launch("playbin uri=https://gstreamer.freedesktop.org/data/media/sintel_trailer-480p.webm", NULL);
    
    /*
    * Element durumunu değiştirmek için kullanılır.
    * GST_STATE_PLAYING: Pipeline oynatma durumundadır. Medya akışı başlar
    * GST_STATE_PAUSED: Pipeline duraklatılmış durumdadır.
    * GST_STATE_READY: Pipeline hazır durumdadır.
    * GST_STATE_NULL:  Pipeline durmaktadır.
    */
    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    bus = gst_element_get_bus(pipeline); // pipeline alır.

    /*
    * Pipeline üzernde bir hata oluşması veya EOS  
    * olana kadar çalışmaya devam eder
    */
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                        GST_MESSAGE_ERROR | GST_MESSAGE_EOS);
    if (GST_MESSAGE_TYPE (msg) == GST_MESSAGE_ERROR) {
        g_error ("An error occurred! Re-run with the GST_DEBUG=*:WARN environment "
            "variable set for more details.");
    } 

    // Oluşturulan nesneler silinir.
    gst_message_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);

    return 0;
}

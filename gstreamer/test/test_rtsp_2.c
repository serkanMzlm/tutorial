#include <gst/gst.h>

int main(int argc, char *argv[]) {
    GstElement *pipeline, *source, *depay, *parser, *decoder, *convert, *encoder, *pay, *sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;

    /* Initialize GStreamer */
    gst_init(&argc, &argv);

    /* Create the elements */
    pipeline = gst_pipeline_new("rtsp_to_udp");
    source = gst_element_factory_make("rtspsrc", "source");
    depay = gst_element_factory_make("rtph265depay", "depay");
    parser = gst_element_factory_make("h265parse", "parser");
    decoder = gst_element_factory_make("avdec_h265", "decoder");
    convert = gst_element_factory_make("videoconvert", "convert");
    encoder = gst_element_factory_make("jpegenc", "encoder");
    pay = gst_element_factory_make("rtpjpegpay", "pay");
    sink = gst_element_factory_make("udpsink", "sink");

    /* Check that all elements are created successfully */
    if (!pipeline || !source || !depay || !parser || !decoder || !convert || !encoder || !pay || !sink) {
        g_printerr("Not all elements could be created.\n");
        return -1;
    }

    /* Set the source URI */
    g_object_set(G_OBJECT(source), "location", "rtsp://192.168.144.25:8554/main.264", NULL);

    /* Add all elements into the pipeline */
    gst_bin_add_many(GST_BIN(pipeline), source, depay, parser, decoder, convert, encoder, pay, sink, NULL);

    /* Link the elements */
    if (!gst_element_link_many(source, depay, parser, decoder, convert, encoder, pay, sink, NULL) != TRUE) {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    /* Set the UDP sink properties */
    g_object_set(G_OBJECT(sink), "host", "10.223.9.9", "port", 3000, NULL);

    /* Set the pipeline state to PLAYING */
    ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    /* Listen to the bus */
    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, 
                                        GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    /* Parse and handle messages from the bus */
    if (msg != NULL) {
        GError *err;
        gchar *debug_info;

        switch (GST_MESSAGE_TYPE(msg)) {
            case GST_MESSAGE_ERROR:
                gst_message_parse_error(msg, &err, &debug_info);
                g_printerr("Error received from element %s: %s\n", GST_OBJECT_NAME(msg->src), err->message);
                g_printerr("Debugging information: %s\n", debug_info ? debug_info : "none");
                g_clear_error(&err);
                g_free(debug_info);
                break;
            case GST_MESSAGE_EOS:
                g_print("End-Of-Stream reached.\n");
                break;
            default:
                g_printerr("Unexpected message received.\n");
                break;
        }
        gst_message_unref(msg);
    }

    /* Free resources */
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}

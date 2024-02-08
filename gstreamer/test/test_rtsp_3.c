#include <gst/gst.h>

// Signal handler for 'pad-added'
static void pad_added_handler(GstElement *src, GstPad *new_pad, gpointer user_data) {
    GstElement *decoder = GST_ELEMENT(user_data);
    GstPad *sink_pad = gst_element_get_static_pad(decoder, "sink");
    GstPadLinkReturn ret;

    g_print("Received new pad '%s' from '%s':\n", GST_PAD_NAME(new_pad), GST_ELEMENT_NAME(src));

    if (gst_pad_is_linked(sink_pad)) {
        g_print("  We are already linked. Ignoring.\n");
        goto done;
    }

    ret = gst_pad_link(new_pad, sink_pad);
    if (ret != GST_PAD_LINK_OK) {
        g_printerr("  Link failed.\n");
    } else {
        g_print("  Link succeeded (type '%s').\n", gst_pad_get_name(new_pad));
    }

done:
    gst_object_unref(sink_pad);
}

int main(int argc, char *argv[]) {
    GstElement *pipeline, *source, *decoder, *sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;

    // Initialize GStreamer
    gst_init(&argc, &argv);

    // Create elements
    pipeline = gst_pipeline_new("rtsp_pipeline");
    source = gst_element_factory_make("rtspsrc", "source");
    decoder = gst_element_factory_make("decodebin", "decoder");
    sink = gst_element_factory_make("autovideosink", "sink");

    if (!pipeline || !source || !decoder || !sink) {
        g_printerr("Not all elements could be created.\n");
        return -1;
    }

    // Set rtsp source location and latency
    g_object_set(G_OBJECT(source), "location", "rtsp://192.168.144.25:8554/main.264", NULL);
    g_object_set(G_OBJECT(source), "latency", 100, NULL);

    // Build the pipeline
    gst_bin_add_many(GST_BIN(pipeline), source, decoder, sink, NULL);
    if (!gst_element_link(source, decoder)) {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    // Signal handler for 'pad-added'
    g_signal_connect(source, "pad-added", G_CALLBACK(pad_added_handler), decoder);

    // Set pipeline state to playing
    ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    // Wait until error or EOS
    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    // Parse error message if any
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

    // Free resources
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}
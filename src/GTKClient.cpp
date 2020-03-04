//
// Created by o2173194 on 04/03/20.
//
#include <gtk/gtk.h>
#include <cctype>

static void enter_callback( GtkWidget *widget, GtkWidget *entry )
{
    const gchar *entry_text;
    entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
    printf ("Entry contents: %s\n", entry_text);
}

void insert_text_event(GtkEditable *editable, const gchar *text, gint length, gint *position, gpointer data)
{
    int i;
    for (i = 0; i < length; i++) {
        if (!isdigit(text[i])) {
            g_signal_stop_emission_by_name(G_OBJECT(editable), "insert-text");
            return;
        }
    }
}

/*
* Initialize GTK Window and all widgets
* */
int main(int argc, char *argv[])
{
    /*Initialization of widgets*/
    GtkWidget *window, *button, *input1, *input2, *vbox, *hbox;

    /*Init*/
    gtk_init(&argc, &argv);

    /* Creation of a new window */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show (vbox);

    input1 = gtk_entry_new();
    gtk_entry_set_max_length (GTK_ENTRY (input1), 3);
    g_signal_connect (input1, "activate",
                      G_CALLBACK (enter_callback),
                      input1);
    g_signal_connect(G_OBJECT(input1), "insert_text",
                     G_CALLBACK(insert_text_event),
                     NULL);
    gtk_box_pack_start (GTK_BOX (vbox), input1, TRUE, TRUE, 0);
    gtk_widget_show (input1);

    input2 = gtk_entry_new();
    gtk_entry_set_max_length (GTK_ENTRY (input2), 3);
    g_signal_connect (input2, "activate",
                      G_CALLBACK (enter_callback),
                      input2);
    g_signal_connect(G_OBJECT(input2), "insert_text",
                     G_CALLBACK(insert_text_event),
                     NULL);
    gtk_box_pack_start (GTK_BOX (vbox), input2, TRUE, TRUE, 0);
    gtk_widget_show (input2);

    hbox = gtk_hbox_new(FALSE, 0);
    gtk_container_add (GTK_CONTAINER (vbox), hbox);
    gtk_widget_show (hbox);

    button = gtk_button_new_with_label ("Submit to server");
    g_signal_connect(button, "clicked",
            G_CALLBACK (enter_callback),
            window);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
    gtk_widget_show (button);

//    /* This function will WRITE all the modifications of the SVG in the XMLFile*/
//    svg_data.SaveFile("../Resources/Image Samples/atom.svg");

    /*
     * Connecting all the events to the GTK window
     * */
    g_signal_connect(window, "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);


    /* Configuration of the window */
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 275, 275);
    gtk_window_set_title(GTK_WINDOW(window), "Client SVG");
    /*
     * This will show all the widgets in the window
     * */
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

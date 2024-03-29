//
// Created by o2173194 on 05/03/20.
//

#include "serverUI.hpp"

RsvgHandle *rsvg_handle;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    rsvg_handle_render_cairo(rsvg_handle, cr);
    return FALSE;
}

ServerUI::ServerUI(RsvgHandle* handler) {
    this->_gtk_thread = std::thread(build_serverUI, &(this->_window), handler, &(this->_darea));
    std::clog << "Started UI !" << std::endl;
}

//TODO : Free the rest of the data
ServerUI::~ServerUI() {
    //The gtk window must be closed manually to execute the join
    this->_gtk_thread.join();
    std::clog << "ServerUI thread stopped !" << std::endl;
    std::clog << "ServerUI destructor done !" << std::endl;
}

void ServerUI::update(RsvgHandle* handler) {
    rsvg_handle = handler;
    gtk_widget_queue_draw(this->_darea);   //Update the window to show new modifications.
}

void build_serverUI(GtkWidget** window, RsvgHandle* handler, GtkWidget** darea) {
    /*Init*/
    gtk_init(nullptr, nullptr);

    /*Creation of a new drawing area*/
    *darea = gtk_drawing_area_new();
    gtk_widget_set_size_request (*darea, 450, 450);

    /* Creation of a new window */
    *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* We create a new XMLController with the svg image stored in the server data*/
    rsvg_handle = handler;

    g_signal_connect(G_OBJECT(*darea), "draw",
                     G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(*window, "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    /* Configuration of the window */
    gtk_container_set_border_width (GTK_CONTAINER (*window), 10);
    gtk_window_set_position(GTK_WINDOW(*window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(*window), 500, 500);
    gtk_window_set_title(GTK_WINDOW(*window), "Serveur SVG");

    /* IMPORTANT : Add all the widgets to the window */
    gtk_container_add(GTK_CONTAINER(*window), *darea);
    gtk_widget_show_all(*window);

    gtk_main();
}
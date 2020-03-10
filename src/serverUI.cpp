//
// Created by o2173194 on 05/03/20.
//

#include "serverUI.hpp"

RsvgHandle *rsvg_handle;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
    std::cout << "In on_draw_envent : " << rsvg_handle << std::endl;
    rsvg_handle_render_cairo(rsvg_handle, cr);
    return FALSE;
}

ServerUI::ServerUI(RsvgHandle* handler) {
    std::cout << "In ServerUI Constructor : " << handler << std::endl;
    this->_gtk_thread = std::thread(build_serverUI, &(this->_window), handler);
    std::clog << "Started UI !" << std::endl;
}

void ServerUI::update(){
    gtk_widget_queue_draw(this->_window);   //Update the window to show new modifications.
}

void build_serverUI(GtkWidget** window, RsvgHandle* handler) {
    /*Init*/
    gtk_init(nullptr, nullptr);

    /*Creation of a new drawing area*/
    GtkWidget* darea =  gtk_drawing_area_new();

    /* Creation of a new window */
    *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* We create a new XMLController with the svg image stored in the server data*/
    rsvg_handle = handler;

    std::cout << "In build_serverUI : " << handler << std::endl;

    g_signal_connect(G_OBJECT(darea), "draw",
                     G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(*window, "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    /* Configuration of the window */
    gtk_container_set_border_width (GTK_CONTAINER (*window), 10);
    gtk_window_set_position(GTK_WINDOW(*window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(*window), 275, 275);
    gtk_window_set_title(GTK_WINDOW(*window), "Serveur SVG");

    /* IMPORTANT : Add all the widgets to the window */
    gtk_container_add(GTK_CONTAINER(*window), darea);
    gtk_widget_show_all(*window);

    gtk_main();
}
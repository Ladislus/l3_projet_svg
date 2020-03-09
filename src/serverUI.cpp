//
// Created by o2173194 on 05/03/20.
//
#include "serverUI.hpp"

RsvgHandle *rsvg_handle;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
    rsvg_handle_render_cairo(rsvg_handle, cr);
    return FALSE;
}

ServerUI::ServerUI() {
    /*Init*/
    gtk_init(nullptr, nullptr);

    /*Creation of a new drawing area*/
    this->_darea =  gtk_drawing_area_new();

    /* Creation of a new window */
    this->_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    this->_controller = new XMLController();
    /* We create a new XMLController with the svg image stored in the server data*/
    rsvg_handle = this->_controller->getSvg_handle();

    g_signal_connect(G_OBJECT(this->_darea), "draw",
                     G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(this->_window, "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    /* Configuration of the window */
    gtk_container_set_border_width (GTK_CONTAINER (this->_window), 10);
    gtk_window_set_position(GTK_WINDOW(this->_window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(this->_window), 275, 275);
    gtk_window_set_title(GTK_WINDOW(this->_window), "Serveur SVG");

    /* IMPORTANT : Add all the widgets to the window */
    gtk_container_add(GTK_CONTAINER(this->_window), this->_darea);
    gtk_widget_show_all(this->_window);
}

void ServerUI::update(int sun_x, int sun_y){
    this->_controller->update(sun_x, sun_y); //The controller will update the stored svg data and the svg handle.
    gtk_widget_queue_draw(this->_window);   //Update the window to show new modifications.
}

//TODO : Make this threaded
void ServerUI::start() {
    gtk_main();
}
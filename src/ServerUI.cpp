//
// Created by o2173194 on 05/03/20.
//

#include <ServerUI.hpp>

#include "ServerUI.hpp"

RsvgHandle *rsvg_handle;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
    rsvg_handle_render_cairo(rsvg_handle, cr);
    return FALSE;
}

//static void do_drawing(cairo_t * cr){
//    /*
//     * TODO: This function should call a function (called like OnClickEventRefresh() ?) in another class for clean code.
//     * */
//    XMLElement *levelElement = svg_data.FirstChildElement("svg")->LastChildElement("g");
//    for (XMLElement* child = levelElement->FirstChildElement("circle"); child != nullptr; child = child->NextSiblingElement())
//    {
//        if(swap){
//            child->SetAttribute("style", "fill:#FFFFFF");
//            swap = !swap;
//        } else {
//            child->SetAttribute("style", "fill:#000000");
//            swap = !swap;
//        }
//
//    }
//    svg_data.SaveFile("../Resources/Image Samples/atom.svg");
//    XMLPrinter printer;
//    svg_data.Print(&printer);
//    svg_handle = rsvg_handle_new_from_data ((const unsigned char*) printer.CStr(), printer.CStrSize()-1, NULL);
//    do_drawing_svg(cr);

        /*
         * ALL COMMANDS ABOVE SHOULD BE IN XMLCONTROLLER
         * */

//    gtk_widget_queue_draw(window);
//}

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

}

void ServerUI::start() {
    gtk_widget_show_all(this->_window);
    gtk_main();
}

void ServerUI::setXMLController(XMLController * controller) {
    this->_controller = controller;
}
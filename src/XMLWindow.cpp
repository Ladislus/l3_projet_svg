//
// Created by o2173194 on 04/03/20.
//
#include <cairo.h>
#include <gtk/gtk.h>
#include <librsvg/rsvg.h>
#include <tinyxml2.h>

using namespace tinyxml2;

bool swap = true;

static void do_drawing(cairo_t *);

RsvgHandle *svg_handle;
XMLDocument svg_data;
GtkWidget *window;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
    rsvg_handle_render_cairo(svg_handle, cr);
    return FALSE;
}

static void do_drawing(cairo_t * cr){
    /*
     * TODO: This function should call a function (called like OnClickEventRefresh() ?) in another class for clean code.
     * */
    XMLElement *levelElement = svg_data.FirstChildElement("svg")->LastChildElement("g");
    for (XMLElement* child = levelElement->FirstChildElement("circle"); child != nullptr; child = child->NextSiblingElement())
    {
        if(swap){
            child->SetAttribute("style", "fill:#FFFFFF");
            swap = !swap;
        } else {
            child->SetAttribute("style", "fill:#000000");
            swap = !swap;
        }

    }
    svg_data.SaveFile("../Resources/Image Samples/atom.svg");
    XMLPrinter printer;
    svg_data.Print(&printer);
    svg_handle = rsvg_handle_new_from_data ((const unsigned char*) printer.CStr(), printer.CStrSize()-1, NULL);
    rsvg_handle_render_cairo(svg_handle, cr);
    gtk_widget_queue_draw(window);
}

/*
 * Useful to load the current state of the atom.svg for initialisation and more
 * */
void loadSavedXMLtoRSVG()
{
    XMLPrinter printer;
    svg_data.LoadFile("../Resources/Image Samples/atom.svg");
    svg_data.Print(&printer);
    svg_handle = rsvg_handle_new_from_data ((const unsigned char*) printer.CStr(), printer.CStrSize()-1, NULL);
}

/*
 * Initialize GTK Window and all widgets
 * */
int main(int argc, char *argv[])
{
    /*Initialization of widgets*/
    GtkWidget *darea;

    /*Init*/
    gtk_init(&argc, &argv);

    /* Creation of a new window */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /*Creation of a new drawing area*/
    darea = gtk_drawing_area_new();

    /* XML File to SVG */
    loadSavedXMLtoRSVG();

//    /* This function will WRITE all the modifications of the SVG in the XMLFile*/
//    svg_data.SaveFile("../Resources/Image Samples/atom.svg");

    /*
     * Connecting all the events to the GTK window
     * */
    g_signal_connect(G_OBJECT(darea), "draw",
                     G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(window, "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(window, "button-press-event", G_CALLBACK(do_drawing), NULL);


    /* Configuration of the window */
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 275, 275);
    gtk_window_set_title(GTK_WINDOW(window), "Serveur SVG");

    /*
     * IMPORTANT : Add all the widgets to the window
     * */
    gtk_container_add(GTK_CONTAINER(window), darea);

    /*
     * This will show all the widgets in the window
     * */
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}


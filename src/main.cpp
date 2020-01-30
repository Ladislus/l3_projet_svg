#include <cairo.h>
#include <gtk/gtk.h>
#include <librsvg/rsvg.h>
#include <gio/gfile.h>
#include <tinyxml2.h>

using namespace tinyxml2;

static void do_drawing(cairo_t *);
static void do_drawing_svg(cairo_t *);

RsvgHandle *svg_handle;
RsvgRectangle viewport;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,
                              gpointer user_data)
{
    do_drawing_svg(cr);

    return FALSE;
}

static void do_drawing_svg(cairo_t * cr)
{
    rsvg_handle_render_document (svg_handle, cr, &viewport, NULL);
}


int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *darea;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    darea = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), darea);

    XMLDocument svg_data;
    svg_data.LoadFile("toto.svg");
    XMLElement *rectangle1 = svg_data.FirstChildElement("svg")->FirstChildElement("g")->FirstChildElement("rect");
    rectangle1->SetAttribute("style", "fill:#000000");
    XMLPrinter printer;
    svg_data.Print(&printer);
    svg_handle = rsvg_handle_new_from_data ((const unsigned char*) printer.CStr(), printer.CStrSize(), NULL);
    rsvg_handle_get_geometry_for_element  (svg_handle, NULL, &viewport, NULL, NULL);


    g_signal_connect(G_OBJECT(darea), "draw",
                     G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(window, "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), viewport.width, viewport.height);
    gtk_window_set_title(GTK_WINDOW(window), "GTK window");

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
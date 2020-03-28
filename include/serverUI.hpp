//
// Created by o2173194 on 05/03/20.
//

#ifndef SERVERUI_HPP
#define SERVERUI_HPP

#include <cairo.h>
#include <gtk/gtk.h>
#include <string>
#include <thread>
#include <iostream>
#include <librsvg/rsvg.h>

class ServerUI {

    private:
        GtkWidget *_window{};
        GtkWidget *_darea{};
    //TODO : stop thread in destructor
        std::thread _gtk_thread;

    public:
        explicit ServerUI(RsvgHandle*);
        ~ServerUI();

        void update(RsvgHandle*);

};

void build_serverUI(GtkWidget**, RsvgHandle*, GtkWidget**);

#endif //SERVERUI_HPP



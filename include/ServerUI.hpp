//
// Created by o2173194 on 05/03/20.
//

#ifndef SERVERUI_HPP
#define SERVERUI_HPP

#include <cairo.h>
#include <gtk/gtk.h>
#include <string>
#include "XMLController.hpp"

class ServerUI {
private:
     GtkWidget *_window, *_darea;
     XMLController *_controller;
public:
    ServerUI();
    void start();
    GtkWidget* getWindow() {
        return this->_window;
    }
    GtkWidget* getDarea() {
        return this->_darea;
    }
    void setXMLController(XMLController * controller);

};

#endif //SERVERUI_HPP



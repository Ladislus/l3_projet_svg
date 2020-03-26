//
// Created by o2173194 on 05/03/20.
//

#include "XMLController.hpp"

XMLController::XMLController() {

    /* Load the svg filename */
    this->_svg_data.LoadFile("Resources/Image Samples/maison.svg");

    XMLPrinter printer;
    this->_svg_data.Print(&printer);
    RsvgHandle * _svg_handle = rsvg_handle_new_from_data((const unsigned char*) printer.CStr(), printer.CStrSize() - 1, NULL);
    this->_serverUI = new ServerUI(_svg_handle);
}

XMLController::~XMLController() {
//    delete this->_serverUI;
    std::clog << "XMLController destructor done !" << std::endl;
}

void XMLController::update(int sun_x, int sun_y) {

    XMLElement *levelElement = this->_svg_data.FirstChildElement("svg")->FirstChildElement("g");
    XMLElement *childElement = levelElement->NextSiblingElement("g")->FirstChildElement("g")->FirstChildElement("circle");

    childElement->SetAttribute("cx", sun_x);
    childElement->SetAttribute("cy", sun_y);

    XMLPrinter printer;
    this->_svg_data.Print(&printer);
    RsvgHandle * _svg_handle = rsvg_handle_new_from_data((const unsigned char*) printer.CStr(), printer.CStrSize() - 1, NULL);
    this->_serverUI->update(_svg_handle);
}

//
// Created by o2173194 on 05/03/20.
//

#include "XMLController.hpp"

XMLController::XMLController() {

    /* Load the svg filename */
    this->_svg_data.LoadFile("Resources/Image Samples/atom.svg");

    XMLPrinter printer;
    GError* errors;
    this->_svg_data.Print(&printer);
    this->_svg_handle = rsvg_handle_new_from_data((const unsigned char*) printer.CStr(), printer.CStrSize() - 1, &errors);
    //TODO : Manage error
//    if (errors != nullptr) std::cerr << errors->message << std::endl;

    this->_serverUI = new ServerUI(this->_svg_handle);
}

void XMLController::update(int sun_x, int sun_y) {
    XMLElement *levelElement = this->_svg_data.FirstChildElement("svg")->LastChildElement("g");
    XMLElement *childElement = levelElement->NextSiblingElement("g")->FirstChildElement("g");

    childElement->SetAttribute("cx", sun_x);
    childElement->SetAttribute("cy", sun_y);

    GError* errors;
    XMLPrinter printer;
    this->_svg_data.Print(&printer);
    this->_svg_handle = rsvg_handle_new_from_data((const unsigned char*) printer.CStr(), printer.CStrSize()-1, &errors);
    this->_serverUI->update();
    //TODO : Manage error
//    if (errors != nullptr) std::cerr << errors->message << std::endl;
}

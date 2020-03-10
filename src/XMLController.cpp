//
// Created by o2173194 on 05/03/20.
//

#include "XMLController.hpp"

XMLController::XMLController() {

    /* Load the svg filename */
    //TODO : relative path
    this->_svg_data.LoadFile("/home/ladislus/Git/drieux_joffroy_walcak_mercier/Resources/Image Samples/atom.svg");

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

    //TODO : Don't save the file
//    this->_svg_data.SaveFile("../Resources/Image Samples/atom.svg");

    GError* errors;
    XMLPrinter printer;
    this->_svg_data.Print(&printer);
    this->_svg_handle = rsvg_handle_new_from_data((const unsigned char*) printer.CStr(), printer.CStrSize()-1, &errors);
    //TODO : Manage error
//    if (errors != nullptr) std::cerr << errors->message << std::endl;
}

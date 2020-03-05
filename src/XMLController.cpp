//
// Created by o2173194 on 05/03/20.
//

#include <XMLController.hpp>

#include "XMLController.hpp"

XMLController::XMLController() {
    /* Load the svg filename */
    this->_svg_data.LoadFile("../Resources/Image Samples/atom.svg"); ;
    XMLPrinter printer;
    this->getSvg_data().Print(&printer);
    this->_svg_handle = rsvg_handle_new_from_data ((const unsigned char*) printer.CStr(), printer.CStrSize()-1, NULL);
}

//
// Created by o2173194 on 05/03/20.
//

#include "XMLController.hpp"

XMLController::XMLController() {

    std::clog << "Blabla1" << std::endl;
    /* Load the svg filename */
    this->_svg_data.LoadFile("/home/ladislus/Git/drieux_joffroy_walcak_mercier/Resources/Image Samples/atom.svg");

    std::clog << "_sg_data : " << &(this->_svg_data) << std::endl;

    XMLPrinter printer;
    std::clog << "Blabla2" << std::endl;

    GError* errors;
    std::clog << "Blabla3" << std::endl;

    this->_svg_data.Print(&printer);
    std::clog << "Blabla4" << std::endl;

    this->_svg_handle = rsvg_handle_new_from_data ((const unsigned char*) printer.CStr(), printer.CStrSize() - 1, &errors);
    std::clog << "Blabla5" << std::endl;

//    std::cout << "Errors : " << errors->message << std::endl;
    std::cout << "In XMLController constructor : " << &(this->_svg_handle) << std::endl;

    std::clog << "Blabla6" << std::endl;
    this->_serverUI = new ServerUI(this->_svg_handle);
}

void XMLController::update(int sun_x, int sun_y) {
    XMLElement *levelElement = this->_svg_data.FirstChildElement("svg")->LastChildElement("g");
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
    this->_svg_data.SaveFile("../Resources/Image Samples/atom.svg");
    XMLPrinter printer;
    this->_svg_data.Print(&printer);
    this->_svg_handle = rsvg_handle_new_from_data ((const unsigned char*) printer.CStr(), printer.CStrSize()-1, NULL);
}

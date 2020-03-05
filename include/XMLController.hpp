//
// Created by o2173194 on 05/03/20.
//

#ifndef XMLCONTROLLER_HPP
#define XMLCONTROLLER_HPP

#include <librsvg/rsvg.h>
#include <tinyxml2.h>

using namespace tinyxml2;

class XMLController {
private:
    RsvgHandle *_svg_handle;
    XMLDocument _svg_data;
public:
    XMLController();

    RsvgHandle *getSvg_handle() {
        return this->_svg_handle;
    }
    XMLDocument &getSvg_data() {
        return this->_svg_data;
    }
};

#endif //XMLCONTROLLER_HPP

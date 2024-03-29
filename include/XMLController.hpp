//
// Created by o2173194 on 05/03/20.
//

#ifndef XMLCONTROLLER_HPP
#define XMLCONTROLLER_HPP

#include <librsvg/rsvg.h>
#include <tinyxml2.h>
#include "serverUI.hpp"

using namespace tinyxml2;

class XMLController {

    private:
        //TODO : Free in destructor
        XMLDocument _svg_data;
        ServerUI* _serverUI;

    public:
        XMLController();
        ~XMLController();

        void update(int sun_x, int sun_y);
};

#endif //XMLCONTROLLER_HPP

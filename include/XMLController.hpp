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
        RsvgHandle* _svg_handle;
        XMLDocument _svg_data;
        ServerUI* _serverUI;

    public:
        XMLController();

        void update(int i, int i1);
};

#endif //XMLCONTROLLER_HPP

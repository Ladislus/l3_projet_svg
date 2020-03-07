//
// Created by ladislus on 06/03/2020.
//

#ifndef DRIEUX_JOFFROY_WALCAK_MERCIER_CLIENT_HPP
#define DRIEUX_JOFFROY_WALCAK_MERCIER_CLIENT_HPP

#include <iostream>
#include <cbor.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>

bool parse(const std::string& input, int& output);

#endif //DRIEUX_JOFFROY_WALCAK_MERCIER_CLIENT_HPP

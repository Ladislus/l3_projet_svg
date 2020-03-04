#Version de Cmake
cmake_minimum_required(VERSION 3.12)
#Projet
project(drieux_joffroy_walcak_mercier)

#Standard de c++
set(CMAKE_CXX_STANDARD 17)

#Outil pour trouver les packages
find_package(PkgConfig REQUIRED)

#Tous les packages utilisés
pkg_check_modules(CAIRO REQUIRED cairo)
pkg_check_modules(TXML REQUIRED tinyxml2)
pkg_check_modules(RSVG REQUIRED librsvg-2.0)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(CBOR REQUIRED libcbor)

#On les inclus
include_directories(${TXML_INCLUDE_DIRS}
                    ${CAIRO_INCLUDE_DIRS}
                    ${GTK3_INCLUDE_DIRS}
                    ${RSVG_INCLUDE_DIRS}
                    ${CBOR_INCLUDE_DIRS}
                    include)

#On les lies
link_directories(${GTK3_LIBRARY_DIRS}
                 ${RSVG_LIBRARY_DIRS}
                 ${CAIRO_LIBRARY_DIRS}
                 ${TXML_LIBRARY_DIRS}
                 ${CBOR_LIBRARY_DIRS})

add_executable(server src/main.cpp src/server.cpp)
#add_executable(client src/client.cpp)

#On lies les librairies pour le serveur
target_link_libraries(server ${GTK3_LIBRARIES} ${RSVG_LIBRARIES} ${CAIRO_LIBRARIES} ${TXML_LIBRARIES})

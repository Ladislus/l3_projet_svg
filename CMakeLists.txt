cmake_minimum_required(VERSION 3.12)
project(Projet_DRIEUX_MERCIER_JOFFROY_WALCAK)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)



add_executable(Exec src/main.cpp)
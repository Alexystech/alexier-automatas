cmake_minimum_required(VERSION 3.17)
project(Automatas)

set(CMAKE_CXX_STANDARD 17)

add_executable(Automatas main.cpp utilidad/constantes/Variables.cpp utilidad/constantes/Variables.h utilidad/constantes/Caracteres.cpp utilidad/constantes/Caracteres.h utilidad/constantes/Key.cpp utilidad/constantes/Key.h files/CustomFile.cpp files/CustomFile.h utilidad/Util.cpp utilidad/Util.h)
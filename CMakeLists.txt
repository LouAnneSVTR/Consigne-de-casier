cmake_minimum_required(VERSION 3.16)
project(Projet_ASD2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet_ASD2 main.cpp Consigne.cpp Consigne.hpp Ticket.cpp Ticket.hpp Type.hpp Bagage.cpp Bagage.hpp
        BagageRectangle.cpp BagageRectangle.hpp BagageCylindre.cpp BagageCylindre.hpp BagagePyramide.cpp
        BagagePyramide.hpp VConsigne.cpp VConsigne.hpp)
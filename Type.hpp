#ifndef PROJET_ASD2_TYPE_HPP
#define PROJET_ASD2_TYPE_HPP


#include <iostream>
#include "Bagage.hpp"

//-------------------------------------------------------------------------
///1 ER PARTIE
//Bagage simple
 struct BagageSimple
{
    std::string nom_bagage;
    bool estValide = true;
};


//Casier simple
struct Casier_simple
{
    bool est_Libre = true;
    int numero_Casier;
    BagageSimple bagage;

};

//-------------------------------------------------------------------------
///2 EME PARTIE
struct Casier
{
    bool est_Libre = true;
    int numero_Casier;
    Bagage *bagage;
    int volume_casier;

};

#endif //PROJET_ASD2_TYPE_HPP
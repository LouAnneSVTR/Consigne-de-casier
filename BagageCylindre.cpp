#include "BagageCylindre.hpp"
#include "math.h"

using namespace std;

/** ROLE : Constructeur du cylindre.
 * @param hauteur : hauteur du cylindre.
 * @param rayon : Rayon de la base circulaire du cylindre.
 * @return BagageCylindre
 */
BagageCylindre::BagageCylindre(string nom, double hauteur, double rayon) : Bagage(nom), m_hauteur(hauteur), m_rayon(rayon)
{
    this->calcul_volume(); //calcul du volume.
}

/** ROLE : Detruit l'objet.*/
BagageCylindre::~BagageCylindre()
{
}

//-------------------------------------------------------------------
/** ROLE : Calcule le volume du cylindre. */
void BagageCylindre::calcul_volume()
{
    this->m_volume = ( M_PI * ( this->m_rayon * this->m_rayon) * this->m_hauteur ) /1000; // "1000" pour passer des cm cube aux Litres.
}

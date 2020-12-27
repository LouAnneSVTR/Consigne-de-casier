#include "BagageRectangle.hpp"

using namespace std;

/** ROLE : Constructeur basique des rectangles.
 * @param hauteur : Hauteur du rectangle.
 * @param largeur : Largeur indépendante de la longueur pour permettre un base rectangulaire.
 * @param longueur : Longueur, indépendante de la largeur.
 * @return BagageRectangle
 */
BagageRectangle::BagageRectangle(string nom, double hauteur, double largeur, double longueur) : Bagage(nom), m_hauteur(hauteur), m_largeur(largeur), m_longueur(longueur)
{
    this->calcul_volume(); //calcul du volume.
}

/** ROLE : Constructeur pour les rectangles spéciaux, les carrés.
 * Initialisation des tous les attributs par la hauteur.
 * @param hauteur : Hauteur = longueur = largeur pour obtenir un cube.
 * @return BagageRectangle
 */
BagageRectangle::BagageRectangle(string nom, double hauteur)  : Bagage(nom), m_hauteur(hauteur), m_longueur(hauteur), m_largeur(hauteur)
{
    this->calcul_volume(); //calcul du volume.
}

/** ROLE : Detruit l'objet.*/
BagageRectangle::~BagageRectangle()
{
}

//------------------------------------------------------------------------------
/** ROLE : Calcule le volume du rectangle.
 * Les entrées sont en cm, la sortie renvoie un valeur en Litre. */
void BagageRectangle::calcul_volume()
{
    this->m_volume = ( this->m_hauteur * this->m_largeur *  this->m_longueur ) / 100; //divison par 100 pour passer en litre.
}

#include "BagagePyramide.hpp"


using namespace std;

/** ROLE : Constructeur basique de la pyramide, la base est déjà connu.
 * @param nom : Nom du sac.
 * @param hauteur : Hauteur de la pyramide.
 * @param base : Base connue.
 * @return BagagePyramide
 */
BagagePyramide::BagagePyramide(string nom, double base, double hauteur) : Bagage(nom), m_base(base), m_hauteur(hauteur)
{
    this->calcul_volume();
}

/** ROLE : Constructeur de la pyramide, la base est inconnue et doit être calculée.
 * @param nom : Nom du sac.
 * @param base_longueur : Longueur de la base, peut etre différente de la largeur.
 * @param base_largeur : Largeur de la base, idem peut être différente de la longueur.
 * @param hauteur : Hauteur de la pyramide.
 */
BagagePyramide::BagagePyramide(string nom, double base_longueur, double base_largeur, double hauteur) : Bagage(nom), m_hauteur(hauteur)
{
    this->m_base = base_longueur * base_largeur; //Calcul de l'aire de la base.
    this->calcul_volume();
}

/** ROLE : Detruit l'objet.*/
BagagePyramide::~BagagePyramide()
{
}

//------------------------------------------------------------------------------
/** ROLE : Calcule le volume de la pyramide. */
void BagagePyramide::calcul_volume()
{
    this->m_volume = ( this->m_base * this->m_hauteur ) / 300; // division par 300 pour passer en litre.
}
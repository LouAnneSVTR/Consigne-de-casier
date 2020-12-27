#ifndef PROJET_ASD2_BAGAGERECTANGLE_HPP
#define PROJET_ASD2_BAGAGERECTANGLE_HPP
#endif //PROJET_ASD2_BAGAGERECTANGLE_HPP

#include <iostream>
#include "Bagage.hpp"

class BagageRectangle : public Bagage
{

private :
    double m_hauteur;
    double m_largeur;
    double m_longueur;

public :

    /** ROLE : Constructeur basique des rectangles.
     * @param hauteur : Hauteur du rectangle.
     * @param largeur : Largeur indépendante de la longueur pour permettre un base rectangulaire.
     * @param longueur : Longueur, indépendante de la largeur.
     * @return BagageRectangle
     */
    BagageRectangle(std::string nom, double hauteur, double largeur, double longueur); //Constructeur basique des rectangles.

    /** ROLE : Constructeur pour les rectangles spéciaux, les carrés.
     * Initialisation des tous les attributs par la hauteur.
     * @param hauteur : Hauteur = longueur = largeur pour obtenir un cube.
     * @return BagageRectangle
     */
    BagageRectangle(std::string nom, double hauteur); //Constructeur pour les rectangles spéciaux, les carrés.

    /** ROLE : Detruit l'objet.*/
    virtual ~BagageRectangle();

private :
    //------------------------------------------------------------------------------
    /** ROLE : Calcule le volume du rectangle. */
    virtual void calcul_volume();
};

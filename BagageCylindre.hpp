
#ifndef PROJET_ASD2_BAGAGECYLINDRE_HPP
#define PROJET_ASD2_BAGAGECYLINDRE_HPP

#include <iostream>
#include "Bagage.hpp"


class BagageCylindre : public Bagage
{

private :
    double m_hauteur;
    double m_rayon;

public :
    //Constructeur/Deconstructeur
    /** ROLE : Constructeur du cylindre.
      * @param hauteur : hauteur du cylindre.
      * @param rayon : Rayon de la base circulaire du cylindre.
      * @return BagageCylindre
      */
    BagageCylindre(std::string nom, double hauteur, double rayon);

    /** ROLE : Detruit l'objet.*/
    virtual ~BagageCylindre();

    //------------------------------------------------------------------
    /** ROLE : Calcule le volume du cylindre. */
    virtual void calcul_volume();
};



#endif //PROJET_ASD2_BAGAGECYLINDRE_HPP

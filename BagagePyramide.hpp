#ifndef PROJET_ASD2_BAGAGEPYRAMIDE_HPP
#define PROJET_ASD2_BAGAGEPYRAMIDE_HPP
#include "Bagage.hpp"

class BagagePyramide : public Bagage
{
    
private :
    double m_base;
    double m_hauteur;

public :

    /** ROLE : Constructeur basique de la pyramide, la base est déjà connu.
     * @param nom : Nom du sac.
     * @param hauteur : Hauteur de la pyramide.
     * @param base : Base connue.
     * @return BagagePyramide
     */
    BagagePyramide(std::string nom, double base, double hauteur);

    /** ROLE : Constructeur de la pyramide, la base est inconnue et doit être calculée.
     * @param nom : Nom du sac.
     * @param base_longueur : Longueur de la base, peut etre différente de la largeur.
     * @param base_largeur : Largeur de la base, idem peut être différente de la longueur.
     * @param hauteur : Hauteur de la pyramide.
     */
    BagagePyramide(std::string nom, double base_longueur, double base_largeur, double hauteur);

    /** ROLE : Detruit l'objet.*/
    virtual ~BagagePyramide();

    //------------------------------------------------------------------------------
    /** ROLE : Calcule le volume de la pyramide. */
    virtual void calcul_volume();
};


#endif //PROJET_ASD2_BAGAGEPYRAMIDE_HPP

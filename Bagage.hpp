#include <iostream>


#ifndef PROJET_ASD2_BAGAGE_HPP
#define PROJET_ASD2_BAGAGE_HPP


class Bagage {

protected :
    std::string m_nom_bagage;
    double m_volume;

    //Constructeur
    /** ROLE : Construit l'objet bagage.
     * @param nomBagage nom du bagage.
     */
    Bagage(std::string nomBagage);

public :
    //Deconstructeur
    virtual ~Bagage();

    //Accesseur
    double getMVolume() const;

    //Methode
    const std::string &getMNomBagage() const;

protected :
    /** ROLE : méthode batrite du calcul du volume du bagage (sous-classe : Rectangle, cylindre, pyramidal...). */
    virtual void calcul_volume();
};

#endif //PROJET_ASD2_BAGAGE_HPP

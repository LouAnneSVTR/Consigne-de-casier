#include "Bagage.hpp"

using namespace std;

//Constructeur/Destructeur
/** ROLE : Construit l'objet bagage.
 * @param nomBagage nom du bagage.
 */
Bagage::Bagage(string nomBagage) : m_nom_bagage(nomBagage)
{
}

Bagage::~Bagage()
{
}

//Accesseur
double Bagage::getMVolume() const {
    return m_volume;
}

const string &Bagage::getMNomBagage() const {
    return m_nom_bagage;
}

//Methodes
/** ROLE : méthode batrite du calcul du volume du bagage (sous-classe : Rectangle, cylindre, pyramidal...). */
void Bagage::calcul_volume()
{

}


#include "Ticket.hpp"
#include <iostream>
#include <random>
#include <unordered_map>

using namespace std;

/** SPÉCIALISATION HASH */

template<class Ticket>
struct hash {
    size_t operator()(const Ticket &t) const {
        return t.hash_code();
    }
};


//********************************* CONSTRUCTEUR / DECONSTRUCTEUR *********************************
/** ROLE : Génère un code à l'aide de la table ascii.
* Peut contenir des chiffres, des minuscules et des majuscules
*/
string Ticket::generer_code()
{
    string code = "";
    for (int i = 0 ; i < 10 ; ++i) {
        int nombre;
        //Gestion du random
        random_device dev;
        mt19937 aleatoire(dev());
        uniform_int_distribution<mt19937::result_type> dist09(0, 61); // distribution in range [1, 6].
        nombre = dist09(aleatoire);

        if (nombre < 10) { //Gestion des chiffres de la tables Ascii.
            nombre += 48;
            code += char(nombre);

        } else if (nombre < 36 ) { //gestion des majuscules.
            nombre += 55;
            code += char(nombre);

        } else { //Gestion des minucules.
            nombre += 61;
            code += char(nombre);
        }
    }
    return code;
}


//---------------------------------------------------
/** CONSTRUCTEUR/DESTRUCTEUR */
Ticket::Ticket()
{
    this->m_code_ticket = this->generer_code();
    this->m_ticket_valable = true; //Initialisation a "true" car on considère que le ticket est presque tout le temps valable.
}

Ticket::~Ticket() {}


//********************************* GESTION TICKET *********************************
///ACCESSEURS
bool Ticket::get_est_Valable() const {
    return m_ticket_valable;
}

//---------------------------------------------------
/** ROLE : Rend le ticket inutilisable. */
void Ticket::ticket_null()
{
    this->m_ticket_valable = false;
}

//************************************** HASH **************************************
/** ROLE : Test si 2 tickets sont égaux.
 * PRECONDITION : Le ticket rhs doit exister.
 * @param rhs Ticket à comparer.
 * @return vérification.
 */
bool Ticket::operator==( Ticket const& rhs) const {
    return m_code_ticket == rhs.m_code_ticket &&
           m_ticket_valable == rhs.m_ticket_valable;
}

//---------------------------------------------------
/** ROLE : Test si 2 tickets sont différents.
 *  PRECONDITION : Le ticket rhs doit exister.
 * @param rhs Ticket à comparer.
 * @return vérification.
 */
bool Ticket::operator!=(Ticket const& rhs) const {
    return !(rhs == *this);
}


//---------------------------------------------------
///SIGNATURE HASH
size_t Ticket:: hash_code() const {

    //Variable
    size_t t;

    //Debut
    for ( int i = 0 ; i <= 9 ; i++) {
        t += i * (int(this->m_code_ticket[i])); //On multiplie la valeur Ascii du caractère par sa position dans la chaine.
    }
    return t;
}

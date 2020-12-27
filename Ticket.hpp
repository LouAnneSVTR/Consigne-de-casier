#include <string>
#include <ostream>

#ifndef PROJET_ASD2_TICKET_H
#define PROJET_ASD2_TICKET_H





class Ticket {

private:

    //Code du ticket générer aléatoirement.
   std::string  m_code_ticket;

    //Ticket valable ou non.
   bool m_ticket_valable;


public:

    //********************************* CONSTRUCTEUR / DECONSTRUCTEUR *********************************

    /** ROLE :Genere un code a l'aide de la table ascii
    * Peut contenir des chiffres, des minuscules et des majuscules
    */
    std::string generer_code();

    //---------------------------------------------------
    /** CONSTRUCTEUR/DESTRUCTEUR */
    Ticket();
    ~Ticket();

    //********************************* GESTION TICKET *********************************

    ///ACCESSEURS
    bool get_est_Valable() const;

    //---------------------------------------------------
   /** ROLE : Rend le ticket inutilisable. */
    void ticket_null();

    //********************************* HASH *********************************
    /** ROLE : Test si 2 tickets sont égaux.
     *  PRECONDITION : Le ticket rhs doit exister.
     * @param rhs Ticket à comparer.
     * @return vérification.
     */
    bool operator==(const Ticket &rhs) const;

    //---------------------------------------------------
    /** ROLE : Test si 2 tickets sont différents.
     *  PRECONDITION : Le ticket rhs doit exister.
     * @param rhs Ticket à comparer.
     * @return vérification.
     */
    bool operator!=(const Ticket &rhs) const;

    //---------------------------------------------------
    ///SIGNATURE HASH
    size_t hash_code() const;

};

/** SPÉCIALISATION HASH */template<>
struct std::hash<Ticket> {
     size_t operator()(const Ticket &t) const {
         return t.hash_code();
     }
};

#endif //PROJET_ASD2_TICKET_H



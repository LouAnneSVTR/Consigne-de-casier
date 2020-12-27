#ifndef PROJET_ASD2_CONSIGNE_H
#define PROJET_ASD2_CONSIGNE_H


#include <iostream>
#include <map>
#include "Type.hpp"
#include <queue>
#include <unordered_map>
#include "Ticket.hpp"


class Consigne {

private:

    //Nombre d'élément max.
    int m_nb_element;

    //Tableau statique de casier (stockage).
    Casier_simple *m_tab_casier; //Initialisation d'un pointeur vers un tableau statique

    //Nombre de casier utilisé.
    int m_nb_casier_utilise;

    //Map de couple {Ticket, index casier}.
    std::unordered_map<Ticket, int> m_map_ticket_indice;

    //Initialisation de la file
    std::queue<int> m_indice_casier_libre;


public:

    //************************************ CONSTRUCTEUR / DECONSTRUCTEUR ************************************
    /** ROLE : Initialisation de la file avec les indices des casiers. */
    void init_file();

    //-------------------------------------------------------------------------------------
    /** ROLE : Initialisation du tableau avec les numéros de casier */
    void init_tab();

    //-------------------------------------------------------------------------------------
    /** CONSTRUCTEUR de la Consigne. Initialise et rempli le tableau et la file du nombre d’objet CasierSimple
     *  PRECONDITION : Le ticket rhs doit exister. */
    Consigne(int nbCasierMax);
    /** DESTRUCTEUR */
    ~Consigne();


    //************************************ GESTION BAGAGE ************************************

    /** ROLE : Vérifie si le tableau de caiser est rempli de bagage.
     * @return booleen qui véréifie, "true" plein, "false" non rempli.
     */
    bool est_pleine();

    //-------------------------------------------------------------------------------------
    /** ROLE : Permet de déposer un bagage dans le casier.
     * Le but étant d'offrir une complexité en theta de 1.
     *  PRECONDITION : Objet BagageSimple en entrée doit être initialisé.
     * @param b : Bagage à déposer dans le casier
     * @return Ticket : Objet Ticket qui permetera par la suite de retirer le bagage
     */
    Ticket deposer_bagage(BagageSimple b) ;

    //-------------------------------------------------------------------------------------
    /** ROLE : Permet de retirer un bagage dans le casier.
     *  Le but étant d'offrir une complexité en theta de 1.
     *  PRECONDITION : Objet Ticket en entrée doit être initialisé.
     *
     * @param t : Ticket représentant la clé pour trouver le casier
     * @return BagageSimple : Objet bagage correspondant au bon Casier rendue par le Ticket
     */
    BagageSimple retirer_bagage(Ticket t);


    //************************************ AFFICHAGE ************************************
    /** ROLE : Affiche le premier élément de la file, c'est à dire le prochain qui sera défilé.
     * @return cdc du premier élément.
     */
    std::string afficher_premier_element();
};

#endif //PROJET_ASD2_CONSIGNE_H
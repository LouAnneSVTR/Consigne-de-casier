#ifndef PROJET_ASD2_VCONSIGNE_HPP
#define PROJET_ASD2_VCONSIGNE_HPP

#include <iostream>
#include <unordered_map>
#include <queue>
#include "Type.hpp"
#include "Ticket.hpp"
#include "Bagage.hpp"


class VConsigne
{
private :
    int m_nb_element; //Nombre d'élément de la consigne ( casier ).
    Casier* m_tab_casier; //Initialisation d'un pointeur vers un tableau statique
    int m_nb_casier_utilise; //Nombre de casier occupé dans la consigne.

    std::unordered_map<Ticket, int> m_map_ticket_indice;
    std::unordered_map<int, std::queue<int>> m_map_vcasier_libre; //Map de file d'on chaque clé correspond à la catégorie de volume.


public :
    //********************************* CONSTRUCTEUR / DECONSTRUCTEUR *********************************
    /** ROLE : Initialisation du tableau avec les numéros de casier. */
    void init();

    //-------------------------------------------------------------------------------------
    /** ROLE : Constructeur de VConsigne.
     * PRECONDITION : L’entrée doit être un entier.
     * @param nbCasierMax nombre de casier que comporte VConsigne au max.
     */
    VConsigne(int nbCasierMax);

    //-------------------------------------------------------------------------------------
    ///Deconstructeur
    ~VConsigne();


    //********************************* GESTION BAGAGE *********************************
    /** ROLE : Recherche le volume clé supérieur le plus proche d'un volume d'un bagage.
     *  PRECONDITION : L’entrée doit être un reel.
     * @param volume_bagage
     * @return clé volume.
     */
    int recherche_cle(double volume_bagage);

    //-------------------------------------------------------------------------------------
    /** ROLE : Dépose un bagage dans VConsigne.
     *  PRECONDITION : L’entrée doit être un Bagage crée et initialisé.
     * @param b bagage donné.
     * @return Ticket du bagage.
     */
    Ticket deposer_bagage(Bagage b);

    //-------------------------------------------------------------------------------------
    /** ROLE : Retire un bagage de VConsigne.
     * @param t Ticket du bagage.
     */
    void retirer_bagage(Ticket t);


    //************************************* AFFICHAGE *************************************
    /** ROLE : Affiche la liste des casier disponible file par file.
     * @return texte d'affichage.
     */
    std::string affichage_consigne();

};

#endif //PROJET_ASD2_VCONSIGNE_HPP



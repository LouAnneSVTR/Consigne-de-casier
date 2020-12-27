#include <iostream>
#include "Consigne.hpp"
#include <queue>

using namespace std;

//************************************ CONSTRUCTEUR / DECONSTRUCTEUR ************************************
/** ROLE : Initialisation de la file avec les indices des casiers. */
void Consigne::init_file()
{
    for (int i = 0 ; i < this->m_nb_element ; ++i) {
        this->m_indice_casier_libre.push(i);
    }
    cout<< "\n>>>>>>>>>> Initialisation de la file terminée. >>>>>>>>>>"<< endl;
}

//-------------------------------------------------------------------------------------
/** ROLE : Initialisation du tableau avec les numéros de casier */
void Consigne::init_tab()
{
    for (int i = 0 ; i < this->m_nb_element ; ++i) {
        this->m_tab_casier[i].numero_Casier = i;
    }
    cout<< "\n>>>> Initialisation des numéros de casier terminée. >>>>\n"<< endl;
}


//-------------------------------------------------------------------------------------
/** CONSTRUCTEUR de la Consigne. Initialise et rempli le tableau et la file du nombre d’objet CasierSimple
  *  PRECONDITION : Le ticket rhs doit exister. */
Consigne::Consigne(int nb_casier_max)
{
    m_nb_element         =  nb_casier_max;
    m_tab_casier         =  new Casier_simple[m_nb_element];
    m_nb_casier_utilise  =  0;
    //Initialisation file et tab
    init_file();
    init_tab();
}
/** DESTRUCTEUR */
Consigne::~Consigne()
{
    delete [] this->m_tab_casier;
}



//************************************ GESTION BAGAGE ************************************
/** ROLE : Vérifie si le tableau de caiser est rempli de bagage.
 * @return booleen qui véréifie, "true" plein, "false" non rempli.
 */
bool Consigne::est_pleine()
{
    return this->m_nb_element == this->m_nb_casier_utilise;
}

//-------------------------------------------------------------------------------------
/** ROLE : Permet de déposer un bagage dans le casier.
 * Le but étant d'offrir une complexité en theta de 1.
 * PRECONDITION : Objet BagageSimple en entrée doit être initialisé.
 * @param b : Bagage à déposer dans le casier.
 * @return Ticket : Objet Ticket qui permetera par la suite de retirer le bagage.
 */
Ticket Consigne::deposer_bagage(BagageSimple b)
{
    //Variables
    int index;
    Ticket ticket;

    //Début
    try
    {
        if (this->est_pleine()) {
            throw string("\n/!\\  ERREUR : Tous les casiers sont déjà occupés, "+ b.nom_bagage + "\" ne peut être déposé.");

        } else {
            index = this->m_indice_casier_libre.front(); //Renvoie l'index du casier libre dont la dernière utilisation est la plus ancienne.
            this->m_indice_casier_libre.pop(); //Defile le casier index.

            this->m_tab_casier[index].bagage = b; //Affectation du casier par le bagage "b".
            this->m_tab_casier[index].est_Libre = false; //Le casier devient occupe
            this->m_nb_casier_utilise++;

            this->m_map_ticket_indice.insert({ticket, index}); //On insere dans la map pour hasher le casier

            cout << "\nINFORMATION : Le dépot du bagage " << b.nom_bagage << " a bien été effectué." << endl;
        }
    }
    catch (string const &chaine)
    {
        ticket.ticket_null();
        cout << chaine << endl;
    }
        return ticket;
}


//-------------------------------------------------------------------------------------
/** ROLE : Permet de retirer un bagage dans le casier.
 * Le but étant d'offrir une complexité en theta de 1.
 * PRECONDITION : Objet Ticket en entrée doit être initialisé.
 * @param t : Ticket représentant la clé pour trouver le casier
 * @return BagageSimple : Objet bagage correspondant au bon Casier rendue par le Ticket
 */
BagageSimple Consigne::retirer_bagage(Ticket t) {

    //Variable
    int index_casier; //index du caiser ou se trouve le bagage.
    BagageSimple b;

    //Debut
    try {
        if (!t.get_est_Valable()) { //Vérifie si le ticket est valable.
            throw string("\n/!\\  ERREUR : Le ticket est invalide ! "); //erreur en cas de mauvais ticket.

        } else {

            index_casier = this->m_map_ticket_indice.operator[](t); //Ressort de la map l'index du casier à l'aide du ticket (hash).
            b = this->m_tab_casier[index_casier].bagage; //Ressort le bagage à l'index trouvé.
            this->m_tab_casier[index_casier].est_Libre = true; //Mets le casier en libre.
            this->m_indice_casier_libre.push(index_casier); //Ajoute à la file l'index du casier nouvellement libre.
            this->m_nb_casier_utilise--;
            this->m_map_ticket_indice.erase(t);
            cout << "\nINFORMATION : Le retrait du bagage " << b.nom_bagage << " a bien été effectué." << endl;

            return b;
        }
    }
    catch (string const &chaine) {
        cout << chaine << endl;
    }
    return b;
}


//************************************ AFFICHAGE ************************************
/** ROLE : Affiche le premier élément de la file, c'est-à-dire le prochain qui sera défilé.
 * @return cdc du premier élément.
 */
string Consigne::afficher_premier_element() {
    string aff = "";
    aff = "\nPremier élément de la file : " + to_string( this->m_indice_casier_libre.front()) + "\n";
    return aff;
}
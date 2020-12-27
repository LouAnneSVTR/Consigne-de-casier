#include <sstream>
#include "VConsigne.hpp"
#include "BagageRectangle.hpp"

using namespace std;

//************************************ INITIALISATION/CONSTRUCTEUR ************************************
/** ROLE : Initialise le tableau et le rempli des numéros de casier. Ce tableau représente nos données statiques, les casier libre et les rempli.
 *  Initialise chaque clé de la map de file en fonction des volumes de la consigne. Rempli chaque file par tous les casiers.
 *  Données dynamiques evoluant en fonction des dépôts, les files réprésente les casiers libres seulement. */
void VConsigne::init()
{
    bool tour_termine = false;
    int volume_casier = 5;

    for (int i = 0 ; i < this->m_nb_element ; ++i) {

        this->m_tab_casier[i].numero_Casier = i; //Initialisation des numéros de casier dans le tableau.
        this->m_tab_casier[i].volume_casier = volume_casier; //Initialisation du volume de chaque casier. (Commence par 5L).

        //Sert à creer et ajouter autant de file que l'on a de volume.
        if (!tour_termine) { //Si l'initialisation des 21 file n'est pas terminée.
            queue<int> nouv_file; //Crée une nouvelle file de volume correspondant.
            this->m_map_vcasier_libre.insert({volume_casier, nouv_file}); //Créer le couple {Volume, file} et l'ajoute dans la map.
        }

        this->m_map_vcasier_libre.operator[](volume_casier).push(i); //Ajoute de maniere linéaire l'index du casier dans la file.

        //Augmentation du volume (5, 10, 20, 30, ... , 200).
        if (volume_casier == 5) {
            volume_casier += 5; //passage 5 litre à 10 litre.
        } else  if (volume_casier == 200) { //Dès que ça atteind 200, la boucle recommence à 5L.
            volume_casier = 5;
            tour_termine = true; //Une première tour de boucle est terminé, plus besoin de recrer de file.
        } else {
            volume_casier += 10; //passage de 10 litre par 10 litre.
        }
    }
    cout<< "\n>>>> Initialisation des numéros de casier terminée. >>>>\n"<< endl;
}


//----------------------------------
/** ROLE : Constructeur de VConsigne.
 *  PRECONDITION : L’entrée doit être un entier.
 * @param nbCasierMax nombre de casier que comporte VConsigne au max. */
VConsigne::VConsigne(int nb_casier_max)
{
    this->m_nb_element = nb_casier_max;
    this->m_tab_casier = new Casier[nb_casier_max];
    this->m_nb_casier_utilise = 0;

    init();
}

///Deconstructeur
VConsigne::~VConsigne()
{
    delete [] this->m_tab_casier; //Detruit le tableau de casier.
}


//********************************* GESTION BAGAGE *********************************
/** ROLE : Recherche le volume "clé" supérieur le plus proche d'un volume d'un bagage.
 *  PRECONDITION : L’entrée doit être un reel.
 * @param volume_bagage : Volume du bagage à déposer dans la consigne.
 * @return int : clé volume.
 */
int VConsigne::recherche_cle(double volume_bagage)
{
    int cle;
    if ( volume_bagage < 5 ){ //Cas volume inférieur à 5.
       cle = 5;
    } else {
        cle = volume_bagage / 10; //Division entiere pour obtenir l'unité.
        cle++; //On donne l'unité supérieur.
        cle *= 10; //Pour obtenir la dizaine superieur adequate.
    }
    int taille_file = this->m_map_vcasier_libre.operator[](cle).size(); //Enregistre la taille de la file.

    //Augmente la clé pour trouver le casier au volume supérieur si la liste est vide.
    while(taille_file == 0 && cle != -1) { //Si la taile de la file est vide et si la clé est différérents de moins -1.

        if (cle == 5) { //Cas volume inférieur à 5.
            cle += 5;
        } else {
            cle += 10;
        }
        taille_file = this->m_map_vcasier_libre.operator[](cle).size();

        //Si la clé arrive au volume max, la clé prends -1.
        if (cle >= 200) {
            cle = -1;
        }
    }
    return cle;
}

//----------------------------------
/** ROLE : Dépose un bagage dans VConsigne.
 * PRECONDITION : L’entrée doit être un Bagage crée et initlisaisé.
 * @param b bagage donné.
 * @return Ticket du bagage.
 */
Ticket VConsigne::deposer_bagage(Bagage b)
{
    //Variable
    Ticket t;
    int cle = recherche_cle(b.getMVolume());

    //Debut
    try {
        if (cle == -1 && b.getMVolume() <= 200) { //Test si aucune clé ne correspond et que le volume n'est pas supérieur au volume max.
            throw string("\n/!\\  ERREUR : Tous les casiers sont déjà occupés, " + b.getMNomBagage() +
                         " ne peut être déposé."); //Tous les casiers adéquats sont occupés.

        } else if (cle == -1) {
            throw string("\n/!\\  ERREUR : Le volume du sac est trop élevé, " + b.getMNomBagage() +
                         " ne peut être déposé."); //Erreur en cas de volume trop important.
        } else {
            //Renvoie l'index du casier libre dont la dernière utilisation est la plus ancienne avec le volume correspondant.
            int index_casier = this->m_map_vcasier_libre.operator[](cle).front();
            this->m_map_vcasier_libre.operator[](cle).pop(); //Défile le casier index correspondant à la file "cle".
            this->m_tab_casier[index_casier].bagage = &b; //Affectation du casier par le bagage "b".
            this->m_tab_casier[index_casier].est_Libre = false; //Le casier devient occupé.
            this->m_nb_casier_utilise++;

            this->m_map_ticket_indice.insert({t, index_casier}); //On insère dans la map pour hasher le casier.

            cout << "\nINFORMATION : Le dépot du bagage " << b.getMNomBagage() << " a bien été effectué." << endl;
        }
    }
    catch (string const &chaine) //Traitements des erreurs.
    {
        t.ticket_null();
        cout << chaine << endl;
    }
    return t;
}

//----------------------------------
/** ROLE : Retire un bagage de VConsigne si le ticket présenté est valable.
 * PRECONDITION : L’entrée doit être un Ticket crée et initialisé.
 * @param t Ticket du bagage.
 */
void VConsigne::retirer_bagage(Ticket t)
{
    //Variable
    int index_casier; //index du caiser ou se trouve le bagage.

    //Debut
    try {
        if (!t.get_est_Valable()) { //Vérifie si le ticket est valable.
            throw string("\n/!\\  ERREUR : Le ticket est invalide ! "); //Erreur en cas de mauvais ticket.

        } else {

            index_casier = this->m_map_ticket_indice.operator[](t); //Ressort de la map l'index du casier à l'aide du ticket (hash).
            int cle = this->m_tab_casier[index_casier].volume_casier;//Recherche de la clé de la file correspondante.

            this->m_tab_casier[index_casier].est_Libre = true; //Mets le casier en libre.
            this->m_map_vcasier_libre.operator[](cle).push(index_casier); //Ajoute à la file l'index du casier nouvellement libre.

            this->m_nb_casier_utilise--;
            this->m_map_ticket_indice.erase(t);

            cout << "\nINFORMATION : Le retrait du bagage à bien été effectué.\n" << endl;
        }
    }
    catch (string const &chaine) {
        cout << chaine << endl;
    }
}


//************************************ AFFICHAGE *************************************
/** ROLE : Affiche la liste des casier disponible file par file.
 * @return texte d'affichage. */
string VConsigne::affichage_consigne()
{
    //Variable
    ostringstream affichage;
    affichage << "Volume\tNumeros de casiers  Nombre de casiers libres : " << this->m_nb_element - this->m_nb_casier_utilise << "\n";
    int incrementation = 5;

    //Pour chaque volume (5, 10, 20,...).
    for (int i = 5; i <= 200; i += incrementation) {
        affichage << i << "\t:\t ";
        int taille_file = this->m_map_vcasier_libre.operator[](i).size(); //Donne la taille de la fille.

        //parcours la file i. En concaténant le premier élément puis en le refillant au début.
        for (int j = 0; j < taille_file; j++) {
            affichage << this->m_map_vcasier_libre.operator[](i).front();
            int num_cas = this->m_map_vcasier_libre.operator[](i).front();
            this->m_map_vcasier_libre.operator[](i).push(num_cas); //Permet de ne pas perdre les élément ni de les mélanger.
            this->m_map_vcasier_libre.operator[](i).pop();
            affichage << " ";
        }
        affichage << "\n";
        if (i == 10) { //Incrémentation de 10 en 10 litre.
            incrementation = 10;
        }
    }
    return affichage.str();
}

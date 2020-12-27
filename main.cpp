#include <random>
#include "Consigne.hpp"
#include "VConsigne.hpp"
#include "BagageRectangle.hpp"
#include "BagageCylindre.hpp"
#include "BagagePyramide.hpp"

using namespace std;


int main() {

    cout << "******************************************** 1 ER PARTIE *******************************************" << endl;
    //VARIABLES
    Consigne c(6);

    Ticket ticket_1, ticket_2, ticket_3, ticket_4, ticket_5, ticket_6, ticket_7, ticket_8;
    BagageSimple sac, valise, cartable, cabas, besace, valisette, vanity;


    //-----------------------------------------------
    //DEBUT

    //Initialisation des 7 bagages
    sac.nom_bagage = "\"Sac a main\"";
    valise.nom_bagage = "\"Valise de voyage\"";
    cartable.nom_bagage = "\"Cartable d'écolier\"";
    cabas.nom_bagage = "\"Cabas de course\"";
    besace.nom_bagage = "\"Besace\"";
    valisette.nom_bagage = "\"Valisette de petit deplacement\"";
    vanity.nom_bagage = "\"Bagage de soute vanity\"";


    //-----------------------------------------------
    //Dépot des 6 bagages
    cout << "------------------------------ Dépot des 6 bagages --------------------------------" << endl;
    ticket_1 = c.deposer_bagage(sac);
    ticket_2 = c.deposer_bagage(valise);
    ticket_3 = c.deposer_bagage(cartable);
    ticket_4 = c.deposer_bagage(cabas);
    ticket_5 = c.deposer_bagage(besace);
    ticket_6 = c.deposer_bagage(valisette);



    /* Bagage en trop, le dépot ne peut se faire, il faut attendre le retrait d'un autre bagage
     * Erreur traité dans le bloc try/catch
     * Genration d'un ticket invalide
     */
    cout << "\n\n-------------------------- Erreur de place ---------------------------------------" << endl;
    ticket_7 = c.deposer_bagage(vanity);

    //Retrait du vanity ainsi impossible car ticket_7 invalide au retrait
    //Egalement traité dans un try/catch

    cout << "\n\n-------------------------- Erreur de ticket --------------------------------------" << endl;
    vanity = c.retirer_bagage(ticket_7);



    /* Nouvelle tentative de dépot
     * PROBLEME : Du fait de l'invalidation du ticket, la variable "vanity" est écrasé, on ne peut donc plus redéposer cet objet
     */
    cout << "\n\n-------------------------- Retrait d'un bagage -----------------------------------" << endl;
    valise = c.retirer_bagage(ticket_5); //Casier dont la dernière utilisation est la plus ancienne : indice 4.

    cout << "\n\n-------------------------- Dépot de la valise vanity écrasé ----------------------" << endl;
    ticket_7 = c.deposer_bagage(vanity);//Variable "vanity" écrasé o

    cout << "\n\n-------------------------- retrait de la valise vanity ---------------------------" << endl;
    vanity = c.retirer_bagage(ticket_7);


    cout << "\n\n-------------------------- Casier le plus ancien ---------------------------------" << endl;
    cout << c.afficher_premier_element() << endl;


    cout << "******************************************** 1 ER PARTIE FIN *******************************************" << endl;




    cout << "\n\n********************************************* 2 EME PARTIE *********************************************" << endl;

    //VARIABLES
    VConsigne v_consigne(42);

    //Bagages
    BagageRectangle cart("Cartable", 29.5, 15, 7.25); //Les entrees se font en "cm".
    BagageRectangle gla("Glaciere de dejeuner",20);

    BagageCylindre sport("Sac de sport", 99, 22.5);

    BagagePyramide main("Sac à main", 30, 22);
    BagagePyramide balu("Baluchon de voyage", 15.5, 30, 51);

    //Ticket
    Ticket v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12;


    //-----------------------------------------------
    //DEBUT

    cout << v_consigne.affichage_consigne() << endl;


    cout << "------------------------------ Dépot des 5 bagages --------------------------------" << endl;
    v1 = v_consigne.deposer_bagage(cart);
    cout << "Volume du "<< cart.getMNomBagage() << " : " << cart.getMVolume() << endl;
    v2 = v_consigne.deposer_bagage(gla);
    cout << "Volume du "<< gla.getMNomBagage() << " : " << gla.getMVolume() << endl;
    v3 = v_consigne.deposer_bagage(sport);
    cout << "Volume du "<< sport.getMNomBagage() << " : " << sport.getMVolume() << endl;
    v4 = v_consigne.deposer_bagage(main);
    cout << "Volume du "<< main.getMNomBagage() << " : " << main.getMVolume() << endl;
    v5 = v_consigne.deposer_bagage(balu);
    cout << "Volume du "<< balu.getMNomBagage() << " : " << balu.getMVolume() << "\n" << endl;

    /* Ici, on affiche la consigne avec les 5 indices de casiers retirés.
     * Les 5 bagages déposés précédement sont stokés dans ces casiers de volume adequats.
     *
     * → cartable (volume 32) déposé dans le casier 4 de volume 40.
     * → glaciere (volume 80) déposé dans le casier 9 de volume 90.
     * → sac de sport (volume 157) deposé dans le casier 16 de volume 160.
     * → sac a main (volume 2) déposé dans le casier 0 de volume 5.
     * → baluchon (volume 79) déposé dans le casier 8 de volume 80. */
    cout << "\n-------- AFFICHAGE CASIERS LIBRES --------\n" << endl;
    cout << v_consigne.affichage_consigne() << endl;



    cout << "\n\n---------------------------------- Retrait d'un bagage ----------------------------------" << endl;
    /* TEST : Bagage precedement déposé est retiré.
     * Le numéro de casier nouvellement vide est enfilé a la fin.
     * Ceci permet qu'a chaque dépot, le casier d'on l'utilisation est la plus ancienne est choisi.
     */
    v_consigne.retirer_bagage(v1);
    cout << v_consigne.affichage_consigne() << endl; //Numero casier "4" rajouté dans la file de clé "40" en derniere position.
    v6 = v_consigne.deposer_bagage(cart);
    cout << "Nouveau casier occupé : \"25\". " ;



    cout << "\n\n----------------------------------- Dépot de bagage -----------------------------------" << endl;
    /* TEST : cas ou pour un bagage, la categorie de volume correspondante est pleine. On passe alors au volume supérieur. */
    BagagePyramide pochette("Pochette", 28.6, 21.9);
    BagagePyramide sac_tissue("Sac en tissue", 25.87, 36.01);

    v7 = v_consigne.deposer_bagage(pochette); //File de volume 5L pleine.
    cout << "Volume du "<< pochette.getMNomBagage() << " : " << pochette.getMVolume() << endl;
    v8 = v_consigne.deposer_bagage(sac_tissue); //Placé dans le casier "1".
    cout << "Volume du "<< sac_tissue.getMNomBagage() << " : " << sac_tissue.getMVolume() <<  endl;
    cout << "Catégorie de 5L pleine, bagage déposé dans la catégorie 10L casier \"1\". \n"<< endl;

    cout << v_consigne.affichage_consigne() << endl;



    cout << "\n\n-------------------------- Cas d'erreur 1 -----------------------------------" << endl;
    /* TEST : Cas ou la categorie de volume maximal est pleine ( 200 Litres ).
     * Il est donc impossible de déposer bagage.
     */
    BagageRectangle pack("Pack",26.9);
    BagageCylindre vivre("Sac de vivre", 110.65, 23.6);
    BagageRectangle voy("Sac de voyage", 35, 30.8, 18); //Ce bagage ne pourra être déposé.



    v9 = v_consigne.deposer_bagage(pack);
    cout << "Volume du "<< pack.getMNomBagage() << " : " << pack.getMVolume() << endl;
    v10 = v_consigne.deposer_bagage(vivre);
    cout << "Volume du "<< vivre.getMNomBagage() << " : " << vivre.getMVolume() <<  endl;
    v11 = v_consigne.deposer_bagage(voy);
    cout << "Volume du "<< voy.getMNomBagage() << " : " << voy.getMVolume() << "\n" <<  endl;

    cout << v_consigne.affichage_consigne() << endl;


    cout << "\n\n-------------------------- Cas d'erreur 2 -----------------------------------";
    /* TEST : Cas ou le bagage est d'un volume supérieur au volume maximal.
     * Il ne sera jamais déposé. */
    BagageCylindre gros_sac("gros sac", 104, 27.6);
    v12 = v_consigne.deposer_bagage(gros_sac);
    cout << "\nVolume du "<< gros_sac.getMNomBagage() << " : " << gros_sac.getMVolume() << ", supérieur à la capacité maximale de la consigne.\n" <<  endl;

    cout << v_consigne.affichage_consigne() << endl;

    cout << "******************************************** 2 EME PARTIE FIN *******************************************" << endl;

    //TODO
    //faire fonctionner base YES

    /* CAS :
     * plus de casier a dequat, inserer dans categories sup
     * bagage trop grand pour la consigne sup = 200 L
     *
     */
    // montrer pas d'erreurs si consignes vide ( try catach a teste)

    // montrer prise du bon volume YES et <<<<<<<<<  du plus vieux ! <<<<<<<<<<<<
    // ticket erreur tester invalidation
    return 0;

}

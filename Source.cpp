//Decaux Kevin C1

#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <time.h>


string nom, niv, prem;
int nb_allumettes;
void saisie();
void affichage();

void miseAjour(int nb);
void jeualterne();

//fonction de saisie de paramètre
//qui contrôle chaque paramètre saisie 
// de façon globale 

void saisie()
{
    char nb_allumette2[30];
    cout << "bonjour quel est votre nom?" << endl;
    cin >> nom;                                                 /* saisie du nom */
    cout << endl << "quelle est la difficulté que vous souhaitez ?(naïf ou expert, N/E)" << endl;
    cin >> niv;
    while ((niv != "n") and (niv != "N") and (niv != "e") and (niv != "E")) {
        cout << endl << "La difficulté a été mal indiquée, veuillez nous la réindiquer avec les caractères n ou e." << endl;
        cin >> niv;                                             /*saisie contrôlée de la difficulté*/
    }
    cout << endl << "Avec combien d'allumettes voulez-vous jouer?" << endl;
    cin >> nb_allumette2;
    nb_allumettes = atoi(nb_allumette2);    /*on garde uniquement les chiffre rentrer*/
    while ((nb_allumettes <= 0) or (nb_allumettes > 30)) {
        cout << endl << "la quantité d'allumette doit être comprise entre 0 et 30, veuillez en rentrer une nouvelle" << endl;
        cin >> nb_allumette2;
        nb_allumettes = atoi(nb_allumette2);             /*saisie contrôlée du nombre d'allumette par chaine de caractère */
    }
    cout << endl << "qui commence? (ordinateur ou " << nom << "?)" << endl;
    cin >> prem;
    while ((prem != "ordinateur") and (prem != nom)) {
        cout << endl << "veuillez préciser la personne qui commence ( entre ordinateur et " << nom << "?)" << endl;
        cin >> prem;                                    /*saisie contrôlée du joueur qui commence la partie */
    }
    cout << endl;
}


//fonction qui affiche le nombre d'allumette encore restante
// grâce à la variable globale qui ressence le nombre d'allumette

void affichage()
{
    int reste;
    reste = nb_allumettes % 5;
    for (int i = 1; i <= nb_allumettes / 5; i = i + 1) {
        for (int j = 1; j <= 5; j = 1 + j) {

            cout << "|";            /*affichage des allumettes par groupe de 5*/
        }
        cout << endl;
    }
    for (int u = 1; u <= reste; u = u + 1) {
        cout << "|";          /* affichage de la dernière ligne d'allumettes si elle est inférieure à 5 */
    }
    cout << endl;
}


// fonction permettant la mise à jour du nombre d'allumettes (variable globale) restante 
//en prenant en paramètre les allumettes a retiré

void miseAjour(int nb)
{
    nb_allumettes = nb_allumettes - nb;     /* mise à jour de la variable global contenant le nombre d'allumettes */
    cout << endl << "il reste " << nb_allumettes << " allumettes:" << endl;
    affichage();                /* appel de la fonction d'affichage après le retret d'allumettes */
}



//fonction qui permet à l'ordinateur de choisir combien d'allumettes retirer en fonction du niveau
int joueOrdi(string niv)
{
    int alleatoire;
                            /* délai pour un affichage plus doux */
    cout << endl << "Ordi joue" << endl;
    srand(time(NULL));
    if ((niv == "n") or (niv == "N")) {
        if (nb_allumettes <= 3)
        {
            switch (nb_allumettes)       /* test pour connaitre la finalité de la partie*/
            {
            case 3:
                alleatoire = 2;
                break;
            case 2:
                alleatoire = 1;
                break;
            case 1:
                alleatoire = 1;
                break;
            }

        }
        else
        {
            alleatoire = rand() % 3 + 1;
            while (alleatoire > nb_allumettes) {
                alleatoire = rand() % 3 + 1;        /* choix aléatoire d'un nombre d'allumettes contrôlée*/
            }
        }
        
        cout << endl << "l'ordinateur retire " << alleatoire << " allumettes" << endl;
        return alleatoire;
    }
    else {
        if (((nb_allumettes % 4) - 1) != 0) {       /* test sur le nombre d'allumettes pour savoir si le complément à 4 est possible */
            cout << endl << "l'ordinateur retire " << ((nb_allumettes - 1) % 4) << " allumettes" << endl;
            return ((nb_allumettes - 1) % 4);
        }
        else {
            alleatoire = (rand() % 3 + 1);
            while (alleatoire > nb_allumettes) {
                alleatoire = (rand() % 3 + 1);
            }
            cout << endl << "l'ordinateur retire " << alleatoire << " allumettes" << endl;
            return alleatoire;              /* renvoi d'un nombre aléatoire contrôlé car le joueur a joué le produit a 4 du nombre d'allumette */
        }
    }
    return 0;

}


// fonction permettant la saisie contrôlée du nombre d'allumette que le joueur veut retiré ainsi que le test d'abandon


int joueJoueur(string nom)
{
    int nb, sortieabbandon = 0;
    char nbtest[10], nbabandon[10] = "0";  /* variable permettant le test pour connaître le nombre d'allumettes à retiré */
    string abandon;     /* variable utilisée pour savoir si le joueur abandonne ou non */
   
    cout << endl << nom << " joue" << endl;
    cout << endl << "combien voulez-vous retirer d'allumettes?" << endl;
    cin >> nbtest;
    nb = atoi(nbtest);      /* saisie du nombre d'allumettes à retiré*/
    if (strcmp(nbtest, nbabandon) == 0) {  /* test pour savoir si le nombre d'allumettes correspond à celui pour abandonné*/
        nb = 0;
    }
    abandon = "non";
    while ((nb > 3) or (nb > nb_allumettes) or (nb < 1))
    {
        if (nb == 0) {
            cout << endl << "voulez-vous abandonner?" << endl;
            cin >> abandon;
            if (abandon == "oui" || abandon == "o" || abandon == "O" || abandon == "OUI")       /*saisie et test si le joueur veut abandonner la partie */ {
                cout << endl << "l'abandon est confirmé!" << endl;
                nb = 1;
                sortieabbandon = 1;
            }
            else {
                cout << endl << "veuillez repréciser le nombre d'allumettes à retirer" << endl;
                cin >> nbtest;
                nb = atoi(nbtest);
                if (strcmp(nbtest, nbabandon) == 0)
                {
                    nb = 0;                     /*contrôle de la saisie du nombre d'allumettes si le joueur refuse d'abandonner*/
                }
            }
        }
        else {

            cout << endl << "la valeur est incorrecte veuillez en ressaisir une valeur" << endl;
            cin >> nbtest;
            nb = atoi(nbtest);          /* contrôle de la saisie du nombre d'allumettes */
            if (strcmp(nbtest, nbabandon) == 0)  /* contrôle pour demander au joueur s'il veut abandonner */
            {
                nb = 903;
            }
        }
    }
    if (sortieabbandon == 1) {
        nb = -1;                        /* si le joueur abandonne on renvoie une valeur prédéfinie pour arrêter le jeu */
    }
    return nb;
}

// procédure faisant jouer de façon alternative le joueur et l'ordinateur en utilisant les autres procédures ou fonctions
// de plus la procédure affiche le vainqueur ou l'abandon du joueur 

void jeualterne()
{
    int tour, nb;
    if (prem == nom)
    {                       /* définition si le joueur commence ou pas */
        tour = 1;
    }
    else
    {
        tour = 0;
    }
    while (nb_allumettes != 0)          /* le jeu fonctionne tant qu'il y a des allumettes */
    {
        if (tour == 0)
        {
            nb = joueOrdi(niv);
            
            miseAjour(nb);
            tour = 1;
        }
        else {

            nb = joueJoueur(nom);
            if (nb == -1)           /* test si le nombre d'allumettes a retirer récupéré est celui pour l'abandon */
            {
                tour = 3;
                nb_allumettes = 0;
            }
            else
            {
                
                miseAjour(nb);
                tour = 0;
            }
        }
    }
    switch (tour)       /* test pour connaitre la finalité de la partie*/
    {
    case 0:
        cout << endl << "Le vainqueur est l'ordinateur !" << endl;
        break;
    case 1:
        cout << endl << "Le vainqueur est " << nom << " !" << endl;
        break;
    default:
        cout << endl << "le joueur a donc abandonné !";
        break;
    }

}




int main()
{
    saisie();
    affichage();
    jeualterne();

}

















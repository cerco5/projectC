#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

//*******************************************************************
//**     Fonction  : information sur toutes les voitures           **
//**     Parametre : structures  le nombre de voitures             **
//**	 Traitement: infos des voiture                             **
//*******************************************************************

void infosTtesVoitures(Voiture *voit, int n){
    int i;


    printf("Matricules \t Etat \n");
    for (i=0; i<n; i++){
        if (voit[i].etat=='o'){
            printf("%s \t %s \t Loue \n", voit[i].mat, voit[i].model);
        } else {
            printf("%s \t %s \t Non loue \n", voit[i].mat, voit[i].model);
        }
    }
}

//*******************************************************************
//**     Fonction  : fin du programme                              **
//**     Parametre : structures  le nombre de voitures             **
//**	 Traitement: fin ou menu du programme                      **
//*******************************************************************

void fin(Voiture *voitures, int n){
    char res;
    do {
        printf("Voudrez vous afficher le menu? o/n ");
        scanf("%s", &res);
    } while (res!='o' && res!='n');


    if (res =='n'){
        exit(0);
    } else {
        menu(voitures, n);
    }
}

//*******************************************************************
//**     Fonction  : menu du programme                             **
//**     Parametre : structures  le nombre de voitures             **
//**	 Traitement: menu du programme                             **
//*******************************************************************


void menu(Voiture *voitures, int n){
    int n1;
    char matricule;

    system("cls");
    printf("Hello world!\n\n");
    printf("-------------MENU-------------\n");
    printf("\t 1 : Louer une voiture\n");
    printf("\t 2 : Retour d'une voiture\n");
    printf("\t 3 : Etat d'une voiture\n");
    printf("\t 4 : Etat du parc de voiture\n");
    printf("\t 5 : Sauvegarder l'etat du parc\n");
    printf("\t 0 : Fin du programme\n");

    do {
        printf("Veuillez choisir un menu ");
        scanf("%d", &n1);
    } while (n1 < 0 || n1 > 5) ;

    switch (n1){
    case 1:
        printf("Cette Option vous permet de louer une voiture \n");

        infosTtesVoitures(voitures, n);

        printf("Veuillez entrer le numero matricule de la voiture a louer ");
        scanf("%s", &matricule);

        louer(&matricule, voitures, n);
        fin(voitures, n);
        break;

    case 2:
        printf("Cette Option vous permet de retourner une voiture \n");

        infosTtesVoitures(voitures, n);

        printf("Veuillez entrer le numero matricule de la voiture a retourner \n");
        scanf("%s", &matricule);

        retour(&matricule, voitures, n);
        fin(voitures, n);
        break;

    case 3:
        printf("Cette Option vous permet davoir des informations sur une voiture \n");

        infosTtesVoitures(voitures, n);

        printf("Veuillez entrer le numero matricule de la voiture dont vous voulez les renseignements \n");
        scanf("%s", &matricule);

        etatVoiture(&matricule, voitures, n);
        fin(voitures, n);
        break;

    case 4:
        printf("Voici les informations sur notre parc \n");
        etatParc(voitures, n);
        fin(voitures, n);
        break;

    case 5:
        printf("Nous allons sauvegarder l'etat de votre parc dans un fichier appele ParcSave \n");

        etatParc(voitures, n);
        save(voitures, n);
        fin(voitures, n);
        break;

    default:
        fin(voitures, n);
        break;
    }
}

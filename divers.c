#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

void infosTtesVoitures(Voiture *voit, int n){
    int i;


    printf("Matricules \t Etat \n");
    for (i=0; i<n; i++){
        if (voit[i].etat=='o'){
            printf("%s \t Loue \n", voit[i].mat);
        } else {
            printf("%s \t Non loue \n", voit[i].mat);
        }
        //fprintf(f, "Model %s \t Matricule %s \t Kilo %f \t Etat %c \n", voit[i].model,voit[i].mat,voit[i].kilo,voit[i].etat);
        //printf("Model %s Matricule %s Kilo %f \n", voit[i].model, voit[i].mat, voit[i].kilo);

    }
}

void infosVoituresLocation(Voiture *voitures, int n){
    int i;

    printf("Matricules \t Etat: \n");
    for (i=0; i<n; i++){
        if (voitures[i].etat=='o'){
            printf("%s \t A retourner \n", voitures[i].mat);
        }
    }
}

void infosVoituresModele(Voiture *voitures, int n){
    int i;

    printf("Matricules \t Modele: \n");
    for (i=0; i<n; i++){
        printf("%s \t %s \n", voitures[i].mat, voitures[i].model);
    }
}

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

//********************************************************
//**	Fonction  : Menu					**
//**	Parametre : Structure Voiture    				**
//**	Traitement: Verifier si la liste de matricule   **
//**                est vide ou pas                     **
//**	Retourne  : 0 si la liste et vide et1 sinon     **
//********************************************************

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

   /* do {
        printf("Veillez choisir un menu ");
        scanf("%d", &n1);
    } while (n1 < 0 || n1 > 5) ;

    system("cls");
    printf("Hello world!\n\n");
    printf("-------------MENU-------------\n");
    printf(" 1 : Louer une voiture\n");
    printf(" 2 : Retour d'une voiture\n");
    printf(" 3 : Etat d'une voiture\n");
    printf(" 4 : Etat du parc de voiture\n");
    printf(" 5 : Sauvegarder l'etat du parc\n");
    printf(" 0 : Fin du programme\n");*/

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

        infosVoituresLocation(voitures, n);

        printf("Veuillez entrer le numero matricule de la voiture a retourner \n");
        scanf("%s", &matricule);

        retour(&matricule, voitures, n);
        fin(voitures, n);
        break;

    case 3:
        printf("Cette Option vous permet davoir des informations sur une voiture \n");

        infosVoituresModele(voitures, n);

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
        //save();
        etatParc(voitures, n);
        save(voitures, n);
        fin(voitures, n);
        break;

    default:
        fin(voitures, n);
        break;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "prototype.h"

//*******************************************************************
//**     Fonction  : creation d'une voiture                        **
//**     Parametre : structures et le nombre de voitures a creer   **
//**	 Traitement: cree une voiture                              **
//*******************************************************************

void creer(Voiture *voit, int n){
    int i, j;
    char c[]="CERCO";
    char c1[]="cerco";
    char c2[]="aa0000";

    if (voit == NULL){
        exit(EXIT_FAILURE);
    } else {
        for (i=0; i<n; i++){
            printf("\nVeuillez entrer les informations de la voiture %d \n", i+1);
            do{
                printf("Modele exemple CERCO: ");
                scanf("%s", voit[i].model);
            } while (strcmp(voit[i].model, c) == 0 || strcmp(voit[i].model, c1) == 0);

            do{
                printf("Matriculation exemple aa0000: ");
                scanf("%s", voit[i].mat);


                for (j=0; j<i; j++){
                    while (strcmp(voit[j].mat, voit[i].mat)==0){
                        printf("Votre matricule existe deja Veuillez entrer un autre matricule exemple aa0000: ");
                        scanf("%s", voit[i].mat);
                    }
                }
            } while (strcmp(voit[i].mat,c2 )== 0);

            printf("Kilometre parcourue exemple 40000.78 contre exemple 10km: ");
            scanf("%f", &voit[i].kilo);

            do{
                printf("Loue ou pas (o/n): ");
                scanf("%c", &voit[i].etat);
            } while ((voit[i].etat!='o')&&(voit[i].etat!='n'));

            voit->suivant=NULL;
        }
    }
    printf("Vous venez d'enregistrer %d voitures \n", n);
}

//*******************************************************************
//**     Fonction  : ajout d'une nouvelle voiture                  **
//**     Parametre : structures  le nombre de voitures au depart   **
//**                 et le nombre de voitures au total             **
//**	 Traitement: ajout de voiture                              **
//*******************************************************************

void recreer(Voiture *voit, int n1, int n){
    int i, j;
    char c[]="CERCO";
    char c1[]="cerco";
    char c2[]="aa0000";

    if (voit == NULL){
        exit(EXIT_FAILURE);
    } else {
        for (i=n1; i<n; i++){
            printf("\nVeuillez entrer les informations de la voiture %d \n", i+1);
            do{
                printf("Modele exemple CERCO: ");
                scanf("%s", voit[i].model);
            } while (strcmp(voit[i].model, c) == 0 || strcmp(voit[i].model, c1) == 0);

            do{
                printf("Matriculation exemple aa0000: ");
                scanf("%s", voit[i].mat);


                for (j=0; j<i; j++){
                    while (strcmp(voit[j].mat, voit[i].mat)==0){
                        printf("Votre matricule existe deja Veuillez entrer un autre matricule exemple aa0000: ");
                        scanf("%s", voit[i].mat);
                    }
                }
            } while (strcmp(voit[i].mat,c2 )== 0);

            printf("Kilometre parcourue exemple 40000.78 contre exemple 10km: ");
            scanf("%f", &voit[i].kilo);

            do{
                printf("Loue ou pas (o/n): ");
                scanf("%c", &voit[i].etat);
            } while ((voit[i].etat!='o')&&(voit[i].etat!='n'));

            voit->suivant=NULL;
        }
    }
    printf("Vous venez d'enregistrer %d voitures \n", n);
}

//*******************************************************************
//**     Fonction  : location de  voiture                          **
//**     Parametre : structures  le nombre de voitures             **
//**                 et matricule de la voiture a louee            **
//**	 Traitement: location de voiture                           **
//*******************************************************************

void louer(char *matricule, Voiture *voit, int n){
    int i, v=-5;
    char res;

    for (i=0; i<n; i++){
        if (strcmp(voit[i].mat,matricule)==0){
            v=i;
            if (voit[i].etat=='o'){
                printf("Voiture deja louee \n");
            } else {
                printf("Cette voiture est disponible et voila les caracteristiques: \n Modele: %s\tKilometre parcouru: %.2f Km \n", voit[v].model, voit[v].kilo);
                do{
                    printf("Voudrez vous la louer? ");
                    scanf("%s", &res);
                } while ((res!='o')&&(res!='n'));
                if (res=='o'){
                    voit[i].etat='o';
                    printf("Vous venez de louer cette voiture \n");
                }else {
                    printf("Vous avez annule la demande de location \n");
                }
            }
        }
    }

    if (v==-5){
        printf("Voiture non enregistre \n");
    }
}

//*******************************************************************
//**     Fonction  : retour de  voiture                            **
//**     Parametre : structures  le nombre de voitures             **
//**                 et matricule de la voiture a retourner        **
//**	 Traitement: retour de voiture                             **
//*******************************************************************

void retour(char *matricule, Voiture *voit, int n){
    int i, v=-5;
    float kilo;

    for (i=0; i<n; i++){
        if (strcmp(voit[i].mat,matricule)==0){
            v=i;
            if (voit[i].etat=='n'){
                printf("Cette voiture n'etait pas louee \n");
            } else {
                printf("Combien de kilometres cette voiture a-t-elle parcouru ? " );
                scanf("%f", &kilo);

                voit[i].kilo=voit[i].kilo+kilo;
                voit[i].etat='n';

                printf("Cette voiture est de nouveau disponible: \nModele: %s Kilometres parcourus: %.2f Km \n", voit[v].model, voit[v].kilo);
            }
        }
    }

    if (v==-5){
        printf("Voiture non enregistree \n");
    }
}

//*******************************************************************
//**     Fonction  : etat de  voiture                              **
//**     Parametre : structures  le nombre de voitures             **
//**                 et matricule de la voiture a voir             **
//**	 Traitement: etat de voiture                               **
//*******************************************************************

void etatVoiture(char *matricule, Voiture *voit, int n){
    int i, v=-5;

    for (i=0; i<n; i++){
        if (strcmp(voit[i].mat,matricule)==0){
            v=i;
            printf("Les informations de votre voiture \n");
            if (voit[v].etat=='o'){
                printf("Modele: %s \t Kilometres parcourus: %.2f Km. Cette voiture n'est pas disponible en ce moment \n", voit[v].model, voit[v].kilo);
            } else {
                printf("Modele: %s \t Kilometres parcourus: %.2f Km. Cette voiture est disponible \n", voit[v].model, voit[v].kilo);
            }
        }
    }

    if (v==-5){
        printf("Voiture non enregistree ");
    }
}

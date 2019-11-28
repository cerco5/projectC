#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "prototype.h"

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
                scanf("%s", &voit[i].etat);
            } while ((voit[i].etat!='o')&&(voit[i].etat!='n'));

            voit->suivant=NULL;
        }
    }
    printf("Vous venez d'enregistrer %d voitures \n", n);
}

void louer(char *matricule, Voiture *voit, int n){
    int i, v=-5;
    char res;

    for (i=0; i<n; i++){
        if (strcmp(voit[i].mat,matricule)==0){
            v=i;
        }
    }

    if (v==-5){
        printf("Voiture non enregistre ");
    } else {
        if (voit[v].etat=='o'){
            printf("Voiture deja louee");
        } else {
            printf("Cette voiture est disponible et voila les caracteristiques: \n Modele: %s\tKilometre parcouru: %.2f Km \n", voit[v].model, voit[v].kilo);
            do{
                printf("Voudrez vous la louer? ");
                scanf("%s", &res);
            } while ((res!='o')&&(res!='n'));
            if (res=='o'){
                voit[v].etat="o";
                printf("%c", voit[v].etat);
                printf("Vous venez de louer cette voiture");
            } else {
                printf("Vous avez annule la demande de location");
            }
        }
    }
}

void retour(char *matricule, Voiture *voit, int n){
    int i, v=1000;
    float kilo;

    for (i=0; i<n; i++){
        if (strcmp(voit[i].mat,matricule)==0){
            v=i;
        }
    }

    if (v==1000){
        printf("Voiture non enregistree ");
    } else {
        if (voit[v].etat=='n'){
            printf("Cette n'etait pas louee");
        } else {
            printf("Combien de kilometres cette voiture a-t-elle parcouru ? " );
            scanf("%f", &kilo);

            voit[v].kilo=voit[v].kilo+kilo;
            voit[v].etat="n";

            printf("Cette voiture est de nouveau disponible: \nModele: %s Kilometres parcourus: %.2f Km ", voit[v].model, voit[v].kilo);
        }
    }
}

void etatVoiture(char *matricule, Voiture *voit, int n){
    int i, v=1000;

    for (i=0; i<n; i++){
        if (strcmp(voit[i].mat,matricule)==0){
            v=i;
        }
    }

    if (v==1000){
        printf("Voiture non enregistree ");
    } else {
        printf("Les informations de votre voiture \n");
        if (voit[v].etat=='o'){
            printf("Modele: %s \t Kilometres parcourus: %.2f Km. Cette voiture n'est pas disponible en ce moment ", voit[v].model, voit[v].kilo);
        } else {
            printf("Modele: %s \t Kilometres parcourus: %.2f Km. Cette voiture est disponible ", voit[v].model, voit[v].kilo);
        }
    }
}

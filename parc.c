#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

void etatParc(Voiture *voit, int n){
    int i, l=0, nl=0;
    float kilo=0;
    FILE *f=NULL;

    f=fopen("ParcSave.txt", "w+");

    printf("Actuellement nous avons %d voitures dans notre parc \n", n);
    fprintf(f, "Actuellement nous avons %d voitures dans notre parc \n", n);

    for (i=0; i<n; i++){
        if (voit[i].etat=='o'){
            l=l+1;
        }
    }

    for (i=0; i<n; i++){
        if (voit[i].etat=='n'){
            nl=nl+1;
        }
    }

    printf("Nous disposons de %d voitures actuellement en location dont voici les matriculations\n", l);
    fprintf(f, "Nous disposons de %d voitures actuellement en location dont voici les matriculations\n", l);
    for (i=0; i<n; i++){
        if (voit[i].etat=='o'){
            printf("%s \n", voit[i].mat);
        }
    }

    printf("Nous disposons de %d voitures actuellement disponibles dont voici les matriculations\n", nl);
    fprintf(f, "Nous disposons de %d voitures actuellement disponibles dont voici les matriculations\n", nl);

    for (i=0; i<n; i++){
        if (voit[i].etat=='n'){
            printf("%s \n", voit[i].mat);
        }
    }

    for (i=0; i<n; i++){
        kilo=kilo+voit[i].kilo;
    }
    printf("Toutes nos voitures ont parcouru un kilometre moyen de %.2f Km. \n", kilo/n);
    fprintf(f, "Toutes nos voitures ont parcouru un kilometre moyen de %.2f Km. \n", kilo/n);

    fclose(f);
}

/*int save(){
    FILE *f =NULL;

    f= fopen("ParcSave.txt", "r");

    if (f==NULL){
        printf("Fichier introuvable");
    }
}*/

void save(Voiture *voit, int n){
    FILE *f =NULL;
    int i;

    f= fopen("ParcSave.txt", "a+");

    if (f==NULL){
        printf("Fichier introuvable");
    } else {

        for ( i=0; i<n; i++){
                fprintf(f, "Model %s \t Matricule %s \t Kilo %.2f Km \t Etat %c \n", voit[i].model,voit[i].mat,voit[i].kilo,voit[i].etat);
                //printf( "Model %s \t Matricule %s \t Kilo %f \t Etat %s \n", voit[i].model,voit[i].mat,voit[i].kilo,voit[i].etat);
                //fprintf(f, "Model %s \t Matricule %s \t Kilo %f \t Etat %s \n", voit[i].model,voit[i].mat,voit[i].kilo,voit[i].etat);

        }

    }
    fclose(f);
}

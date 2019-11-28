#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "prototype.h"


//*****************************************************************
//****                ********************                     ****
//******            **                    **                  *****
//*********        ***PROGRAMME PRINCIPALE***            **********
//******            **                    **                  *****
//****                ********************                     ****
//*****************************************************************

int main()
{
    int n1, n2, n;
    Voiture *voitures;
    char res;

    //**************************************************************
	//****              Message de bienvenu                *********
	//**************************************************************

    printf("Bienvenue dans notre programme. \nVous allez tout d'abord creer votre parc avec un nombre minimum de voitures \nNb: Le nombre minimum exige est 2 \n");

    //**************************************************************
	//****              Nombre de voitures                 *********
	//**************************************************************

    do {
        printf("Veuillez entrer le nombre de voitures que vous voulez enregistrer ");
        scanf("%d", &n1);
    } while (n1<2);

    //**************************************************************
	//****              Allocation de la memoire           *********
	//**************************************************************

    //voitures = malloc(n1*sizeof(Voiture));
    voitures = calloc(n1, sizeof(Voiture));
    n=n1;




   /* do{
        printf("Voudrez vous enregistrer d'autres voitures? ");
        scanf("%s", &res);
    } while (res != 'o' && res != 'n');

    if (res=='o'){
        printf("\nVeuillez entrer le nombre de voitures que vous voulez enregistrer ");
        scanf("%d", &n2);

        n=n1+n2;
        voitures= realloc(voitures, n*sizeof(Voiture));
        creer(voitures, n2);
        for (int i=0; i<n; i++){
        printf("%s", voitures[i].mat);
    }
    } else {
        n=n1;
    }*/



    //**************************************************************
	//****              Creation de voitures               *********
	//**************************************************************

    creer(voitures, n);
    //**************************************************************
	//****              Fin ou menu                        *********
	//**************************************************************

    fin(voitures, n);
}

#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

void menu(Voiture *voitures, int n);
void creer(Voiture *voit, int n);
void louer(char *matricule, Voiture *voit, int n);
void retour(char *matricule, Voiture *voit, int n);
void etatVoiture(char *matricule, Voiture *voit, int n);
void etatParc(Voiture *voit, int n);
void save(Voiture *voit, int n);
void fin(Voiture *voitures, int n);
void infosTtesVoitures(Voiture *voit, int n);
void infosVoituresLocation(Voiture *voitures, int n);
void infosVoituresModele(Voiture *voitures, int n);

#endif // PROTOTYPE_H_INCLUDED

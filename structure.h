typedef struct Voiture Voiture;
struct Voiture {
    char model[15];
    char mat[15];
    float kilo;
    char etat;
    Voiture *suivant;
};


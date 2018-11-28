#ifndef GENERATION_H
#define GENERATION_H

#define MAX_TAB 20

typedef struct {
  Color couleur;
  char type;// À VIRER
  int num;
  Position position;
  int sorti;
}Cheval;

typedef struct {
  Color couleur;
  char nom[20];
  int num;
}Joueur;

Cheval cheval[MAX_TAB];
Cheval arrivee[MAX_TAB];

Joueur joueur_jouant;


#endif

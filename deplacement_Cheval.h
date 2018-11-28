#ifndef DEPLACEMENT_CHEVAL_H
#define DEPLACEMENT_CHEVAL_H

#define MAX_TAB 20

typedef struct {
  int x;
  int y;
}Position;

typedef struct {
  Position position;
  Cheval *retireCheval;
  int renvoie;
}Deplacement;

typedef struct { // à enlever
  Color couleur;
  char case1;
  int case2;
}Plateau;

Plateau plateau[10][10]; // faire un tableau de case

//faire un pointeur de chaque case vers la case suivante (et le répéter tant que le numéro du dé n'a pas été atteint)


#endif

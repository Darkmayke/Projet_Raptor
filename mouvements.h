#ifndef CADRES_H
#define CADRES_H

#define MAX_TAB 20

typedef enum {
  BLEU,
  ROUGE,
  VERT,
  JAUNE
}color;

typedef struct {
  int x;
  int y;
}Position;

typedef struct {
  char color;
  char type;
  int num;
  Position position;
  int sorti;
}Cheval;

typedef struct {
  Position position;
  Cheval *retireCheval;
  int renvoie;
}Deplacement;

typedef struct {
  color couleur;
  char nom[20];
  int num;
}Joueur;

typedef struct {
  char color;
  char case1;
  int case2;
}Plateau;

Cheval cheval[MAX_TAB], lion[MAX_TAB], singe[MAX_TAB];
Cheval arrivee[MAX_TAB];

Plateau plateau[10][10];

int deplacement(Joueur joueur);
int test_Cheval_select (char type,int num);
int test_Cheval_mort (Cheval Cheval);
int affiche_deplacements_possibles(Joueur joueur,Cheval *Cheval,Position deplacement_possible[],int renvoie);
int test_deplacement_select(int num_deplacement,int num_max);
void deplace_Cheval(Deplacement deplacement,Cheval *Cheval);
void vide_deplacements(Deplacement deplacement_possible[],int num_max);


#endif

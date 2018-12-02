#ifndef DEPLACEMENT_CHEVAL_H
#define DEPLACEMENT_CHEVAL_H

#define MAX_TAB 20

typedef enum {
  BLEU,
  ROUGE,
  VERT,
  JAUNE
}Color;

typedef struct {
  int x;
  int y;
}Position;

typedef struct {
  Color couleur;
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
  Color couleur;
  char nom[20];
  int num;
}Joueur;

typedef struct { // à enlever
  Color couleur;
  char case1;
  int case2;
}Plateau;

typedef struct {
  Position position;
  Cheval cheval;
}Case;



Cheval cheval[MAX_TAB];
Cheval arrivee[MAX_TAB];

Plateau plateau[10][10];
//faire un pointeur de chaque case vers la case suivante (et le répéter tant que le numéro du dé n'a pas été atteint)
int deplacement(Joueur joueur);
int test_Cheval_select (Color couleur,int num);
int test_Cheval_renvoi (Cheval Cheval);
int affiche_deplacements_possibles(Joueur joueur, Cheval *Cheval, Position deplacement_possible[], int renvoie);
void deplace_Cheval(Deplacement deplacement, Cheval *Cheval);
void vide_deplacements(Deplacement deplacement_possible[], int num_max);

Joueur joueur_jouant;

int deplacement_cheval(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num);
int deplacement_renvoie(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num);

void creer_deplacement(Deplacement deplacement_possible[],int x, int y, int num);

#endif

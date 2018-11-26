#ifndef DEPLACEMENT_CHEVAL_H
#define DEPLACEMENT_CHEVAL_H

#define MAX_TAB 20

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
    char color;
    char type;
    int num;
    Position position;
    int sorti;
} Cheval;

typedef struct {
    Position position;
    Cheval *retireCheval;
    int renvoie;
} Deplacement;

typedef struct {
    char color;
    char case1;
    int case2;
} Plateau;

typedef struct {
    char color;
    int num;
} Joueur;

Plateau plateau[10][10];

Cheval cheval[MAX_TAB];
Cheval arrivee[MAX_TAB];

Joueur joueur_jouant;

int deplacement_cheval(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num);
int deplacement_renvoie(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num);

void creer_deplacement(Deplacement deplacement_possible[],int x, int y, int num);

#endif

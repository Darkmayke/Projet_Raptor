#ifndef DEPLACEMENT_Cheval_H
#define DEPLACEMENT_Cheval_H

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
    int shing_shang;
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

Cheval cheval[MAX_TAB], lion[MAX_TAB], singe[MAX_TAB];
Cheval arrivee[MAX_TAB];

Joueur joueur_jouant;

int deplacement_singe(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num);
int deplacement_lion(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num);
int deplacement_cheval(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num);
int deplacement_shing_shang(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num);

void creer_deplacement(Deplacement deplacement_possible[],int x, int y, int num);

#endif

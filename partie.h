#ifndef PARTIE_H
#define PARTIE_H

#define MAX_TAB 20

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
    char color;
    int num;
} Joueur;

typedef struct {
    Position position;
    char color;
    int sorti;
    int num;
} Cheval;

typedef struct {
    char color;
    char case1;
    int case2;
} Plateau;

Cheval cheval[MAX_TAB];
Cheval arrivee[MAX_TAB];

Plateau plateau[10][10];

void nouvelle_partie();
void affiche_plateau();
void test_color(int x, int y);
void affiche_case(int i,int j);
int test_case(int x,int y);
int test_fin_partie();

#endif

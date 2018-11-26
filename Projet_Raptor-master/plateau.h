#ifndef GESTION_TABLEAU_H
#define GESTION_TABLEAU_H

#define MAX_TAB 20

typedef struct {
    char color;
    char case1;
    int case2;
} Plateau;

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

Plateau plateau[10][10];

Cheval cheval[MAX_TAB];
Cheval arrivee[MAX_TAB];

void actualise_plateau();
void rentre_cheval(Cheval Cheval);
void reset_case();

#endif

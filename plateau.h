#ifndef PLATEAU_H
#define PLATEAU_H

#define MAX_TAB 20

typedef enum {
  BLEU,
  ROUGE,
  VERT,
  JAUNE
}Color;

typedef struct {
    Color couleur;
    char case1;
    int case2;
} Plateau;

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
    Color couleur;
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

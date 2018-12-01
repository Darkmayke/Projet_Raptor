#ifndef GENERATION_H
#define GENERATION_H

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
  int num;
  Position position;
  int sorti;
}Cheval;

Cheval cheval[MAX_TAB];
Cheval arrivee[MAX_TAB];

void generation_ecurie();
void creer_cheval(Cheval *Cheval, Color couleur, int num,int x,int y);

#endif

#ifndef PARTIE_H
#define PARTIE_H

#define MAX_TAB 20

typedef enum {
  BLEU,
  ROUGE,
  VERT,
  JAUNE
}Color;

typedef struct {
  Position position;
  Cheval cheval;
}Case;

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

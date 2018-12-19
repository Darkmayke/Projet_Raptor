#ifndef H_H
#define H_H

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
  char nom[20];
  int num;
}Joueur;

typedef struct {
  Color couleur;
  int num;
}Cheval

#endif

#ifndef GENERATION_H
#define GENERATION_H

#define MAX_TAB 20

typedef struct {
  int x;
  int y;

} Position;

typedef struct {
    char color;
    int num;
    Position position;
    int sorti;
} Cheval;

Cheval cheval[MAX_TAB];
Cheval arrivee[MAX_TAB];

void generation_ecurie();
void creer_cheval(Cheval *Cheval,char color, int num,int x,int y);

#endif

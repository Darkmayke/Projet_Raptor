#include <stdio.h>
#include "partie.h"

#include "choix.h"
#include "plateau.h"
#include "h.h"

void nouvelle_partie() {
  int recupDe;
  int recupChoix;

  char coul_e[][10] = { "BLEU", "ROUGE", "VERT", "JAUNE" };
  Joueur player[4];

  choix(&recupDe, &recupChoix, player);
  printf("recupDe = %d | recupChoix = %d\n\n",recupDe, recupChoix);

  printf("Joueur 1: %s ID: %d\n %s\n", player[0].nom, player[0].num, coul_e[player[0].couleur]);
  printf("Joueur 2: %s ID: %d\n %s\n", player[1].nom, player[1].num, coul_e[player[1].couleur]);
  printf("Le Joueur %d commence !\n", recupChoix);
  printf("Le Joueur a lancer et a obtenu un %d !\n", recupDe);//??

  chemin(&recupDe);

  affichePlateau();
}

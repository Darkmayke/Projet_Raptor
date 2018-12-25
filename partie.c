#include <stdio.h>

#include "esthetique.h"
#include "partie.h"
#include "choix.h"
#include "plateau.h"
#include "h.h"

void nouvelle_partie() {
  int recupDe;
  int recupChoix;
  int nb_joueur;

  char coul_e[][10] = { "BLEU", "ROUGE", "VERT", "JAUNE" };
  Joueur player[4];
  Cheval ecurie[16];

  choix(&recupDe, &recupChoix, player, &nb_joueur);
  efface_ecran();
  printf("recupDe = %d | recupChoix = %d\n\n",recupDe, recupChoix);

  printf("Joueur 1: %s ID: %d\n %s\n", player[0].nom, player[0].num, coul_e[player[0].couleur]);
  printf("Joueur 2: %s ID: %d\n %s\n", player[6].nom, player[6].num, coul_e[player[6].couleur]);
  printf("Le Joueur %d commence !\n", recupChoix);
  printf("Le Joueur a lancer et a obtenu un %d !\n", recupDe);

  chemin(&recupDe);

  creer_cheval(ecurie, player, &nb_joueur);

  for (int j4 = 0; j4 < nb_joueur*4; j4++) {
    printf("Num cheval : %d \n sa couleur : %s\n", ecurie[j4].num, coul_e[ecurie[j4].couleur]);
  }// A convertir en fonction à part ou à enlever

  affichePlateau();
}

void creer_cheval(Cheval ecurie[], Joueur player[], int *nb_joueur) {
 int k=0; // ID des chevaux  (cheval n°12)
  for (int i = 0; i < *nb_joueur; i++) {
    for (int j = 0; j < 4; j++) {
      ecurie[k].couleur = player[i].couleur;
      ecurie[k].num = j+1;
      k++;
    }
  }
}

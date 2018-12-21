#include <stdio.h>
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
  printf("recupDe = %d | recupChoix = %d\n\n",recupDe, recupChoix);

  printf("Joueur 1: %s ID: %d\n %s\n", player[0].nom, player[0].num, coul_e[player[0].couleur]);
  printf("Joueur 2: %s ID: %d\n %s\n", player[6].nom, player[6].num, coul_e[player[6].couleur]);
  printf("Le Joueur %d commence !\n", recupChoix);
  printf("Le Joueur a lancer et a obtenu un %d !\n", recupDe);

  chemin(&recupDe);

  creer_cheval(ecurie, player, &nb_joueur);

  for (int j4 = 0; j4 < nb_joueur*4; j4++) {
    printf("Cheval 1: num cheval : %d \n sa couleur : %s\n", ecurie[j4].num, coul_e[ecurie[j4].couleur]);

  }

  affichePlateau();
}


/*void generation_ecurie() {
    //CRÉATION DES CHEVAUX JOUEUR JAUNE
    creer_cheval(&cheval[1],'J',1,2,1);
    creer_cheval(&cheval[2],'J',2,3,2);
    creer_cheval(&cheval[3],'J',3,4,3);
    creer_cheval(&cheval[4],'J',4,5,4);

    //CRÉATION DES CHEVAUX JOUEUR
    creer_cheval(&cheval[6],'B',1,46,1);
    creer_cheval(&cheval[7],'B',2,45,2);
    creer_cheval(&cheval[8],'B',3,44,3);
    creer_cheval(&cheval[9],'B',4,43,4);
    //CRÉATION DES CHEVAUX JOUEUR
    creer_cheval(&cheval[10],'R',1,46,15);
    creer_cheval(&cheval[11],'R',2,45,14);
    creer_cheval(&cheval[12],'R',3,44,13);
    creer_cheval(&cheval[13],'R',4,43,12);
    //CRÉATION DES CHEVAUX JOUEUR
    creer_cheval(&cheval[14],'V',1,1,0);
    creer_cheval(&cheval[15],'V',2,8,0);
    creer_cheval(&cheval[16],'V',3,1,9);
    creer_cheval(&cheval[16],'V',4,8,9);

    //CRÉATIONS DE L'ARRIVÉE
    creer_cheval(&arrivee[1],'J',0,24,10);
}*/

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

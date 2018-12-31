#include <stdio.h>
#include "esthetique.h"
#include "partie.h"
#include "choix.h"
#include "plateau.h"
#include "h.h"

void nouvelle_partie() {
  int recupDe;
  int recupChoix;
  int recupchoixcheval;
  int nb_joueur;
  int position = 0;
  int IDcheval;


  char coul_e[][10] = { "VERT", "JAUNE", "BLEU", "ROUGE", "BLANC" };
  Joueur player[4];
  Cheval ecurie[17];
  Case cases[56];

  // Initialisation du Jeu

  for (int i = 0; i < 56; i++) {
	  cases[i].couleur = 4;
	  cases[i].IDcheval1 = 17;
	  cases[i].IDcheval2 = 17;
	  cases[i].IDcheval3 = 17;
	  cases[i].IDcheval4 = 17;
  }

  for (int i = 0; i < 17; i++) {
	  ecurie[i].position_c = 56;
  }

  choix(player, &nb_joueur);

  creer_cheval(ecurie, player, &nb_joueur, &IDcheval);

  recupChoix = choix_depart(&nb_joueur);
  printf("Le Joueur %d commence !\n", recupChoix);

  recupDe = De(player, ecurie, &recupChoix, cases, &position, &recupchoixcheval, &IDcheval);
  printf("Le Joueur a lancer et a obtenu un %d !\n", recupDe);

  for (int i = 0; i <= nb_joueur - 1; i++) {
	  printf("Joueur %d: %s ID: %d\n %s\n Ecurie: %d\n\n", i + 1, player[i].nom, player[i].num, coul_e[player[i].couleur], player[i].cheval_e);
  }

  for (int j4 = 0; j4 < nb_joueur * 4; j4++) {
	  printf("Cheval n°: %d | de couleur : %s | en position : %d\n", ecurie[j4].num, coul_e[ecurie[j4].couleur], ecurie[j4].position_c);
  }

  // selection_cheval(&recupChoix, &recupchoixcheval, &IDcheval);

  //chemin(&recupDe, cases, &position, &IDcheval, &recupchoixcheval, ecurie);

  printf("\n");
  printf("\n");
  printf("\n");
  affichePlateau();
}

void creer_cheval(Cheval ecurie[], Joueur player[], int *nb_joueur, int *IDcheval) {
  *IDcheval = 0; // ID des chevaux  (cheval n°12)
  for (int i = 0; i < *nb_joueur; i++) {
    for (int j = 0; j < 4; j++) {
      ecurie[*IDcheval].couleur = player[i].couleur;
      ecurie[*IDcheval].num = j+1;
      (*IDcheval)++;
    }
  }
}

void selection_cheval(int *recupchoix, int *recupchoixcheval, int *IDcheval) {
	*recupchoixcheval = 0;
	printf("Quel cheval voulez-vous faire avancez ? (Son Numéro): ");
	scanf("%d", recupchoixcheval);

	*IDcheval = ((*recupchoix - 1) * 4 + *recupchoixcheval)-1;
}

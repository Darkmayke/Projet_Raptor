#include <stdio.h>
#include "esthetique.h"
#include "partie.h"
#include "choix.h"
#include "plateau.h"
#include "h.h"

void nouvelle_partie() {
  int recupDe; // Valeur du Dé
  int recupChoix; // Numéro du Joueur qui Joue
  int recupchoixcheval; // Numéro du Cheval qui est séléctioner
  int compteur_j; // Compteur qui permet de savoir qui a déjà jouer et qui doit jouer ensuite
  int nb_joueur; // Nombre de Joueur dans la partie
  int position = 0; // Position du cheval séléctioner
  int IDcheval; // ID d'un cheval par rapport a tous les chevaux du Jeu
  int exception; // Exception pour la fonction "choix_depart"
  int Fin = 0; // Sortir de boucle en cas de fin de partie


  char coul_e[][10] = { "VERT", "JAUNE", "BLEU", "ROUGE", "BLANC" };
  Joueur player[4];
  Cheval ecurie[17];
  Case cases[63];

  // Initialisation du Jeu

  for (int i = 0; i < 63; i++) {
	  cases[i].couleur = 4;
	  cases[i].IDcheval1 = 16;
	  cases[i].IDcheval2 = 16;
	  cases[i].IDcheval3 = 16;
	  cases[i].IDcheval4 = 16;
  }

  for (int i = 0; i < 17; i++) {
	  ecurie[i].position_c = 56;
  }

  exception = choix(player, &nb_joueur, &recupChoix);
  creer_cheval(ecurie, player, &nb_joueur, &IDcheval);
  printf("\nLe Joueur %d commence !\n", recupChoix);
  compteur_j = recupChoix;

  while (Fin != 2) {

	  efface_ecran();

	  if (exception != 1) {
		  recupChoix = choix_depart(&compteur_j, &nb_joueur);
		  printf("\nC'est au tour du Joueur %d de joué !\n", recupChoix);
	  }
	  exception = 0;

	  exception = De(player, ecurie, &recupChoix, cases, &position, &recupchoixcheval, &IDcheval, &recupDe);

	  printf("\n");

	  affichePlateau();

	  /* Condition de Fin de Partie */
	  for (int i = 0; i < nb_joueur; i++) {
		  if (player[i].couleur == 0) {
			  if ((cases[59].IDcheval1 < 16) && (cases[60].IDcheval1 < 16) && (cases[61].IDcheval1 < 16) && (cases[62].IDcheval1 < 16)) {
				  printf("\nLe Joueur %d : %s remporte la Partie !\n", player[i].num, player[i].nom);
				  Fin = 2;
			  }
		  }
		  if (player[i].couleur == 1) {
			  if ((cases[59].IDcheval2 < 16) && (cases[60].IDcheval2 < 16) && (cases[61].IDcheval2 < 16) && (cases[62].IDcheval2 < 16)) {
				  printf("\nLe Joueur %d : %s remporte la Partie !\n", player[i].num, player[i].nom);
				  Fin = 2;
			  }
		  }
		  if (player[i].couleur == 2) {
			  if ((cases[59].IDcheval3 < 16) && (cases[60].IDcheval3 < 16) && (cases[61].IDcheval3 < 16) && (cases[62].IDcheval3 < 16)) {
				  printf("\nLe Joueur %d : %s remporte la Partie !\n", player[i].num, player[i].nom);
				  Fin = 2;
			  }
		  }
		  if (player[i].couleur == 3) {
			  if ((cases[59].IDcheval3 < 16) && (cases[60].IDcheval3 < 16) && (cases[61].IDcheval3 < 16) && (cases[62].IDcheval3 < 16)) {
				  printf("\nLe Joueur %d : %s remporte la Partie !\n", player[i].num, player[i].nom);
				  Fin = 2;
			  }
		  }
	  }

	  if (Fin != 2) {
		  do {
			  printf("\n\nVoulez vous passez au prochain tour ? (1 = Oui | 2 = Non): ");
			  scanf("%d", &Fin);
		  } while ((Fin < 1) || (Fin > 2));
	  }
  }
}

void creer_cheval(Cheval ecurie[], Joueur player[], int *nb_joueur, int *IDcheval) {
  *IDcheval = 0;
  for (int i = 0; i < *nb_joueur; i++) {
    for (int j = 0; j < 4; j++) {
      ecurie[*IDcheval].couleur = player[i].couleur;
      ecurie[*IDcheval].num = j+1;
      (*IDcheval)++;
    }
  }
  ecurie[16].couleur = 4;
  ecurie[16].num = 17;
}

void selection_cheval(int *recupchoix, int *recupchoixcheval, int *IDcheval) {
	*recupchoixcheval = 0;
	do {
		printf("Quel cheval voulez-vous faire avancez ? (Son Numéro): ");
		scanf("%d", recupchoixcheval);
	} while ((*recupchoixcheval < 1) && (*recupchoixcheval > 4));

	*IDcheval = ((*recupchoix - 1) * 4 + *recupchoixcheval)- 1;
}

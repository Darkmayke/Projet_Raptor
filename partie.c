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
  int IDcheval; // ID d'un cheval par rapport a tout les chevaux du Jeu
  int exception; // Exception pour la fonction "choix_depart"
  int Fin = 0; // Sortir de boucle en cas de fin de partie


  char coul_e[][10] = { "VERT", "JAUNE", "BLEU", "ROUGE", "BLANC" };
  Joueur player[4];
  Cheval ecurie[17];
  Case cases[56];

  // Initialisation du Jeu

  for (int i = 0; i < 56; i++) {
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
  printf("Le Joueur %d commence !\n", recupChoix);
  compteur_j = recupChoix;
  
  while (Fin != 1) {
	  efface_ecran();

	  if (exception != 1) {
		  recupChoix = choix_depart(&compteur_j, &nb_joueur);
	  }
	  exception = 0;
	  printf("C'est au tour du Joueur %d de joué !\n", recupChoix);

	  recupDe = De(player, ecurie, &recupChoix, cases, &position, &recupchoixcheval, &IDcheval);

	  for (int i = 0; i <= nb_joueur - 1; i++) {
		  printf("Joueur %d: %s ID: %d\n %s\n Ecurie: %d\n\n", i + 1, player[i].nom, player[i].num, coul_e[player[i].couleur], player[i].cheval_e);
	  }

	  for (int j4 = 0; j4 < nb_joueur * 4; j4++) {
		  printf("Cheval n°: %d | de couleur : %s | en position : %d\n", ecurie[j4].num, coul_e[ecurie[j4].couleur], ecurie[j4].position_c);
	  }

	  printf("\n");
	  printf("\n");
	  printf("\n");
	  affichePlateau();
	  do {
		  printf("\n\nVoulez vous passez au prochain tour ? (0 = Oui | 1 = Non): ");
		  scanf("%d", &Fin);
	  } while ((Fin < 0) || (Fin > 1));
  }
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
  ecurie[16].couleur = 4;
  ecurie[16].num = 17;
}

void selection_cheval(int *recupchoix, int *recupchoixcheval, int *IDcheval) {
	*recupchoixcheval = 0;
	printf("Quel cheval voulez-vous faire avancez ? (Son Numéro): ");
	scanf("%d", recupchoixcheval);

	*IDcheval = ((*recupchoix - 1) * 4 + *recupchoixcheval)-1;
}

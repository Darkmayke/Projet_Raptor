#include <stdio.h>
#include <unistd.h>
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
  int position;
  int IDcheval;


  char coul_e[][10] = { "BLEU", "ROUGE", "VERT", "JAUNE" };
  Joueur player[4];
  Cheval ecurie[16];
  Case cases[56];

  choix(&recupDe, &recupChoix, player, &nb_joueur);
  efface_ecran();
  printf("recupDe = %d | recupChoix = %d\n\n",recupDe, recupChoix); //utilité à la vérification ne pas oublier de l'enlever.

//faire un for avec comme compteur le nombre de joueur jouant.
  for (int i = 1; i <= nb_joueur; i++) {
    printf("Joueur %d: %s ID: %d\n %s\n\n", i, player[0].nom, player[0].num, coul_e[player[0].couleur]);
  }
  //printf("Joueur 2: %s ID: %d\n %s\n\n", player[6].nom, player[6].num, coul_e[player[6].couleur]);

  printf("Le Joueur %d commence !\n", recupChoix);
  sleep(5);
  efface_ecran();
  printf("Le Joueur a lancer et a obtenu un %d !\n", recupDe);


  creer_cheval(ecurie, player, &nb_joueur, &IDcheval);

  selection_cheval(&recupChoix, &recupchoixcheval, &IDcheval);

  chemin(&recupDe, cases, &position, &IDcheval, &recupchoixcheval);

  for (int j4 = 0; j4 < nb_joueur*4; j4++) {
    printf("Cheval n°: %d | de couleur : %s\n", ecurie[j4].num, coul_e[ecurie[j4].couleur]);
  }// A convertir en fonction à part ou à enlever

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

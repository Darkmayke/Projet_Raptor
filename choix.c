#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "esthetique.h"
#include "couleurs.h"
#include "choix.h"
#include "h.h"

int choix(Joueur player[], int *nb_joueur, int *recupChoix)
{
	int exception = 1;
	do
	{
		printf("Nombre de Joueur pour la Partie : ");
		scanf("%d", nb_joueur);
	} while ((*nb_joueur < 1) || (*nb_joueur > 4));
	clean();
	/* Sélection des Joueurs*/
	Joueur *g;
	int verif[4] = { 0,0,0,0 };
	int couleur_num;

	for (int i = 0; i < *nb_joueur; i++)
	{
		g = player + i;
        efface_ecran();
		printf("Nom du Joueur %d : \n", i + 1);
		scanf("%s", g->nom);
		clean();
		g->num = i + 1;
		g->cheval_e = 0;
		do
		{
			printf("Quelle Couleur voulez-vous :\n");
			if (verif[0] == 0) {
				printf(COLOR_VERT_EC);
				printf("Vert (1)\n");
			}
			if (verif[1] == 0) {
				printf(COLOR_JAUNE_EC);
				printf("Jaune (2)\n");
			}
			if (verif[2] == 0) {
				printf(COLOR_BLEU_EC);
				printf("Bleu (3)\n");
			}
			if (verif[3] == 0) {
				printf(COLOR_ROUGE_EC);
				printf("Rouge (4)\n");
			}
			printf(COLOR_BASE_EC);
			scanf("%d", &couleur_num);

			if (verif[couleur_num - 1] == 1)
			{
				printf("Couleur déjà prise\n");
			}

		} while ((verif[couleur_num - 1] != 0) || ((couleur_num < 0) || (couleur_num > 4)));
		verif[couleur_num - 1] = 1;
		g->couleur = couleur_num - 1;
		clean();

		srand(time(NULL));
		*recupChoix = rand() % (*nb_joueur - 1 + 1) + 1;
	}
	return exception;
}

int choix_depart(int *compteur_j, int *nb_joueur)
{
	(*compteur_j)++;
	if (*compteur_j > *nb_joueur) {
		*compteur_j = 1;
	}
	return *compteur_j;
}

int De(Joueur player[], Cheval ecurie[], int *recupChoix, Case cases[], int *position, int *recupchoixcheval, int *IDcheval)
{
	srand(time(NULL));
	int lancer = rand() % (6 - 1 + 1) + 1;
	lancer = 6;
	printf("Le Joueur %d a lancer et a obtenu un %d !\n", *recupChoix, lancer);
	int a = 0;
	int confirmation;
	*position = (player[*recupChoix - 1].couleur) * 14;
	*IDcheval = ((*recupChoix - 1) * 4 + player[*recupChoix - 1].cheval_e);

	if ((lancer == 6) && ((player[*recupChoix - 1].cheval_e < 4) || (player[*recupChoix - 1].cheval_e == 0))) {
		do {
			printf("Vous avez fait un 6, voulez vous sortir un Cheval de votre écurie ? (1 = Oui | 2= Non): ");
			scanf("%d", &confirmation);
		} while ((confirmation < 1) || (confirmation > 2));
		clean();
		if (confirmation == 1) {
			player[*recupChoix - 1].cheval_e++;
			*recupchoixcheval = player[*recupChoix - 1].cheval_e;
			ecurie[((*recupChoix - 1) * 4 + player[*recupChoix - 1].cheval_e) - 1].position_c = (player[*recupChoix - 1].couleur) * 14;

			chemin(&a, cases, position, IDcheval, recupchoixcheval, ecurie);
		}
	}
	if ((player[*recupChoix - 1].cheval_e != 0) && (confirmation == 2)){
		selection_cheval(recupChoix, recupchoixcheval, IDcheval);
		*position = ecurie[*IDcheval].position_c;
		chemin(&lancer, cases, position, IDcheval, recupchoixcheval, ecurie);
	}
	else {
		printf("Désolé Joueur %d vous n'avez pas fait un assez bon lancer pour sortir un cheval.\n", *recupChoix);
	}

	return lancer;
}

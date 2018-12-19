#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "couleurs.h"
#include "choix.h"
#include "h.h"

void ajouter_joueur(int i, Joueur *g);

void choix(int *p_recupDe, int *p_recupChoix, Joueur player[])
{
	srand(time(NULL));
	/* Nombre de Joueur*/
	int nb_joueur;
	do
	{
		printf("Nombre de Joueur pour la Partie : ");
		scanf("%d", &nb_joueur);
	} while ((nb_joueur < 0) || (nb_joueur > 4));

	/* S�l�ction des Joueurs*/
	Joueur gamer;

	for (int i = 0; i < nb_joueur; i++)
	{
		ajouter_joueur(i, &gamer);
		player[i]= gamer;
	}

	*p_recupChoix = choix_depart(nb_joueur);
	*p_recupDe = De();
}

void ajouter_joueur(int i, Joueur *g)
{
	int verif[4] = { 0,0,0,0 };
	int couleur_num;

	printf("Nom du Joueur %d : \n", i + 1);
	scanf("%s", g->nom);
	g->num = i + 1;
	do
	{
		printf("Quelle Couleur voulez-vous :\n");
		if (verif[0] == 0) {
			printf(COLOR_BLEU_EC);
			printf("Bleu (1)\n");
		}
		if (verif[1] == 0) {
			printf(COLOR_ROUGE_EC);
			printf("Rouge (2)\n");
		}
		if (verif[2] == 0) {
			printf(COLOR_VERT_EC);
			printf("Vert (3)\n");
		}
		if (verif[3] == 0) {
			printf(COLOR_JAUNE_EC);
			printf("Jaune (4)\n");
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
}

int choix_depart(int max)
{
	int choix_d = rand() % (max - 1 + 1) + 1;
	return choix_d;
}

int De(void)
{
	int lancer = rand() % (6 - 1 + 1) + 1;
	return lancer;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Couleurs.c"
#include "mouvements.h"


int coul(void) {
	/* Nombre de Joueur*/
	int nb_joueur;
	do {
		printf("Nombre de Joueur pour la Partie : ");
		scanf("%d", &nb_joueur);
	} while ((nb_joueur < 0) || (nb_joueur > 4));

	/* S�l�ction des Joueurs*/
	Joueur joueur[4];
	int couleur_num;
	int verif[4] = { 0,0,0,0 };
	char coul_e[][10] = { "BLEU", "ROUGE", "VERT", "JAUNE" };


	for (int i = 0; i < nb_joueur; i++) {
		printf("Nom du Joueur %d : \n", i + 1);
		scanf("%s", joueur[i].nom);
		joueur[i].num = i + 1;
		do {
			printf("Quelle Couleur voulez-vous :\n");
			printf(COLOR_BLEU_EC);
			printf("Bleu (1)\n");
			printf(COLOR_ROUGE_EC);
			printf("Rouge (2)\n");
			printf(COLOR_VERT_EC);
			printf("Vert (3)\n");
			printf(COLOR_JAUNE_EC);
			printf("Jaune (4)\n");
			printf(COLOR_BASE_EC);
			scanf("%d", &couleur_num);

			if (verif[couleur_num - 1] == 1) {
				printf("Couleur deja prise\n");
			}

		} while ((verif[couleur_num - 1] != 0) && ((couleur_num < 0) || (couleur_num > 4)));
		joueur[i].couleur = couleur_num - 1;
		verif[couleur_num - 1] = 1;
	}

	/*int choix_depart(void) {
		alea = rand() % (MAX - MIN + 1) + MIN
	} TA FONCTION EST ICI JE L'AI MISE EN COMMENTAIRE DE MANIERE A NE PAS AVOIR D'ERREUR À LA COMPLIATION*/

	printf("Joueur 1: %s ID: %d\n %s\n", joueur[0].nom, joueur[0].num, coul_e[joueur[0].couleur]);

	printf("Joueur 2: %s ID: %d\n %s\n", joueur[1].nom, joueur[1].num, coul_e[joueur[1].couleur]);
}

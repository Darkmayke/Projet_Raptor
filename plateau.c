#include <stdio.h>

#include "h.h"
#include "couleurs.h"

#define Taille_Grille 50
#define Taille_Grille_H 17

int affichePlateau()
{
	int i, j;
	char Grille[Taille_Grille][Taille_Grille] = {
	  {"[] [] [] [] [] [] [] [ [ ] ] [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O  0  X [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O [1] O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O [2] O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O [3] O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O [4] O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O [5] O [] [] [] [] [] [] []"},
	  {"[] X  O  O  O  O  O  O [6] O  O  O  O  O  O  O []"},
	  {"[] O [1][2][3][4][5][6][+][6][5][4][3][2][1] 0 []"},
	  {"[] O  O  O  O  O  O  O [6] O  O  O  O  O  O  X []"},
	  {"[] [] [] [] [] [] [] O [5] O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O [4] O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O [3] O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O [2] O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] O [1] O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] X  0  O [] [] [] [] [] [] []"},
	  {"[] [] [] [] [] [] [] [ [ ] ] [] [] [] [] [] [] []"}
	};

	for (i = 0; i < Taille_Grille_H; i++) {
		for (j = 0; j < Taille_Grille; j++) {
			/* Jaune */
			if (((j >= 2) && (j <= 19)) && ((i >= 1) && (i <= 6)))
			{
				printf(COLOR_JAUNE_F, Grille[i][j]);
			}
			else if (((j == 21) && ((i >= 1) && (i <= 6))) || (((j >= 3) && (j <= 21)) && (i == 7)) || ((j == 24) && (i == 1)))
			{
				printf(COLOR_JAUNE_E, Grille[i][j]);
			}
			else if (((j >= 23) && (j <= 25)) && ((i >= 2) && (i <= 7)))
			{
				printf(COLOR_JAUNE_EF, Grille[i][j]);
			}

			/* Vert */
			else if (((j >= 2) && (j <= 19)) && ((i >= 10) && (i <= 15)))
			{
				printf(COLOR_VERT_F, Grille[i][j]);
			}
			else if (((j == 21) && ((i >= 9) && (i <= 15))) || (((j >= 3) && (j <= 21)) && (i == 9)) || ((j == 3) && (i == 8)))
			{
				printf(COLOR_VERT_E, Grille[i][j]);
			}
			else if (((j >= 5) && (j <= 22)) && (i == 8))
			{
				printf(COLOR_VERT_EF, Grille[i][j]);
			}


			/* Rouge */
			else if (((j >= 29) && (j <= 46)) && ((i >= 10) && (i <= 15)))
			{
				printf(COLOR_ROUGE_F, Grille[i][j]);
			}
			else if (((j == 27) && ((i >= 9) && (i <= 15))) || (((j >= 27) && (j <= 45)) && (i == 9)) || ((j == 24) && (i == 15)))
			{
				printf(COLOR_ROUGE_E, Grille[i][j]);
			}
			else if (((j >= 23) && (j <= 25)) && ((i >= 9) && (i <= 14)))
			{
				printf(COLOR_ROUGE_EF, Grille[i][j]);
			}

			/* Bleu */
			else if (((j >= 29) && (j <= 46)) && ((i >= 1) && (i <= 6)))
			{
				printf(COLOR_BLEU_F, Grille[i][j]);
			}
			else if (((j == 27) && ((i >= 1) && (i <= 7))) || (((j >= 27) && (j <= 45)) && (i == 7)) || ((j == 45) && (i == 8)))
			{
				printf(COLOR_BLEU_E, Grille[i][j]);
			}
			else if (((j >= 26) && (j <= 43)) && (i == 8))
			{
				printf(COLOR_BLEU_EF, Grille[i][j]);
			}
			/* Blanc Bord*/
			else if ((((j >= 0) && (j <= 48)) && (i == 0)) || (((j >= 0) && (j <= 48)) && (i == 16)) || (((j >= 47) && (j <= 48)) && ((i >= 0) && (i <= 16))) || (((j >= 0) && (j <= 1)) && ((i >= 0) && (i <= 16))))
			{
				printf(COLOR_BASE, Grille[i][j]);
			}

			else
			{
				printf("%c", Grille[i][j]);
			}
		}
		printf("\n");
	}
  return 0;
}

void chemin(int *p_recupDe, Case cases[], int *p_position, int *IDcheval, int *recupchoixheval){

  Case *c;
  *p_position = 55; // Mettre à 55 pour aller plus vite lors de la vérification du passage de tour.
	printf("\nCase: %d -->", *p_position);
  for (int saut = 0; saut < *p_recupDe; saut++) {
    (*p_position)++;
	c = cases + *p_position;
		if(*p_position>56){
			*p_position=0;
		}
		// Faire un switch case ici mais je sais pas faire
		if (*recupchoixheval == 1) {
			c->IDcheval1 = *IDcheval;
		}
		if (*recupchoixheval == 2) {
			c->IDcheval2 = *IDcheval;
		}
		if (*recupchoixheval == 3) {
			c->IDcheval3 = *IDcheval;
		}
		if (*recupchoixheval == 4) {
			c->IDcheval4 = *IDcheval;
		}
  }
  printf(" %d\n", *p_position);
  printf("Case Cheval1 : %d\n", cases[*p_position].IDcheval1);
  printf("Case Cheval2 : %d\n", cases[*p_position].IDcheval2);
  printf("Case Cheval3 : %d\n", cases[*p_position].IDcheval3);
  printf("Case Cheval4 : %d\n", cases[*p_position].IDcheval4);
	
}

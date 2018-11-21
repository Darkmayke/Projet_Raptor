#include <stdio.h>

/* Initialisation */
#define Taille_Grille 50
#define Taille_Grille_H 17

/* Couleur Jaune*/
#define COLOR_JAUNE_F "\033[33;43;7m%c\033[0m"
#define COLOR_JAUNE_E "\033[33m%c\033[0m"
#define COLOR_JAUNE_EF "\033[37;43;1m%c\033[0m"

/* Couleur Vert*/
#define COLOR_VERT_F "\033[32;42;7m%c\033[0m"
#define COLOR_VERT_E "\033[32m%c\033[0m"
#define COLOR_VERT_EF "\033[37;42;1m%c\033[0m"

/* Couleur Rouge*/
#define COLOR_ROUGE_F "\033[31;41;7m%c\033[0m"
#define COLOR_ROUGE_E "\033[31m%c\033[0m"
#define COLOR_ROUGE_EF "\033[37;41;1m%c\033[0m"

/* Couleur Bleu*/
#define COLOR_BLEU_F "\033[34;44;7m%c\033[0m"
#define COLOR_BLEU_E "\033[34m%c\033[0m"
#define COLOR_BLEU_EF "\033[37;44;1m%c\033[0m"

/* Couleur de Base*/
#define COLOR_BASE "\033[37;47;7m%c\033[0m"

int main(void){

	int i, j;
	char Grille[Taille_Grille][Taille_Grille] ={
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
	//for (i = 0; i < Taille_Grille_H; i++) {
	//	for (j = 0; j < Taille_Grille; j++) {
	//		printf("%c", Grille[i][j]);
	//	}
	//	printf("\n");
	//}

	for (i = 0; i < Taille_Grille_H ; i++){
		for (j = 0; j < Taille_Grille; j++){
			/* Jaune */
			if (((j >= 2) && (j <= 19)) && ((i >= 1) && (i <= 6)))
			{
				printf(COLOR_JAUNE_F, Grille[i][j]);
			}
			else if (((j == 21) && ((i >= 1) && (i <= 6))) || (((j >= 3) && (j <= 21)) && (i == 7)) || ((j == 24) && (i == 1)))
			{
				printf(COLOR_JAUNE_E, Grille[i][j]);
			}
			else if (((j >= 23) && (j <= 25)) && ((i >= 2) && ( i <= 7)))
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
			else if ((((j >= 0) && (j <= 48)) && (i == 0)) || (((j >= 0) && (j <= 48)) && (i == 16)) || (((j >= 47) && (j <= 48)) && ((i >= 0) && (i<= 16))) || (((j >= 0) && (j <= 1)) && ((i >= 0) && (i <= 16))))
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

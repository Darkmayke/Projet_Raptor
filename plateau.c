#include <stdio.h>

#include "h.h"
#include "couleurs.h"
#include "plateau.h"

#define Taille_Grille 50
#define Taille_Grille_H 17

char Grille[Taille_Grille_H][Taille_Grille] = {
	{"[] [] [] [] [] [] [] [ [ ] ] [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O  0  X [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O [1] O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O [2] O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O [3] O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O [4] O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O [5] O [] [] [] [] [] [] []"},
	{"[] X  O  O  O  O  O  O [6] O  O  O  O  O  O  O []"},
	{"[] 0 [1][2][3][4][5][6][+][6][5][4][3][2][1] 0 []"},
	{"[] O  O  O  O  O  O  O [6] O  O  O  O  O  O  X []"},
	{"[] [] [] [] [] [] [] O [5] O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O [4] O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O [3] O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O [2] O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] O [1] O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] X  0  O [] [] [] [] [] [] []"},
	{"[] [] [] [] [] [] [] [ [ ] ] [] [] [] [] [] [] []"}
};

int i, j;

void affichePlateau() {
				//Grille[15][24] = '8';
	for (i = 0; i < Taille_Grille_H; i++) {
		for (j = 0; j < Taille_Grille; j++) {
			afficheCouleur(i,j);
		}
		printf("\n");
	}
}

void afficheCouleur(int i,int j) {
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

void recupereEmplacementGrille(int numCase, int *x, int *y) {
	if (numCase < 7) {
		*x = 21;
		*y = 15-numCase;

	} else if (numCase </*=*/ 12) {
		*x = 21-(numCase+6)*3;
		*y = 9;

	} else if (numCase == 13) {
		*x= 3;
		*y = 8;

	} else if (numCase < 21) {
		*x = 3+(numCase-14)*3;
		*y = 7;

	}else if (numCase < 27) {
		*x = 21;
		*y = 7+numCase;

	} else if (numCase == 27) {
		*x = 25;
		*y = 1;

	} else if (numCase < 35) {
		*x = 27;
		*y = 1+(numCase-28);

	} else if (numCase < 41) {
		*x =27+(numCase-35)*3;
		*y =7;

	}else if (numCase == 41) {
		*x = 45;
		*y = 8;

	} else if (numCase < 49) {
		*x = 45-(numCase-42)*3;
		*y = 9;

<<<<<<< HEAD
	}  else if (numCase < 56) {
=======
	} else if (numCase < 56) {
>>>>>>> e618420c5d052fd7a7063ab826b59bb9c37bd8cf
		*x = 27;
		*y = 9+(numCase-50);

	}else if (numCase == 55){
		*x = 24;
		*y = 15;
	}
}

// actualisePlateau(le cheval et les coord)
void actualisePlateau(int numCase,int IDcheval) {
	printf("actualisation\n");
	int x,y;
	recupereEmplacementGrille(numCase,&x,&y);

	if(IDcheval == 16) {
		//affiche la case comme vide
		Grille[y][x] = 'O';
		//A COMPLETER EN GERANT LES 0 ET X
		//RESET A SA COULEUR DORIGINE
	} else {
		//affiche la case comme contenant un ou des chevaux
		int affichage;
		if(IDcheval < 4) {
			//afficher le cheval comme étant VERT
			//A FAIRE POUR CHAQUE
			affichage = IDcheval+1;
		} else if (IDcheval < 8) {
			//afficher le cheval comme étant JAUNE
			affichage = IDcheval-4+1;
		} else if (IDcheval < 12) {
			//afficher le cheval comme étant BLEU
			affichage = IDcheval-8+1;
		} else if (IDcheval < 16) {
			//afficher le cheval comme étant ROUGE
			affichage = IDcheval-12+1;
		}
		Grille[y][x] = affichage+'0'; //transforme l'entier en caractère.
	}
}

void chemin(int *p_recupDe, Case cases[], int *p_position, int *IDcheval, int *recupchoixcheval, Cheval ecurie[], Joueur player[]){
  char coul_e[][10] = { "VERT", "JAUNE", "BLEU", "ROUGE", "BLANC" };
  // Mettre à 55 pour la vérification du passage de tour.
  int barrage = 0; // Valeur permettant de savoir s'il y a un cheval en barrage
  int conflit = 0; // Valeur permettant de savoir s'il y a conflit entre 2 chevaux de couleur différentes sur une case
  int pos_depart = *p_position; // Enregistre la position de départ du cheval
  int r_ID = 16; // Permet de remettre à la valeur initiale l'ID d'un cheval dans la structure case

 /* Fait avancer la position du cheval en fonction de la valeur du dé */
	printf("\nCase : %d -->", *p_position);
	for (int saut = 0; saut < *p_recupDe; saut++) {
		(*p_position)++;

		if (*p_position > 56) {
			*p_position = 0;
		}
		if (cases[*p_position].couleur != ecurie[*IDcheval].couleur) { // Vérifie pour chaque case parcourue s'il y a un cheval d'une autre couleur
			barrage = 1; // Signifie que il y a bien un cheval en barrage
		}
    }
	printf(" %d\n", *p_position);

/* Vérification que la case d'arrivée ne contient pas un cheval d'une autre couleur */
	if (cases[*p_position].couleur != ecurie[*IDcheval].couleur) {
		conflit = 1; // Signifie qu'il y a conflit entre 2 chevaux de couleur différentes
		barrage = 0;
		for (int i = 0; i < 4; i++) {
			if (cases[*p_position].couleur == player[i].couleur) {
				printf("Joueur %d : Chevaux Ecurie = %d\n", i + 1, player[i].cheval_e);
				player[i].cheval_e = player[i].cheval_e - 1;
				if (*recupchoixcheval == 1) {
					ecurie[cases[*p_position].IDcheval1].position_c = 56;
					player[i].cheval_dispo[0] = 0;
				}
				else if (*recupchoixcheval == 2) {
					ecurie[cases[*p_position].IDcheval2].position_c = 56;
					player[i].cheval_dispo[1] = 0;
				}
				else if (*recupchoixcheval == 3) {
					ecurie[cases[*p_position].IDcheval3].position_c = 56;
					player[i].cheval_dispo[2] = 0;
				}
				else if (*recupchoixcheval == 4) {
					ecurie[cases[*p_position].IDcheval4].position_c = 56;
					player[i].cheval_dispo[3] = 0;
				}
			}
		}
		deplacement(p_position, cases, ecurie, &r_ID, recupchoixcheval);
	}

/* Suppression du cheval de sa case de départ */
	if (barrage == 0) {
		deplacement(&pos_depart, cases, ecurie, &r_ID, recupchoixcheval);
	}

/* Enregistre le cheval dans la case d'arrivée */
	if (barrage == 0) {
		ecurie[*IDcheval].position_c = *p_position;
		deplacement(p_position, cases, ecurie, IDcheval, recupchoixcheval);
	}
	if (barrage == 1) {
		printf("Il y avait un cheval sur votre route ! Dommage retour à l'envoyeur.\nVotre Cheval reste sur place et vous passez votre tour.\n");
	}
	if (conflit == 1) {
		printf("Vous avez chargé le cheval adverse et vous l'avez renvoyé dans son écurie !\n");
	}

/* Affichage des cases de départ et d'arrivée */

  printf("Case Numero : %d\n", pos_depart);
  printf("Case Couleur : %s\n", coul_e[cases[pos_depart].couleur]);
  printf("Case Cheval1 : %d\n", cases[pos_depart].IDcheval1);
  printf("Case Cheval2 : %d\n", cases[pos_depart].IDcheval2);
  printf("Case Cheval3 : %d\n", cases[pos_depart].IDcheval3);
  printf("Case Cheval4 : %d\n\n\n", cases[pos_depart].IDcheval4);

  printf("Case Numero : %d\n", *p_position);
  printf("Case Couleur : %s\n", coul_e[cases[*p_position].couleur]);
  printf("Case Cheval1 : %d\n", cases[*p_position].IDcheval1);
  printf("Case Cheval2 : %d\n", cases[*p_position].IDcheval2);
  printf("Case Cheval3 : %d\n", cases[*p_position].IDcheval3);
  printf("Case Cheval4 : %d\n\n\n", cases[*p_position].IDcheval4);

}

void deplacement(int *position, Case cases[], Cheval ecurie[], int *IDcheval, int *recupchoixcheval) {
	Case *c;
	c = cases + *position;
	printf("id du cheval selectionne :      %d  de position %d\n", *IDcheval, *position);
	if (*recupchoixcheval == 1) {
		c->couleur = ecurie[*IDcheval].couleur;
		c->IDcheval1 = *IDcheval;
	}
	else if (*recupchoixcheval == 2) {
		c->couleur = ecurie[*IDcheval].couleur;
		c->IDcheval2 = *IDcheval;
	}
	else if (*recupchoixcheval == 3) {
		c->couleur = ecurie[*IDcheval].couleur;
		c->IDcheval3 = *IDcheval;
	}
	else if (*recupchoixcheval == 4) {
		c->couleur = ecurie[*IDcheval].couleur;
		c->IDcheval4 = *IDcheval;
	}
	actualisePlateau(*position,*IDcheval);
}

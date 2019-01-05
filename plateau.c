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

Color CouleurChemin[Taille_Grille_H][Taille_Grille];

int i, j;

void affichePlateau() {
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
	else if (((j == 21) && ((i >= 1) && (i <= 6))) || (((j >= 3) && (j <= 21)) && (i == 7)) || ((j == 3) && (i == 8)) )
	{
		if(Grille[i][j] < '1' || Grille[i][j] > '4')
			printf(COLOR_JAUNE_E, Grille[i][j]);
		else
			afficherCouleurCheval(i,j);
	}
	else if (((j >= 23) && (j <= 25)) && ((i >= 2) && (i <= 7)))
	{
		if (i == 2) {
			if (Grille[2][24] == '1')
				printf(COLOR_BLEU_EF, Grille[i][j]);
			else
				printf(COLOR_BLEU_ENF, Grille[i][j]);
		}
		else if (i == 3) {
			if (Grille[3][24] == '2')
				printf(COLOR_BLEU_EF, Grille[i][j]);
			else
				printf(COLOR_BLEU_ENF, Grille[i][j]);
		}
		else if (i == 4) {
			if (Grille[4][24] == '3')
				printf(COLOR_BLEU_EF, Grille[i][j]);
			else
				printf(COLOR_BLEU_ENF, Grille[i][j]);
		}
		else if (i == 5) {
			if (Grille[5][24] == '4')
				printf(COLOR_BLEU_EF, Grille[i][j]);
			else
				printf(COLOR_BLEU_ENF, Grille[i][j]);
		}
		else if (i == 6) {
			if (Grille[6][24] == '5')
				printf(COLOR_BLEU_EF, Grille[i][j]);
			else
				printf(COLOR_BLEU_ENF, Grille[i][j]);
		}
		else if (i == 7) {
			if (Grille[7][24] == '6')
				printf(COLOR_BLEU_EF, Grille[i][j]);
			else
				printf(COLOR_BLEU_ENF, Grille[i][j]);
		}
		else {
			printf(COLOR_BLEU_EF, Grille[i][j]);
		}
	}

	/* Vert */
	else if (((j >= 2) && (j <= 19)) && ((i >= 10) && (i <= 15)))
	{
		printf(COLOR_VERT_F, Grille[i][j]);
	}
	else if (((j == 21) && ((i >= 9) && (i <= 15))) || (((j >= 3) && (j <= 21)) && (i == 9)) || ((j == 24) && (i == 15)))
	{
		if(Grille[i][j] < '1' || Grille[i][j] > '4')
			printf(COLOR_VERT_E, Grille[i][j]);
		else
			afficherCouleurCheval(i,j);
	}
	else if (((j >= 5) && (j <= 22)) && (i == 8))
	{
		if (j >= 5 && j <= 7) {
			if (Grille[8][6] == '1')
				printf(COLOR_JAUNE_EF, Grille[i][j]);
			else
				printf(COLOR_JAUNE_ENF, Grille[i][j]);
		}
		else if (j >= 8 && j <= 10) {
			if (Grille[8][9] == '2')
				printf(COLOR_JAUNE_EF, Grille[i][j]);
			else
				printf(COLOR_JAUNE_ENF, Grille[i][j]);
		}
		else if (j >= 11 && j <= 13) {
			if (Grille[8][12] == '3')
				printf(COLOR_JAUNE_EF, Grille[i][j]);
			else
				printf(COLOR_JAUNE_ENF, Grille[i][j]);
		}
		else if (j >= 14 && j <= 16) {
			if (Grille[8][15] == '4')
				printf(COLOR_JAUNE_EF, Grille[i][j]);
			else
				printf(COLOR_JAUNE_ENF, Grille[i][j]);
		}
		else if (j >= 17 && j <= 19) {
			if (Grille[8][18] == '5')
				printf(COLOR_JAUNE_EF, Grille[i][j]);
			else
				printf(COLOR_JAUNE_ENF, Grille[i][j]);
		}
		else if (j >= 20 && j<= 22) {
			if (Grille[8][21] == '6')
				printf(COLOR_JAUNE_EF, Grille[i][j]);
			else
				printf(COLOR_JAUNE_ENF, Grille[i][j]);
		}
		else {
			printf(COLOR_JAUNE_EF, Grille[i][j]);
		}
	}


	/* Rouge */
	else if (((j >= 29) && (j <= 46)) && ((i >= 10) && (i <= 15)))
	{
		printf(COLOR_ROUGE_F, Grille[i][j]);
	}
	else if (((j == 27) && ((i >= 9) && (i <= 15))) || (((j >= 27) && (j <= 45)) && (i == 9)) || ((j == 45) && (i == 8)))
	{
		if(Grille[i][j] < '1' || Grille[i][j] > '4')
			printf(COLOR_ROUGE_E, Grille[i][j]);
		else
			afficherCouleurCheval(i,j);
	}
	else if (((j >= 23) && (j <= 25)) && ((i >= 9) && (i <= 14)))
	{
		if (i == 14) {
			if (Grille[14][24] == '1')
				printf(COLOR_VERT_EF, Grille[i][j]);
			else
				printf(COLOR_VERT_ENF, Grille[i][j]);
		}
		else if (i == 13) {
			if (Grille[13][24] == '2')
				printf(COLOR_VERT_EF, Grille[i][j]);
			else
				printf(COLOR_VERT_ENF, Grille[i][j]);
		}
		else if (i == 12) {
			if (Grille[12][24] == '3')
				printf(COLOR_VERT_EF, Grille[i][j]);
			else
				printf(COLOR_VERT_ENF, Grille[i][j]);
		}
		else if (i == 11) {
			if (Grille[11][24] == '4')
				printf(COLOR_VERT_EF, Grille[i][j]);
			else
				printf(COLOR_VERT_ENF, Grille[i][j]);
		}
		else if (i == 10) {
			if (Grille[10][24] == '5')
				printf(COLOR_VERT_EF, Grille[i][j]);
			else
				printf(COLOR_VERT_ENF, Grille[i][j]);
		}
		else if (i == 9) {
			if (Grille[9][24] == '6')
				printf(COLOR_VERT_EF, Grille[i][j]);
			else
				printf(COLOR_VERT_ENF, Grille[i][j]);
		}
		else {
			printf(COLOR_VERT_EF, Grille[i][j]);
		}

	}

	/* Bleu */
	else if (((j >= 29) && (j <= 46)) && ((i >= 1) && (i <= 6)))
	{
		printf(COLOR_BLEU_F, Grille[i][j]);
	}
	else if (((j == 27) && ((i >= 1) && (i <= 7))) || (((j >= 27) && (j <= 45)) && (i == 7)) || ((j == 24) && (i == 1)))
	{
		if(Grille[i][j] < '1' || Grille[i][j] > '4')
			printf(COLOR_BLEU_E, Grille[i][j]);
		else
			afficherCouleurCheval(i,j);
	}
	else if (((j >= 26) && (j <= 43)) && (i == 8))
	{
		if (j >= 41 && j <= 43) {
			if (Grille[8][42] == '1')
				printf(COLOR_ROUGE_EF, Grille[i][j]);
			else
				printf(COLOR_ROUGE_ENF, Grille[i][j]);
		}
		else if (j >= 38 && j <= 40) {
			if (Grille[8][39] == '2')
				printf(COLOR_ROUGE_EF, Grille[i][j]);
			else
				printf(COLOR_ROUGE_ENF, Grille[i][j]);
		}
		else if (j >= 35 && j<= 37) {
			if (Grille[8][36] == '3')
				printf(COLOR_ROUGE_EF, Grille[i][j]);
			else
				printf(COLOR_ROUGE_ENF, Grille[i][j]);
		}
		else if (j >= 32 && j<= 34) {
			if (Grille[8][33] == '4')
				printf(COLOR_ROUGE_EF, Grille[i][j]);
			else
				printf(COLOR_ROUGE_ENF, Grille[i][j]);
		}
		else if (j >= 29 && j <= 31) {
			if (Grille[8][30] == '5')
				printf(COLOR_ROUGE_EF, Grille[i][j]);
			else
				printf(COLOR_ROUGE_ENF, Grille[i][j]);
		}
		else if (j >= 26 && j <= 28) {
			if (Grille[8][27] == '6')
				printf(COLOR_ROUGE_EF, Grille[i][j]);
			else
				printf(COLOR_ROUGE_ENF, Grille[i][j]);
		}
		else {
			printf(COLOR_ROUGE_EF, Grille[i][j]);
		}
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

void afficherCouleurCheval(int i,int j) {
	if (CouleurChemin[i][j] == VERT)
			printf(COLOR_VERT_E, Grille[i][j]);
	else if (CouleurChemin[i][j] == JAUNE)
			printf(COLOR_JAUNE_E, Grille[i][j]);
	else if (CouleurChemin[i][j] == BLEU)
			printf(COLOR_BLEU_E, Grille[i][j]);
	else
			printf(COLOR_ROUGE_E, Grille[i][j]);
}

void recupereEmplacementGrille(int numCase, int *x, int *y, Color couleur) {
	if (numCase < 7) {
		*x = 21;
		*y = 15-numCase;

	} else if (numCase < 13) {
		*x = 21-(numCase-6)*3;
		*y = 9;

	} else if (numCase == 13) {
		*x= 3;
		*y = 8;

	} else if (numCase < 21) {
		*x = 3+(numCase-14)*3;
		*y = 7;

	}else if (numCase < 27) {
		*x = 21;
		*y = 7-(numCase-20);

	} else if (numCase == 27) {
		*x = 24;
		*y = 1;

	} else if (numCase < 35) {
		*x = 27;
		*y = 1+(numCase-28);

	} else if (numCase < 41) {
		*x =27+(numCase-34)*3;
		*y =7;

	}else if (numCase == 41) {
		*x = 45;
		*y = 8;

	} else if (numCase < 49) {
		*x = 45-(numCase-42)*3;
		*y = 9;

	}  else if (numCase < 55) {
		*x = 27;
		*y = 9+(numCase-48);

	}else if (numCase == 55){
		*x = 24;
		*y = 15;
	}
	else if ((numCase > 56) && (numCase < 63)){
		if (couleur == 0) {
			*x = 24;
			*y = 14 -(numCase-57);
		}
		if (couleur == 1) {
			*x = 6 + (numCase - 57)*3;
			*y = 8;
		}
		if (couleur == 2) {
			*x = 24;
			*y = 2 + (numCase - 57);
		}
		if (couleur == 3) {
			*x = 42 - (numCase - 57)*3;
			*y = 8;
		}
	}
}

void actualisePlateau(int numCase,int IDcheval,Color couleur) {
	int x,y;
	recupereEmplacementGrille(numCase,&x,&y,couleur);

	if(IDcheval == 16) {
		//affiche la case comme vide
		if (numCase < 56) {
			Grille[y][x] = 'O';
		}
		if ((numCase == 0) || (numCase == 14) || (numCase == 28) || (numCase == 42)) {
			Grille[y][x] = 'X';
		}
		if ((numCase == 55) || (numCase == 13) || (numCase == 27) || (numCase == 41)) {
			Grille[y][x] = '0';
		}
		if (numCase == 57) {
			Grille[y][x] = '1';
		}
		if (numCase == 58) {
			Grille[y][x] = '2';
		}
		if (numCase == 59) {
			Grille[y][x] = '3';
		}
		if (numCase == 60) {
			Grille[y][x] = '4';
		}
		if (numCase == 61) {
			Grille[y][x] = '5';
		}
		if (numCase == 62) {
			Grille[y][x] = '6';
		}
		afficheCouleur(y,x);
		//RESET A SA COULEUR DORIGINE
	} else {
		//affiche la case comme contenant un ou des chevaux
		int affichage;
		if(IDcheval < 4) {
			//afficher le cheval comme étant VERT
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
		Grille[y][x] = affichage+'0'; //transforme l'entier en caractère et le stock dans la Grille
		//stock la couleur du cheval
		CouleurChemin[y][x] = couleur;
	}
}

void chemin(int *p_recupDe, Case cases[], int *p_position, int *IDcheval, int *recupchoixcheval, Cheval ecurie[], Joueur player[]){
  char coul_e[][10] = { "VERT", "JAUNE", "BLEU", "ROUGE", "BLANC" };
  // Mettre à 55 pour la vérification du passage de tour.
  int barrage = 0; // Valeur permettant de savoir s'il y a un cheval en barrage
  int conflit = 0; // Valeur permettant de savoir s'il y a conflit entre 2 chevaux de couleur différentes sur une case
  int echelle = 0; // Valeur permttant de savoir si le Joueur entre dans la phase finale du Jeu (Echelle de fin)
  int pos_depart = *p_position; // Enregistre la position de départ du cheval
  int r_ID = 16; // Permet de remettre à la valeur initiale l'ID d'un cheval dans la structure case

	/* Entrée dans l'Echelle de fin*/
	if (((ecurie[*IDcheval].position_c) == (((ecurie[*IDcheval].couleur) * 14) - 1)) || ((ecurie[*IDcheval].couleur == 0) && (ecurie[*IDcheval].position_c == 55)) || (ecurie[*IDcheval].position_c > 56)) {
		echelle = marche(cases, ecurie, IDcheval, p_recupDe, recupchoixcheval, r_ID);
	}

	/* Fait avancer la position du cheval en fonction de la valeur du dé */
   if (echelle == 0) {
 	  for (int saut = 0; saut < *p_recupDe; saut++) {
 		  (*p_position)++;

 		  if (*p_position > 55) {
 			  *p_position = 0;
 		  }
 		  if ((cases[*p_position].couleur != ecurie[*IDcheval].couleur) && (cases[*p_position].couleur != 4)) { // Vérifie pour chaque case parcouru si il y a un cheval d'un autre couleur
 			  barrage = 1; // Signifie que il y a bien un cheval en barrage
 		  }
 		  // Vérification que le Cheval a bien fait un tour et qu'il doit s'arreter sur la case devant l'échelle de fin
 		  if ((*p_position >= (((ecurie[*IDcheval].couleur) * 14) - 1)) && (pos_depart <= (((ecurie[*IDcheval].couleur) * 14) - 1)) || ((pos_depart > *p_position) && (ecurie[*IDcheval].couleur == 0))) {
 			  barrage = 1;
 			  echelle = 1;
 		  }
 	  }
   }

	 /* Vérification que la case d'arrivée ne contient pas un cheval d'une autre couleur */
	 	if ((cases[*p_position].couleur != ecurie[*IDcheval].couleur) && (cases[*p_position].couleur != 4)) {
	 		conflit = 1; // Signifie qu'il y a conflit entre 2 chevaux de couleur différentes
	 		barrage = 0;
	 		verif_conflit(cases, ecurie, player, p_position, recupchoixcheval, r_ID);
	 	}

	 /* Suppression du cheval de sa case de départ */
	 	if ((barrage == 0) && (echelle == 0)) {
	 		deplacement(&pos_depart, cases, ecurie, &r_ID, recupchoixcheval);
	 	}

	 /* Enregistre le cheval dans la case d'arrivée */
	 	if ((barrage == 0) && (echelle == 0)) {
	 		ecurie[*IDcheval].position_c = *p_position;
	 		deplacement(p_position, cases, ecurie, IDcheval, recupchoixcheval);
	 	}
	 	if (barrage == 1 && echelle == 0) {
	 		printf("Il y avait un cheval sur votre route ! Dommage retour à l'envoyeur.\nVotre Cheval reste sur place et vous passez votre tour.\n");
	 	}
	 	if (barrage == 1 && echelle == 1) {
	 		printf("Vous êtes aller trop loin ! Vous retournez à votre position de départ et vous passez votre tour. Essayer de ne pas aller aussi loin la prochaine fois !\n");
	 	}
	 	if (conflit == 1) {
	 		printf("Vous avez chargé le cheval adverse et vous l'avez renvoyé dans son écurie !\n");
	 	}
}

void deplacement(int *position, Case cases[], Cheval ecurie[], int *IDcheval, int *recupchoixcheval) {
	Case *c;
	c = cases + *position;
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
	actualisePlateau(*position, *IDcheval, ecurie[*IDcheval].couleur);
}


void verif_conflit(Case cases[], Cheval ecurie[], Joueur player[], int *p_position, int *recupchoixcheval, int r_ID) {
	for (int i = 0; i < 4; i++) {
		if (cases[*p_position].couleur == player[i].couleur) {
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

void echelle_fin(Case cases[], Cheval ecurie[], int *IDcheval, int pos_echelle, int recupcouleur) {
	Case *ca;

	ca = cases + pos_echelle;
	if (recupcouleur == 0) {
		ca->IDcheval1 = *IDcheval;
	}
	if (recupcouleur == 1) {
		ca->IDcheval2 = *IDcheval;
	}
	if (recupcouleur == 2) {
		ca->IDcheval3 = *IDcheval;
	}
	if (recupcouleur == 3) {
		ca->IDcheval4 = *IDcheval;
	}

	actualisePlateau(pos_echelle, *IDcheval, recupcouleur);
	ecurie[*IDcheval].position_c = pos_echelle;
}

int marche(Case cases[], Cheval ecurie[], int *IDcheval, int *p_recupDe, int *recupchoixcheval, int r_ID) {
	int recupcouleur = ecurie[*IDcheval].couleur; // Récupère la Couleur du cheval
	int pos_cheval = ecurie[*IDcheval].position_c; // Récupère la Position du cheval

	if (ecurie[*IDcheval].position_c == (((ecurie[*IDcheval].couleur) * 14) - 1)) {
		if (*p_recupDe == 1) {
			deplacement(&pos_cheval, cases, ecurie, &r_ID, recupchoixcheval);
			echelle_fin(cases, ecurie, IDcheval, 57, recupcouleur);

		}
		else {
			printf("\nDésolé mais tu n'a pas fait assez pour pouvoir monter la marche !\n\n");
		}
	}
	else if (ecurie[*IDcheval].position_c == 57) {
		if (*p_recupDe == 2) {
			echelle_fin(cases, ecurie, &r_ID, 57, recupcouleur);
			echelle_fin(cases, ecurie, IDcheval, 58, recupcouleur);
		}
		else {
			printf("\nDésolé mais tu n'a pas fait assez pour pouvoir monter la marche !\n\n");
		}
	}
	else if (ecurie[*IDcheval].position_c == 58) {
		if (*p_recupDe == 3) {
			echelle_fin(cases, ecurie, &r_ID, 58, recupcouleur);
			echelle_fin(cases, ecurie, IDcheval, 59, recupcouleur);
		}
		else {
			printf("\nDésolé mais tu n'a pas fait assez pour pouvoir monter la marche !\n\n");
		}
	}
	else if (ecurie[*IDcheval].position_c == 59) {
		if (*p_recupDe == 4) {
			echelle_fin(cases, ecurie, &r_ID, 59, recupcouleur);
			echelle_fin(cases, ecurie, IDcheval, 60, recupcouleur);

		}
		else {
			printf("\nDésolé mais tu n'a pas fait assez pour pouvoir monter la marche !\n\n");
		}
	}
	else if (ecurie[*IDcheval].position_c == 60) {
		if (*p_recupDe == 5) {
			echelle_fin(cases, ecurie, &r_ID, 60, recupcouleur);
			echelle_fin(cases, ecurie, IDcheval, 61, recupcouleur);
		}
		else {
			printf("\nDésolé mais tu n'a pas fait assez pour pouvoir monter la marche !\n\n");
		}
	}
	else if (ecurie[*IDcheval].position_c == 61) {
		if (*p_recupDe == 6) {
			echelle_fin(cases, ecurie, &r_ID, 61, recupcouleur);
			echelle_fin(cases, ecurie, IDcheval, 62, recupcouleur);
		}
		else {
			printf("\nDésolé mais tu n'a pas fait assez pour pouvoir monter la marche !\n\n");
		}
	}
	return 1;
}

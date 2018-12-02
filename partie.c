#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Taille_Grille 50
#define Taille_Grille_H 17

#include "Couleurs.h"
#include "partie.h"

void nouvelle_partie() {

    Joueur joueur1, joueur2, joueur_jouant;
    joueur1.couleur = 'J', joueur1.num = 1;
    joueur2.couleur = 'B', joueur2.num = 2;
    joueur_jouant = joueur2;

    int num_tour = 0;

    generation_ecurie();

    int gagnant = 0;

    do{
        num_tour++;

        efface_ecran();
        bandeau();
        printf("\n\n\n\n\n                    ============\n");
        printf("                    || TOUR %d ||\n",num_tour);
        printf("                    ============\n");
        sleep(1);

        for(int i = 1;i <= 2;i++){
            if (joueur_jouant.num == 1) joueur_jouant = joueur2;
            else joueur_jouant = joueur1;

            gagnant = test_fin_partie(); //test si l'un des joueur n'a pas gagné

            //effectue la demande de deplacement pour le joueur si la partie n'est pas gagné par l'un d'eux
            if (gagnant == 0){
                do{
                    efface_ecran();
                    actualise_plateau();
                    bandeau();
                    affiche_plateau();
                }while(deplacement(joueur_jouant) == 0);    //(la boucle permet à l'utilisateur de choisir un autre Cheval s'l le souhaite)
            }
        }

        //petit temps d'attente
        efface_ecran();
        bandeau();
        affiche_plateau();
        sleep(1);

        gagnant = test_fin_partie();

   }while(gagnant == 0);

    char couleur_gagnant[10];

   if(gagnant == 1) sprintf(couleur_gagnant,"ROUGE");
   else sprintf(couleur_gagnant,"NOIR");

    efface_ecran();
    bandeau();

    printf("\n\n\n\n\n       =======================================\n");
    printf("       || LE JOUEUR %s GAGNE LA PARTIE ! ||\n",couleur_gagnant);
    printf("       =======================================\n");
    sleep(2);
}

void affiche_plateau() {

  /*  for (int i = 0;i <= 9;i++){

        //affiche les barres du plateau
        if (i == 0) printf("     -----------------------------------------      \n");

        //affiche le Cheval pour chaque case
        for (int j = 0;j <= 9;j++){
                affiche_case(i,j);
            }

        if (i >= 3 && i <= 5){
            printf("\n---------------------------------------------------\n");
        }else{
            printf("\n     -----------------------------------------     \n");
        }
    }   //FIN DE L'AFFICHAGE DE MON EXEMPLE*/
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
}


void test_color(int x, int y) {
        if (plateau[x][y].couleur == 'J') printf("\033[41;37m");
        else if(plateau[x][y].couleur == 'B') printf("\033[47;30m");
        else if(plateau[x][y].couleur == 'V') printf("\033[42;37m");
}


void affiche_case(int i,int j) {
    if (test_case(j,i) == 1) {
        if ((j == 1 && (i != 5 && i != 4)) || (j == 0 && (i == 4 || i == 5))) printf("|");

        test_color(j,i);

        printf(" %c%d ",plateau[j][i].case1, plateau[j][i].case2);
        printf("\033[40;37m"); //necessaire pour reinitailiser la couleur

        printf("|");
    }else{
        printf("     ");
    }

}

int test_case(int x,int y) {
    int r;
    if ( (x >= 0 && x <= 9) && (y >= 4 && y <= 5) ){
        r = 1;
    }else{
        if ( (x >= 1 && x <= 8) && (y >= 0 && y <= 9) ){
            r = 1;
        }else{
            r = 0;
        }
    }
    return r;
}

int test_fin_partie() {
    int code_retour = 2;

    for (int i = 1;i <= 2;i++){
        if(cheval[i].sorti == 1) code_retour = 0;
    }

    if (code_retour == 0){
        code_retour = 1;
        for (int i = 3;i <= 4;i++){
            if(cheval[i].sorti == 1) code_retour = 0;
        }
    }
    //vérifie si l'un des joueurs n'a plus de chevaux

    if(code_retour == 0){
        for(int i = 1;i <= 2;i++){
            if (cheval[i].position.x == arrivee[3].position.x && cheval[i].position.y == arrivee[3].position.y) code_retour = 1;
            if (cheval[i].position.x == arrivee[4].position.x && cheval[i].position.y == arrivee[4].position.y) code_retour = 1;
        }

        for(int i = 3;i <= 4;i++){
            if (cheval[i].position.x == arrivee[1].position.x && cheval[i].position.y == arrivee[1].position.y) code_retour = 2;
            if (cheval[i].position.x == arrivee[2].position.x && cheval[i].position.y == arrivee[2].position.y) code_retour = 2;
        }
    }
    //vérifie si l'un des joueurs à un cheval sur le arrivée adverse

    return code_retour;
}

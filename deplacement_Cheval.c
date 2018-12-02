#include <stdio.h>
#include <string.h>

#include "deplacement_Cheval.h"

int deplacement(Joueur joueur) {
    int select_num;
    int code_retour = 1, renvoie = 0;
    Cheval *Cheval_selectionne;
    int erreur = 0;

        if (erreur == 1){
            efface_ecran();
            bandeau();
            affiche_plateau();
            printf("Cheval INEXISTANT ");
        }

        printf("Choisissez le Cheval à déplacer\n('1' pour le cheval 1 par exemple) : ");
        scanf("%d",&select_num);

      do{
          efface_ecran();
          bandeau();
          affiche_plateau();

          if (erreur == 1) printf("DÉPLACEMENT IMPOSSIBLE ! ");

          printf("(Entrer 0 pour revenir en arriere)\n");
          erreur = 1;
      }while (erreur == 0);
}

int test_Cheval_select (Color couleur,int num) {
    int code_retour = 0;

  /*if (/*Le cheval sélectionner dans le cas présent peut effectuer le déplacement){ code_retour = 1;}*/

    return code_retour;
}

int test_Cheval_renvoi (Cheval Cheval) {
    int code_retour = 0;
    if (Cheval.sorti == 1) code_retour = 1;
    return code_retour;
}

void deplace_Cheval(Deplacement deplacement, Cheval *Cheval) {
    Cheval->position.x = deplacement.position.x;
    Cheval->position.y = deplacement.position.y;

    if (deplacement.retireCheval != 0) deplacement.retireCheval->sorti = 0;
}

void vide_deplacements(Deplacement deplacement_possible[],int num_max) {
    for (int i = 0; i <= num_max;i++){
			deplacement_possible[i].position.x = 0;
			deplacement_possible[i].position.y = 0;
			deplacement_possible[i].retireCheval = NULL;
		}

    /*for (int i = 0;i <= 9;i++){
        for (int j = 0;j <= 9;j++){
            if (plateau[j][i].couleur == 'V'){reset_case(j,i);}
        }
    }*/
}//Réinitialise le déplacement possible

int deplacement_cheval(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num) {
    int code_retour = 0; //la fonction renvoie 1 si le deplacement a eu lieu, sinon 0

    int x = Cheval->position.x+j, y = Cheval->position.y+i; //rentre les coordonnées de la case dans les valeurs x et y

	if (plateau[x][y].case1 == 'S'){

        if ( (plateau[x+j][y+i].case1 == '0') && (test_case(x+j,y+i) == 1)){

            creer_deplacement(deplacement_possible,x+j,y+i,num);
            deplacement_possible[num].renvoie = 1;
			         code_retour = 1;
		    }
  }

	return code_retour;
}

int deplacement_renvoie(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num) {
    int code_retour = 0;
}

void creer_deplacement(Deplacement deplacement_possible[],int x,int y,int num) {
    plateau[x][y].couleur = 'V';
    //permet de ne pas faire déborder le numéro du déplacement
    if(num >= 10){
        plateau[x][y].case1 = (num/10)+'0';
        plateau[x][y].case2 = (num%10);
    }else{
        plateau[x][y].case1 = ' ';
        plateau[x][y].case2 = num;
    }
    deplacement_possible[num].position.x = x;
    deplacement_possible[num].position.y = y;

    deplacement_possible[num].renvoie = 0;
    deplacement_possible[num].retireCheval = 0;
}

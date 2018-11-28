#include <stdio.h>
#include <string.h>

#include "Couleurs.h"
#include "generationEcurie.c"

#include "deplacement_Cheval.h"
#include "generationEcurie.h"
#include "esthetique.h"
#include "partie.h"
#include "plateau.h"

int deplacement(Joueur joueur);
int test_Cheval_select (Color couleur,int num);
int test_Cheval_renvoi (Cheval Cheval);


void deplace_Cheval(Deplacement deplacement,Cheval *Cheval);
void vide_deplacements(Deplacement deplacement_possible[],int num_max);


int deplacement(Joueur joueur) {
    char select_type,select_num;
    Deplacement deplacement_possible[MAX_TAB];
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

          printf("(entrer 0 pour revenir en arriere)\n");
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

    for (int i = 0;i <= 9;i++){
        for (int j = 0;j <= 9;j++){
            if (plateau[j][i].couleur == 'V'){reset_case(j,i);}
        }
    }
}
//Réinitialise le déplacement possible

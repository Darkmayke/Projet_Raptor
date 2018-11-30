#include <stdio.h>
#include <string.h>

#include "deplacement_Cheval.h"

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
    plateau[x][y].color = 'V';
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

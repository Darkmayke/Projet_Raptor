#include <stdio.h>
#include <string.h>

#include "deplacement_Cheval.h"

int deplacement_singe(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num)
{
    int code_retour = 0; //la fonction renvoie 1 si le deplacement a eu lieu, sinon 0

    int x = Cheval->position.x+j,y = Cheval->position.y+i; //rentre les coordonnées de la case dans les valeurs x et y

	if (plateau[x][y].case1 == 'S'){

        if (plateau[x+j][y+i].case1 == '0' && test_case(x+j,y+i) == 1){ //regarde si la case d'après est vide et dans le plateau

            creer_deplacement(deplacement_possible,x+j,y+i,num);
            deplacement_possible[num].renvoie = 1;           //créer le déplacement et le définit comme un deplacement incluant un shing shang
            code_retour = 1;
        }

    }else if (plateau[x][y].case1 == '0'){

        creer_deplacement(deplacement_possible,x,y,num);
        code_retour = 1;

        if (plateau[x+j][y+i].case1 == '0' && test_case(x+j,y+i) == 1){
            creer_deplacement(deplacement_possible,x+j,y+i,num+1);
            code_retour++;
        }
	}
	return code_retour;
}

int deplacement_lion(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num)
{
    int code_retour = 0;

    int x = Cheval->position.x+j,y = Cheval->position.y+i;

	if (plateau[x][y].case1 == 'S' || plateau[x][y].case1 == 'L'){

        if (plateau[x+j][y+i].case1 == '0' && test_case(x+j,y+i) == 1){

            creer_deplacement(deplacement_possible,x+j,y+i,num);
            deplacement_possible[num].renvoie = 1;
			code_retour = 1;
		}

	}else if (plateau[x][y].case1 == '0'){

        creer_deplacement(deplacement_possible,x,y,num);
		code_retour = 1;
	}
	return code_retour;
}

int deplacement_cheval(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num)
{
    int code_retour = 0; //la fonction renvoie 1 si le deplacement a eu lieu, sinon 0

    int x = Cheval->position.x+j, y = Cheval->position.y+i; //rentre les coordonnées de la case dans les valeurs x et y

	if (plateau[x][y].case1 == 'S' || plateau[x][y].case1 == 'L' || plateau[x][y].case1 == 'D'){

        if ( (plateau[x+j][y+i].case1 == '0' || (plateau[x+j][y+i].case1 == 'P' && plateau[x+j][y+i].color != joueur.color)) && test_case(x+j,y+i) == 1){

            creer_deplacement(deplacement_possible,x+j,y+i,num);
            deplacement_possible[num].renvoie = 1;
			code_retour = 1;
		}
    }

	return code_retour;
}

int deplacement_renvoie(Joueur joueur,Deplacement deplacement_possible[],Cheval *Cheval,int i,int j,int num)
{
    int code_retour = 0;

    int x = Cheval->position.x+j,y = Cheval->position.y+i;

    if(Cheval->type == 'S'){
        if(plateau[x][y].case1 == 'S'){
             if(plateau[x+j][y+i].case1 == '0' && test_case(x+j,y+i) == 1){

                creer_deplacement(deplacement_possible,x+j,y+i,num);
                deplacement_possible[num].renvoie = 1;

                if (plateau[x][y].color != joueur.color){
                    if (joueur.num == 1) deplacement_possible[num].retireCheval = &singe[(plateau[x][y].case2)]+6; //permet de sélectionner le Cheval qui mourrira lors du déplacement
                    else deplacement_possible[num].retireCheval = &singe[plateau[x][y].case2];
                }
                code_retour = 1;
            }
        }

    }else if (Cheval->type == 'L'){
        if(plateau[x][y].case1 == 'S' || plateau[x][y].case1 == 'L'){
             if(plateau[x+j][y+i].case1 == '0' && test_case(x+j,y+i) == 1){

                creer_deplacement(deplacement_possible,x+j,y+i,num);
                deplacement_possible[num].renvoie = 1;

                if (plateau[x][y].color != joueur.color){
                    if (plateau[x][y].case1 == 'S'){
                        if (joueur.num == 1) deplacement_possible[num].retireCheval = &singe[(plateau[x][y].case2)]+6;
                        else deplacement_possible[num].retireCheval = &singe[plateau[x][y].case2];
                    }else if (plateau[x][y].case1 == 'L'){
                        if (joueur.num == 1) deplacement_possible[num].retireCheval = &lion[(plateau[x][y].case2)]+4;
                        else deplacement_possible[num].retireCheval = &lion[plateau[x][y].case2];
                    }
                }
                code_retour = 1;
            }
        }

    }else if (Cheval->type == 'D'){
        if(plateau[x][y].case1 == 'S' || plateau[x][y].case1 == 'L' || plateau[x][y].case1 == 'D'){
             if( (plateau[x+j][y+i].case1 == '0' || (plateau[x+j][y+i].case1 == 'P' && plateau[x+j][y+i].color != joueur.color) ) && test_case(x+j,y+i) == 1){

                creer_deplacement(deplacement_possible,x+j,y+i,num);
                deplacement_possible[num].renvoie = 1;

                if (plateau[x][y].color != joueur.color){
                    if (plateau[x][y].case1 == 'S'){
                        if (joueur.num == 1) deplacement_possible[num].retireCheval = &singe[(plateau[x][y].case2)]+6;
                        else deplacement_possible[num].retireCheval = &singe[plateau[x][y].case2];
                    }else if (plateau[x][y].case1 == 'L'){
                        if (joueur.num == 1) deplacement_possible[num].retireCheval = &lion[(plateau[x][y].case2)]+4;
                        else deplacement_possible[num].retireCheval = &lion[plateau[x][y].case2];
                    }else if (plateau[x][y].case1 == 'D'){
                        if (joueur.num == 1) deplacement_possible[num].retireCheval = &cheval[(plateau[x][y].case2)]+2;
                        else deplacement_possible[num].retireCheval = &cheval[plateau[x][y].case2];
                    }
                }
                code_retour = 1;
            }
        }
    }
    return code_retour;
}


void creer_deplacement(Deplacement deplacement_possible[],int x,int y,int num)
{
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

#include <stdio.h>
#include <string.h>

#include "mouvements.h"

int deplacement(Joueur joueur) {
    char select_type,select_num;
    Deplacement deplacement_possible[MAX_TAB];
    int code_retour = 1, renvoie = 0, num_deplacements_max = 0;
    Cheval *Cheval_selectionne;
    int erreur = 0;

    do{

        if (erreur == 1){
            efface_ecran();
            bandeau();
            affiche_plateau();
            printf("Cheval INEXISTANT ");
        }

        printf("Choisissez le Cheval à déplacer\n('D1' pour le cheval 1 par exemple) : ");
        scanf("%c%d",&select_type,&select_num);

        select_type = toupper(select_type); //permet de mettre en majuscule le Cheval choisit

        if (select_type == 'D'){

            if (joueur.num == 2) Cheval_selectionne = &cheval[select_num+2];
            else Cheval_selectionne = &cheval[select_num];

        }else if (select_type == 'L'){

            if (joueur.num == 2) Cheval_selectionne = &lion[select_num+4];
            else Cheval_selectionne = &lion[select_num];

        }else{

            if (joueur.num == 2) Cheval_selectionne = &singe[select_num+6];
            else Cheval_selectionne = &singe[select_num];
        }
        //selectionne le Cheval
        erreur = 1;

    }while (test_Cheval_select(select_type,select_num) == 0 || test_Cheval_mort(*Cheval_selectionne) == 0); //test si le Cheval existe et est encore sorti

    num_deplacements_max = affiche_deplacements_possibles(joueur,Cheval_selectionne,deplacement_possible,renvoie); //creer tout les deplacement possible à partir du Cheval selectionne

    int deplacement_select = 0;
    erreur = 0;
    do{
        efface_ecran();
        bandeau();
        affiche_plateau();

        if (erreur == 1) printf("DEP. IMPOSSIBLE ! ");

        printf("(entrer 0 pour revenir en arriere)\n");
        printf("Choisissez le numero du deplacement a effectuer : ");
        scanf("%d",&deplacement_select);
        erreur = 1;
    }while (test_deplacement_select(deplacement_select,num_deplacements_max) == 0 && deplacement_select != 0); //test si le deplacement existe

    if(deplacement_select == 0) code_retour = 0; //retourne 0 si le joueur choisit de faire un autre deplacement

    else{
        deplace_Cheval (deplacement_possible[deplacement_select],Cheval_selectionne); //deplace le Cheval
        vide_deplacements(deplacement_possible,num_deplacements_max);

        //test si le Cheval n'est pas en shing shang
        if (deplacement_possible[deplacement_select].renvoie == 1){
            renvoie = 1;
            num_deplacements_max = affiche_deplacements_possibles(joueur,Cheval_selectionne,deplacement_possible,renvoie);
            //test les différents déplacement possibles

            while(num_deplacements_max >= 1 && deplacement_select != 0){ //test si un ou des deplacements sont possibles, sinon sort de la boucle
                actualise_plateau();
                bandeau();
                affiche_plateau();
                erreur = 0;

                do{
                    if(erreur = 1){
                        efface_ecran();
                        bandeau();
                        affiche_plateau();
                    }

                    printf("SHING SHANG (entrer 0 pour arreter le deplacement)\n");
                    printf("Choisissez le numero du deplacement a effectuer : ");
                    scanf("%d",&deplacement_select);
                    erreur = 1;
                }while (test_deplacement_select(deplacement_select,num_deplacements_max) == 0 && deplacement_select != 0);

                if(deplacement_select > 0){
                    deplace_Cheval (deplacement_possible[deplacement_select],Cheval_selectionne);
                    num_deplacements_max = affiche_deplacements_possibles(joueur,Cheval_selectionne,deplacement_possible,renvoie);
                }
            }

        }
        actualise_plateau();
    }
    vide_deplacements(deplacement_possible,num_deplacements_max);
    return code_retour;
}

int test_Cheval_select (char type,int num) {
    int code_retour = 0;

    if (type == 'D') {if (num == 1 || num == 2) code_retour = 1;}
    if (type == 'L') {if (num >= 1 && num <= 4) code_retour = 1;}
    if (type == 'S') {if (num >= 1 && num <= 6) code_retour = 1;}

    return code_retour;
}

int test_Cheval_mort (Cheval Cheval) {
    int code_retour = 0;
    if (Cheval.sorti == 1) code_retour = 1;
    return code_retour;
}

int affiche_deplacements_possibles(Joueur joueur,Cheval *Cheval,Position deplacement_possible[],int renvoie) {
    int num = 1;
    for (int i = (-1); i <= 1;i++)
    {
        for (int j = (-1); j <= 1;j++){
            if (test_case(Cheval->position.x+j,Cheval->position.y+i) == 1){ // regarde si la case n'est pas hors du plateau
                if (i != 0 || j != 0 ){ //regarde si ce n'est pas la case du Cheval selectionné
                    if (Cheval->type == 'S'){
                        if (renvoie == 1) num += deplacement_renvoie(joueur,deplacement_possible,Cheval,i,j,num);
                        else num += deplacement_singe(joueur,deplacement_possible,Cheval,i,j,num);
                    }else if(Cheval->type == 'L'){
                        if (renvoie == 1) num += deplacement_renvoie(joueur,deplacement_possible,Cheval,i,j,num);
                        else num += deplacement_lion(joueur,deplacement_possible,Cheval,i,j,num);
                    }else if(Cheval->type == 'D'){
                        if (renvoie == 1) num += deplacement_renvoie(joueur,deplacement_possible,Cheval,i,j,num);
                        else num += deplacement_cheval(joueur,deplacement_possible,Cheval,i,j,num);
                    }
                }
            }
        }
    }
    return num-1; //renvoie le nombre possible de déplacement
}

int test_deplacement_select(int num_deplacement,int num_max) {
    int code_retour;
    if (num_deplacement <= num_max && num_deplacement > 0) code_retour = 1;
    else code_retour = 0;
    return code_retour;
}

void deplace_Cheval(Deplacement deplacement,Cheval *Cheval) {
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
            if (plateau[j][i].color == 'V') reset_case(j,i);
        }
    }
}

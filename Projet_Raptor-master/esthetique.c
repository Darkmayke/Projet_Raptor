#include <stdio.h>
#include <string.h>

#include "esthetique.h"

void bandeau() {
    printf(" {==============================================}\n");
    printf(" {==============================================}\n");
    printf(" {                 LES PETITS CHEVAUX           }\n");
    printf(" {==============================================}\n");
    printf(" {======by CASSEGRAIN Loris & MOREAU Baptise ===}\n\n");
}

void efface_ecran() {
    printf("\e[2J\e[H");
}

void informations_partie(num_tour,couleur_joueur) {
    char nom_couleur_joueur[10];
    if (couleur_joueur == 'R') nom_couleur_joueur[10] = "Rouge";
    else nom_couleur_joueur[10] = "Bleu";
    printf("     TOUR : %d    |    Au joueur %s de jouer\n",num_tour,nom_couleur_joueur);
}

void retour_menu() {
    char s,a;

    printf("APPUYEZ POUR QUITTER");

    do{
         s=getchar();
    }while(s!='\n');

    putchar(a);
}

//Permet de vider le buffer
void clean(){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

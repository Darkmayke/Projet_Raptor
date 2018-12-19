#include <stdio.h>
#include <string.h>

#include "esthetique.h"

void regles() {
    char touche;
    efface_ecran();
    bandeau();
    printf("\n Voici les règles du jeu :");
    printf("\n\n Appuyez sur entrée pour revenir au menu ");
    clean();
    scanf("%c",&touche);
}

void bandeau() {
    printf(" {==============================================}\n");
    printf(" {==============================================}\n");
    printf(" {              LES PETITS CHEVAUX              }\n");
    printf(" {==============================================}\n");
    printf(" {====by CASSEGRAIN Loris & MOREAU Baptiste© ===}\n\n");
}

void efface_ecran() {
    printf("\e[2J\e[H");
}

void retour_menu() {
    char s,a;

    printf("APPUYEZ POUR QUITTER");

    do{
         s=getchar();
    }while(s!='\n');

    putchar(a); //met fin au fichier
}

//Permet de vider le buffer
void clean(){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

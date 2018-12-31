#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "esthetique.h"

void regles() {
    char touche;
    efface_ecran();
    bandeau();
    printf("\nVoici les règles du jeu :\n\n");

    printf("Le jeu des petits chevaux se joue de 2 à 4 joueurs.\nChaque joueurs possèdent 4 chevaux d'une et d'une seule couleur.\n\n");
    printf("Le but du jeu est d'ammener la totalité de ses pions dans les 6 cases numérotées.");
    printf("\nPour sortir un pion de l’écurie et venir le placer sur la première case de son parcours, le joueur doit faire un 6 avec le dé.");
    printf("\nS’il n’a pas fait 6, il passe son tour.");
    printf("\nPendant la partie, il faudra obligatoirement faire un 6 pour mettre un nouveau pion sur la piste.");
    printf("\n\n\n Les règles ci-dessous définissent le déplacement des pions sur le plateau.");
    printf("\n\n  — Une fois un pion sorti, le joueur le fait avancer du nombre de cases égal aux pions du dé.");
    printf("\n    S’il a plusieurs pions sortis, le joueur peut faire avancer, au choix, n’importe lequel de ses pions en piste.");
    printf("\n\n  — Un joueur qui fait 6 rejoue automatiquement une deuxième fois et peut, au choix, faire sortir un cheval ou avancer de 6 cases.");
    printf("\n\n  — Un pion dont la route est barrée par un autre pion adverse ne peut se déplacer et passera son tour si les points du dé l’amène au-delà du barrage.");
    printf("\n\n  — En revanche, si le tirage au dé permet à un joueur de placer son pion exactement sur une case déjà occupée par un pion adverse,");
    printf("\n    il renvoie le pion de l’adversaire à l’écurie et prend sa place. Celui qui retourne à l’écurie repart donc de zéro et doit obtenir de nouveau un 6 pour sortir.");
    printf("\n\nToutefois, deux pions de la même couleur peuvent se poser sur la même case.");

    printf("\n\n Appuyez sur entrée pour revenir au menu ");
    clean();
    scanf("%c",&touche);
}

void bandeau() {
    printf(" {==============================================}\n");
    printf(" {==============================================}\n");
    printf(" {              LES PETITS CHEVAUX              }\n");
    printf(" {==============================================}\n");
    printf(" {=== by CASSEGRAIN Loris & MOREAU Baptiste© ===}\n\n");
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

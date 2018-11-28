#include <stdio.h>
#include <stdlib.h>

#include "Couleurs.h"

#include "deplacement_Cheval.h"
#include "generationEcurie.h"
#include "esthetique.h"
#include "partie.h"
#include "plateau.h"

void generation_ecurie();
void creer_cheval(Cheval *Cheval, Color couleur, int num,int x,int y);

void generation_ecurie() {
    //CRÉATION DES CHEVAUX JOUEUR JAUNE
    creer_cheval(&cheval[1],'J',1,2,1);
    creer_cheval(&cheval[2],'J',2,3,2);
    creer_cheval(&cheval[3],'J',3,4,3);
    creer_cheval(&cheval[4],'J',4,5,4);

    //CRÉATION DES CHEVAUX JOUEUR BLEU
    creer_cheval(&cheval[6],'B',1,46,1);
    creer_cheval(&cheval[7],'B',2,45,2);
    creer_cheval(&cheval[8],'B',3,44,3);
    creer_cheval(&cheval[9],'B',4,43,4);
    //CRÉATION DES CHEVAUX JOUEUR ROUGE
    creer_cheval(&cheval[10],'R',1,46,15);
    creer_cheval(&cheval[11],'R',2,45,14);
    creer_cheval(&cheval[12],'R',3,44,13);
    creer_cheval(&cheval[13],'R',4,43,12);
    //CRÉATION DES CHEVAUX JOUEUR VERT
    creer_cheval(&cheval[14],'V',1,1,0);
    creer_cheval(&cheval[15],'V',2,8,0);
    creer_cheval(&cheval[16],'V',3,1,9);
    creer_cheval(&cheval[16],'V',4,8,9);

    //CRÉATIONS DE L'ARRIVÉE
    creer_cheval(&arrivee[1],'J',0,24,10);
}

void creer_cheval(Cheval *Cheval,Color couleur, int num,int x,int y) {
    Cheval->couleur = couleur;
    Cheval->num = num;
    Cheval->position.x = x;
    Cheval->position.y = y;
    Cheval->sorti = 1;
}

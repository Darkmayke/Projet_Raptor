#include <stdio.h>
#include <stdlib.h>

#include "plateau.h"

void actualise_plateau() {
    //REMPLI LE RESTE DU TABLEAU DES CASES VIDES
    for (int i = 0; i <= 9;i++){

        for (int j = 0; j <= 9;j++){

            if(plateau[j][i].color != 'V') reset_case(j,i);
        }
    }

    for (int i = 1; i <= 12;i++) {
        if (plateau[arrivee[i].position.x][arrivee[i].position.y].color != 'V'){
        rentre_cheval(arrivee[i]);
        }
        rentre_cheval(cheval[i]);
    }
}

void rentre_cheval(Cheval Cheval) {
    if (Cheval.sorti == 1){
        //affiche le Cheval sur le plateau
        plateau[Cheval.position.x][Cheval.position.y].color = Cheval.color;
        plateau[Cheval.position.x][Cheval.position.y].case1 = Cheval.type;
        plateau[Cheval.position.x][Cheval.position.y].case2 = Cheval.num;
    }else{
        //permet de faire sortir le Cheval mort du plateau
        Cheval.position.x = -1; //Mettre les positions respectives des écuries
        Cheval.position.y = -1; //Mettre les positions respectives des écuries
    }
}

void reset_case(int x,int y) {
    plateau[x][y].color = '0';
    plateau[x][y].case1 = '0';
    plateau[x][y].case2 = 0;
}

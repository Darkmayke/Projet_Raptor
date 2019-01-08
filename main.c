#include <stdio.h>
#include <stdlib.h>

//#include <unistd.h>
#include "esthetique.h"
#include "partie.h"

int main(void){
    printf("\033[40;37m"); //initialise la couleur de base pour tout le programme

    int fin = 0;
    int choix;

    efface_ecran();
    do{
        do{
            bandeau();
            printf("\n   1.Jouer\n\n");
            printf("   2.Règles\n\n");
            printf("   3.Quitter\n\n");
            printf("   CHOIX : ");
            scanf("%d",&choix);
            efface_ecran();
        }while(choix < 1 || choix > 3);

        clean();

        switch (choix) {
            case 1 : nouvelle_partie();
            //sleep(999);
                     break;

            case 2 : regles();
                     break;

            case 3 : fin = 1;
                     break;

            default : break;
        }

        efface_ecran();
        choix = 0;

    }while (fin != 1);

    return 0;
}

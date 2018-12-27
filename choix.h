#ifndef CHOIX_H
#define CHOIX_H

#include "h.h"
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn choix_depart désigne le joueur qui commence la partie. Elle prend en paramètre
    le nombre maximum de joueurs présent dans la partie.
  *\param max désigne le nombre maximum de joueurs présent dans la partie.
  *\return choix_d le numéro du joueur choisi pour commencer la partie.
*/
int choix_depart(int max);
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn De est la fonction symbolisant le dé qui décide du nombre de case que le cheval va parcourir.
  *\return lancer le nombre de case que le cheval va parcourir.
*/
int De(void);
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn choix est une des fonctions de gestions de partie. Elle demande à l'utilisateur
    le nombre de joueurs, leur nom, et la couleur qu'ils désirent.
  *\param *p_recupDe récupère la valeur retournée par la fonction De.
  *\param *p_recupDe récupère la valeur retournée par la fonction choix_depart.
  *\param *j afin d'enregistrer les données dans un nouveau joueur.
  *\param *nb_joueur afin de créer le nombre de joueur voulu 
*/
void choix(int *p_recupDe, int *p_recupChoix, Joueur *j, int *nb_joueur);
////////////////////////////////////////////////////////////////////////////////

#endif

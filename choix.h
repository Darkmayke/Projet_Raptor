#ifndef CHOIX_H
#define CHOIX_H

#include "h.h"
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn choix_depart désigne le joueur qui joue au prochain tour.
  *\param
*/
int choix_depart(int *compteur_j, int *nb_joueur);
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn De est la fonction symbolisant le dé qui décide du nombre de case que le cheval va parcourir.
  *\return lancer le nombre de case que le cheval va parcourir.
*/
int De(Joueur player[], Cheval ecurie[], int *recupChoix, Case cases[], int *position, int *recupchoixcheval, int *IDcheval, int *recupDe);
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn choix est une des fonctions de gestions de partie. Elle demande à l'utilisateur
    le nombre de joueurs, leur nom, et la couleur qu'ils désirent.
  *\param *p_recupDe récupère la valeur retournée par la fonction De.
  *\param *p_recupDe récupère la valeur retournée par la fonction choix_depart.
  *\param *j afin d'enregistrer les données dans un nouveau joueur.
  *\param *nb_joueur afin de créer le nombre de joueur voulu 
*/
int choix(Joueur *j, int *nb_joueur, int *recupChoix);
////////////////////////////////////////////////////////////////////////////////

#endif

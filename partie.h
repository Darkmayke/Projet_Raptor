#ifndef PARTIE_H
#define PARTIE_H

#include "h.h"
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn nouvelle_partie est une fonction de type void sert de main secondaire.
          Il appelle toutes les autres fonctiones principale permettant le
          déroulement d'une partie.
*/
void nouvelle_partie();
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn creer_cheval est la fonction permettant de créer les 16 chevaux
          en fonction du nombre de joueurs.
*/
void creer_cheval(Cheval ecurie[], Joueur player[], int *nb_joueur); //ajouter un ID général
////////////////////////////////////////////////////////////////////////////////

#endif

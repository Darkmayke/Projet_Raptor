#ifndef PLATEAU_H
#define PLATEAU_H
#include "h.h"

////////////////////////////////////////////////////////////////////////////////
/**
  *\fn affichePlateau permet d'afficher le tableau dans sa forme graphique.
*/
int affichePlateau();
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn chemin permet de retourner au début du chemin respectif à chaque cheval.
*/
void chemin(int *p_recupDe, Case cases[], int *p_position, int *IDcheval, int *recupchoixcheval, Cheval ecurie[], Joueur player[]);
////////////////////////////////////////////////////////////////////////////////
void deplacement(int *position, Case cases[], Cheval ecurie[], int *IDcheval, int *recupchoixcheval);
////////////////////////////////////////////////////////////////////////////////
void echelle_fin(Case cases[], Cheval ecurie[], int *IDcheval, int pos_echelle, int recupcouleur);
////////////////////////////////////////////////////////////////////////////////
int marche(Case cases[], Cheval ecurie[], int *IDcheval, int *p_recupDe, int *recupchoixcheval, int r_ID);
////////////////////////////////////////////////////////////////////////////////
void verif_conflit(Case cases[], Cheval ecurie[], Joueur player[], int *p_position, int *recupchoixcheval, int r_ID);
#endif

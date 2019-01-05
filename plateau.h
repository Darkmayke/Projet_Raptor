#ifndef PLATEAU_H
#define PLATEAU_H
#include "h.h"

////////////////////////////////////////////////////////////////////////////////
/**
  *\fn affichePlateau permet d'afficher le tableau dans sa forme graphique.
*/
void affichePlateau();

////////////////////////////////////////////////////////////////////////////////

void actualisePlateau(int cases,int IDcheval);

////////////////////////////////////////////////////////////////////////////////

void recupereEmplacementGrille(int numCase,int *x,int *y);

////////////////////////////////////////////////////////////////////////////////

void afficheCouleur(int i,int j);

////////////////////////////////////////////////////////////////////////////////

/**
  *\fn chemin permet de retourner au début du chemin respectif à chaque cheval.
*/
void chemin(int *p_recupDe, Case cases[], int *p_position, int *IDcheval, int *recupchoixcheval, Cheval ecurie[], Joueur player[]);
////////////////////////////////////////////////////////////////////////////////
void deplacement(int *position, Case cases[], Cheval ecurie[], int *IDcheval, int *recupchoixcheval);
////////////////////////////////////////////////////////////////////////////////
#endif

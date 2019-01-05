#ifndef PLATEAU_H
#define PLATEAU_H
#include "h.h"

////////////////////////////////////////////////////////////////////////////////
/**
  *\fn affichePlateau permet d'afficher le tableau dans sa forme graphique.
*/
void affichePlateau();

////////////////////////////////////////////////////////////////////////////////

void actualisePlateau(int cases,int IDcheval,Color couleur);
// Permet de mettre a jour le plateau de jeu en fonction des déplacements qui on été effectué
////////////////////////////////////////////////////////////////////////////////

void recupereEmplacementGrille(int numCase,int *x,int *y, Color couleur);
// Récupère la position selon des axe x et y d'un cheval sur le plateau
////////////////////////////////////////////////////////////////////////////////

void afficheCouleur(int i,int j);

////////////////////////////////////////////////////////////////////////////////

void afficherCouleurCheval(int i,int j);

////////////////////////////////////////////////////////////////////////////////

/**
  *\fn chemin permet de retourner au début du chemin respectif à chaque cheval.
*/
void chemin(int *p_recupDe, Case cases[], int *p_position, int *IDcheval, int *recupchoixcheval, Cheval ecurie[], Joueur player[]);
////////////////////////////////////////////////////////////////////////////////

void deplacement(int *position, Case cases[], Cheval ecurie[], int *IDcheval, int *recupchoixcheval);
// Permet de faire avancer un Cheval sur le tableau Cases
////////////////////////////////////////////////////////////////////////////////

void echelle_fin(Case cases[], Cheval ecurie[], int *IDcheval, int pos_echelle, int recupcouleur);
// Permet de faire avancer un Cheval sur l'echelle de fin de jeu
////////////////////////////////////////////////////////////////////////////////

int marche(Case cases[], Cheval ecurie[], int *IDcheval, int *p_recupDe, int *recupchoixcheval, int r_ID);
// Vérifie si les conditions sont réunis pour pouvoir faire avancer un cheval sur l'échelle de fin de jeu
////////////////////////////////////////////////////////////////////////////////

void verif_conflit(Case cases[], Cheval ecurie[], Joueur player[], int *p_position, int *recupchoixcheval, int r_ID);
//Vérifie si il y a un cheval sur la case d'arrivée

#endif

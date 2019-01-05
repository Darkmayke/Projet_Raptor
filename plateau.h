#ifndef PLATEAU_H
#define PLATEAU_H
#include "h.h"

////////////////////////////////////////////////////////////////////////////////
/**
  *\fn affichePlateau permet d'afficher le tableau dans sa forme graphique.
*/
void affichePlateau();
////////////////////////////////////////////////////////////////////////////////
/**
	*\fn Permet de mettre a jour le plateau de jeu en fonction des déplacements qui on été effectué
*/
void actualisePlateau(int cases,int IDcheval,Color couleur);
////////////////////////////////////////////////////////////////////////////////
/**
	*\fn Récupère la position selon des axe x et y d'un cheval sur le plateau
*/
void recupereEmplacementGrille(int numCase,int *x,int *y, Color couleur);
////////////////////////////////////////////////////////////////////////////////
/**
	*\fn
*/
void afficheCouleur(int i,int j);
////////////////////////////////////////////////////////////////////////////////
/**
	*\fn
*/
void afficherCouleurCheval(int i,int j);
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn chemin permet faire déplacer les chevaux sur le plateau.
*/
void chemin(int *p_recupDe, Case cases[], int *p_position, int *IDcheval, int *recupchoixcheval, Cheval ecurie[], Joueur player[]);
////////////////////////////////////////////////////////////////////////////////
/**
	*\fn Permet d'enregistrer un Cheval sur le tableau Cases
*/
void deplacement(int *position, Case cases[], Cheval ecurie[], int *IDcheval, int *recupchoixcheval);
////////////////////////////////////////////////////////////////////////////////
/**
	*\fn Permet d'enregistrer un Cheval sur l'echelle de fin de jeu
*/
void echelle_fin(Case cases[], Cheval ecurie[], int *IDcheval, int pos_echelle, int recupcouleur);
////////////////////////////////////////////////////////////////////////////////
/**
	*\fn Vérifie si les conditions sont réunis pour pouvoir faire avancer un cheval sur l'échelle de fin de jeu
*/
int marche(Case cases[], Cheval ecurie[], int *IDcheval, int *p_recupDe, int *recupchoixcheval, int r_ID);
////////////////////////////////////////////////////////////////////////////////
/**
	*\fn Permet de vérifier si il y a un cheval sur la case d'arrivée
*/
void verif_conflit(Case cases[], Cheval ecurie[], Joueur player[], int *p_position, int *recupchoixcheval, int r_ID);
#endif

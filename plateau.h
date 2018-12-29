#ifndef PLATEAU_H
#define PLATEAU_H

////////////////////////////////////////////////////////////////////////////////
/**
  *\fn affichePlateau permet d'afficher le tableau dans sa forme graphique.
*/
int affichePlateau();
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn chemin permet de retourner au début du chemin respectif à chaque cheval.
*/
void chemin(int *p_recupDe, Case *p_c, int *p_position, int *IDcheval, int *recupchoixcheval);
////////////////////////////////////////////////////////////////////////////////
void deplacement(int *p_recupDe, Case *p_c, int *p_position, int *IDcheval, int *recupchoixcheval);
#endif

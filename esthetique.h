#ifndef ESTHETIQUE_H
#define ESTHETIQUE_H

////////////////////////////////////////////////////////////////////////////////
/**
  *\fn regles sert à afficher les règles dans le menu éponyme.
*/
void regles();
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn bandeau affiche un bandeau comportant le nom du jeu ainsi que les noms
    des étudiants ayant conçu le programme.
*/
void bandeau();
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn efface_ecran permet d'effectuer l'équivalent d'un Crtl+l (clear)
    sur le terminal, permettant ainsi de donner un aspect fluide et propre au programme.
*/
void efface_ecran();
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn retour_menu permet de retourner au menu principal de sélection.
*/
void retour_menu();
////////////////////////////////////////////////////////////////////////////////
/**
  *\fn retour permet de vider le buffer avant ou suite à une saisie.
*/
void clean();

#endif

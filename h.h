#ifndef H_H
#define H_H

#define MAX_TAB 20

////////////////////////////////////////////////////////////////////////////////
/**
  * \enum Color
  * \brief Représente les couleurs des 4 écuries.
*/
typedef enum {
  BLEU,
  ROUGE,
  VERT,
  JAUNE
}Color;
////////////////////////////////////////////////////////////////////////////////
/**
  * \struct Joueur h.h "h"
  * \brief Structure d'un joueur comportant sa couleur, son nom ainsi que son numéro.
  * \param couleur correspond à la couleur choisie par le Joueur
  * \param nom correspond au nom choisi par le joueur. Il est de 20 caractères maximum.
  * \param num correspond au numéro du joueur.
 */
typedef struct {
  Color couleur;
  char nom[20];
  int num;
}Joueur;
////////////////////////////////////////////////////////////////////////////////
/**
  * \struct Cheval h.h "h"
  * \brief Structure d'un Cheval comportant sa couleur et son numéro.
  * \param couleur détermine la couleur du cheval.
  * \param num détermine le numéro du cheval.
*/
typedef struct {
  Color couleur;
  int num;
}Cheval;
////////////////////////////////////////////////////////////////////////////////
/**
  * \struct case plateau.h "Plateau"
  * \brief Structure de case qui prends chaque écurie dans chaque case et qui affiche le nombre de chevaux présents dans cette dernière.
  * \ Elle a 2 état vide et non vide
  * \ Si non vide alors elle prend en mémoire l'/les identifiant/s du/des cheval/aux qui est/sont sur cette case
  * \ Ne peut contenir que des chevaux de même couleur et que 4 chevaux au maximum
  * \ 
 */
 typedef struct{
	 Color couleur;
	 int IDcheval1;
	 int IDcheval2;
	 int IDcheval3;
	 int IDcheval4;
 }Case;


#endif

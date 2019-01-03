#ifndef H_H
#define H_H

#define MAX_TAB 20

////////////////////////////////////////////////////////////////////////////////
/**
  * \enum Color
  * \brief Représente les couleurs des 4 écuries.
*/
typedef enum {
  VERT,
  JAUNE,
  BLEU,
  ROUGE,
  BLANC
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
  int cheval_e;
  int cheval_dispo[4];
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
  int position_c;
}Cheval;
////////////////////////////////////////////////////////////////////////////////
/**
  * \struct case plateau.h "Plateau"
  * \brief Structure de case qui prends chaque écurie dans chaque case et qui
      affiche le nombre de chevaux présents dans cette dernière.
  * \ Elle a 2 états, vide et non vide
  * \ Si non vide alors elle prend en mémoire l'/les identifiant/s du/des cheval/aux qui est/sont sur cette case
  * \ Ne peut contenir que 4 des chevaux d'une même couleur.
 */
 typedef struct{
	 Color couleur;
	 int IDcheval1;
	 int IDcheval2;
	 int IDcheval3;
	 int IDcheval4;
 }Case;


#endif

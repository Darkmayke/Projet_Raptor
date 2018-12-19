#include <stdio.h>
#include "partie.h"

void nouvelle_partie() {
  int recupDe;
  int recupChoix;

  choix(&recupDe, &recupChoix);
  printf("recupDe = %d | recupChoix = %d\n\n",recupDe, recupChoix);
  affichePlateau();
  chemin(&recupDe);
}

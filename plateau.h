#ifndef PLATEAU_H
#define PLATEAU_H

#define MAX_TAB 20

Cheval cheval[MAX_TAB];
Cheval arrivee[MAX_TAB];
Plateau plateau[10][10];

void actualise_plateau();
void rentre_cheval(Cheval Cheval);
void reset_case();

#endif

#ifndef MANCHESTERDIFF_H_INCLUDED
#define MANCHESTERDIFF_H_INCLUDED

#include <stdio.h>
#include <string.h>

#define DIM   (11)
#define BASSO (0) ///LIVELLO
#define ALTO  (1) ///LIVELLO
#define SOPRA (1) ///LINEA
#define SOTTO (0) ///LINEA

void Codifica_ManchesterDifferenziato(char* szOnde);
void StampaLegenda(char* szonde);
void LetturaStringa(char* szOnde, int linea);
int BitOndaSotto(int come, char valore);
int BitOndaSopra(int come, char valore);
void ControlloSopra(char* szOnde, int i, int come);
void ControlloSotto(char* szOnde, int i, int come);

#endif // MANCHESTERDIFF_H_INCLUDED

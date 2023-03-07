#pragma once
#ifndef PontResistifs
#define PontResistifs
#include "PontResistifs.h"

//...................................constantes

const int nombreMaxDeResPontDiv = 10;
const int tensionMaxPontDiv = 30;
const int valeurMaxRes = 10000000;
const int valeurMinRes = 0.1;

//...................................structures

typedef struct {
	int nbResComposantPonRes;
	int tensionAlimPontRes;
	int tbValRes;
	int tbValTensionRes;
}PontDiviseur;

//...................................Prototypes

int InitInofoPontDiviseur(PontDiviseur* demoPonDiv);
int CalculTensionPontDiviseur(PontDiviseur* demoPonDiv);
int AfficheTensionPontDiviseur(PontDiviseur demoPonDiv);


#endif // !PontResistifs

#ifndef PONT_RESISTIF_H
#define PONT_RESISTIF_H

//d�clarations des constantes(si marche pas utiliser define)
#define nbMaxResistance 10
#define tensionMax 30
#define valMaxResistance 10e6
#define valMinResistance 0.1

//d�clarations des structures

typedef struct {
	unsigned char nbDeResistance;
	unsigned char tensionAlimVe;
	float valeurResistance[10];
	float valeurTension[10];
}pontDiviseur;

//d�clarations des prototypes des fonctions

void InitInfoPontDiviseur(pontDiviseur* demoPontDiv);
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv);
void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv);

#endif // PONT_RESISTIF_H
//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 1 Semestre2 Pont resistif 
// Nom du fichier 		: PontResistifs.h
// Date de création 	: 07.03.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR (Jérémy Affolter)
//
// Description          : 
//
//
// Remarques			: voir donnee de l'épreuve            
//----------------------------------------------------------------------------------//


#ifndef HEADER
#define HEADER

// Variables globales
#define NBMAXRES	10			// Nombre maximum de résistances
#define	VCCMAX		30			// Tension maximum du pont
#define RMAX		10000000.0	// Valeur maximum d'une résistnace
#define	RMIN		0.1			// Valeur minimum d'une résistance

// Stuctures
#ifndef STRUCTURE_H
#define	STRUCTURE_H
typedef struct
{
	char nbRes;		// Nombre de résistances dans le pont
	char vccPont;	// Tension d'alimentation du pont
	int	tb_ValRes[10];	// Tableau comprenant la valeur des résistances
	float tb_URes[10];	// Tableau comprenant la tension sur chaque résistance
}pontDiviseur;
#endif // ! STRUCTURE_H


// Prototype de fonction
void InitInfoPontDiviseur(pontDiviseur* demoPontDiv);
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv);
void AffichageTensionPontDiviseur(pontDiviseur* demoPontDiv);

#endif
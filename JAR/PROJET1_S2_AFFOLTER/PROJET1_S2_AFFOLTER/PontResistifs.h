//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 1 Semestre2 Pont resistif 
// Nom du fichier 		: PontResistifs.h
// Date de cr�ation 	: 07.03.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR (J�r�my Affolter)
//
// Description          : 
//
//
// Remarques			: voir donnee de l'�preuve            
//----------------------------------------------------------------------------------//


#ifndef HEADER
#define HEADER

// Variables globales
#define NBMAXRES	10			// Nombre maximum de r�sistances
#define	VCCMAX		30			// Tension maximum du pont
#define RMAX		1e7			// Valeur maximum d'une r�sistnace
#define	RMIN		0.1			// Valeur minimum d'une r�sistance

// Stuctures
typedef struct
{
	char nbRes;		// Nombre de r�sistances dans le pont
	char vccPont;	// Tension d'alimentation du pont
	float	tb_ValRes[10];	// Tableau comprenant la valeur des r�sistances
	float	tb_URes[10];	// Tableau comprenant la tension sur chaque r�sistance
}pontDiviseur;


// Prototype de fonction
void InitInfoPontDiviseur(pontDiviseur* demoPontDiv);
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv);
void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv);

#endif
/*
 -------------------------------------------------
 -- Projet : PROJET1_S2_LEO_MENDES				--
 -- Fichier : pontsResistifs.h					--
 -- Versions : 1.0								--
 -- Date : 07.03.23								--
 -- Autheur : Léo Mendes						--
 -------------------------------------------------
*/

#ifndef FONCTIONS
#define FONCTIONS

// Définition
#define MAXRES 1e7
#define MINRES 0.1
#define MAXTENSION 30
#define NBRMAXRES 10
#define DEFAULTMAXRES 10
#define DEFAULTMINRES 1
#define DEFAULTVMIN 1

//Déclaration de constante 
static const int nbrMaxRes = NBRMAXRES;
static const int maxTension = MAXTENSION; //en volt
static const double maxRes = MAXRES; //10 Mega Ohm
static const float minRes = MINRES; //1 Ohm

//-- déclaration de structure --// 
typedef struct 
{
	int nbrRes;	//Nombre de resistance dans le ponts resistif (R1-Rn)
	int vAlim;	//Tension d'alimentation du pont resistif
	float tab_ValRes[10]; // Valeur des resistance
	float tab_ValTension[10]; // Potentiel au borne de chaque resistance
}pontDiviseur;

//Prototype de fonctions 
void InitInfoPontDiviseur(pontDiviseur* demoPontDiv);
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv );
void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv);

#endif
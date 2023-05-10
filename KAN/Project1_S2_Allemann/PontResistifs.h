/*
*	Nom du projet:		Project_S2_Allemann
*	Nom du fichier:		PontResistifs.h
*	Auteur:				Kevin Allemann
*	Date de création:	07.03.2022
*
*	Description:		en tête de mainProject1
*/

#ifndef ENTETE_MES_FONCTIONS
#define ENTETE_MES_FONCTIONS

const MAX_NOMBRE_RESISTANCES 10
#define TENSION_MAX_PONT_DIVISEUR 30
#define VALEUR_MAX_RESISTANCE 10e6 // 10*10^6
#define VALEUR_MIN_RESISTANCE 0.1

typedef struct {
	int nbr_resistance;
	int tension_ve;
	double taille_resistance[MAX_NOMBRE_RESISTANCES];
	float valeur_tension_R[MAX_NOMBRE_RESISTANCES];
}pontDiviseur;

void InitInfoPontDiviseur(pontDiviseur* demoPontDiv);
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv);
void AffichageTensionDiviseur(pontDiviseur demoPontDiv);



#endif

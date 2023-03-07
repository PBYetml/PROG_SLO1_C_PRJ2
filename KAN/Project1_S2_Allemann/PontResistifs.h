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

static int nbr_max_resist = 10;
static int tension_max = 30;
static float resistance_valmax = 10000000;
static float resistance_valmin = 0.1;

struct pontDiviseur
{
	int nbr_resistance;
	int tension_ve;
	double taille_resistance[10];
	double valeur_tension_R[10];
}pontDiviseur;

extern void InitInfoPontDiviseur(int a);
extern void CalculTensionPontDivisueur();
extern void AffichageTensionDivisueur();



#endif
/*	Nom du projet           : PROJET1_S1_ALLEMANN_KEVINYVESTOBIAS
*	Nom du fichier			: fonctionPontDiv.c
*	Nom auteur				: Kevin Allemann
*	Date de création        : 07.03.2023
*	Date de modification    : 07.03.2023
*/
/*
*  Description:
*  fonction pont diviseur
*
*  Remarque:
*  -
*/
#pragma warning(disable: 4996)
#include "PontResistifs.h"

//Librairie (standart)
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>


//Initialisation du pont diviseur
void InitInfoPontDiviseur(pontDiviseur* demoPontDiv)
{
	int valeurUserI, i, erreur;
	float valeurUserF;

	//Nbr de résistances
	printf("Combien de resistance? :\n");
	scanf("%d", &valeurUserI);

	//Test de la valeur si elle est comprise entre les limites de nombre de resistance
	demoPontDiv->nbr_resistance = (valeurUserI > MAX_NOMBRE_RESISTANCES) ? MAX_NOMBRE_RESISTANCES : valeurUserI;
	demoPontDiv->nbr_resistance = (valeurUserI < 1) ? 1 : valeurUserI;

	//Entree des valeurs des resitances
	for (i = 0; i < demoPontDiv->nbr_resistance; i++)
	{
		printf("Entrer la valeur de resistance %d (Max 10M / Min 0.1):\n", i + 1);

		while ((getchar() != '\n') && (getchar() != EOF));
		//Test de la valeur d'entree si elle est comprise dans les limites
		do
		{
			erreur = 0;
			scanf("%f", &valeurUserF);
			if ((valeurUserF > VALEUR_MAX_RESISTANCE) || (valeurUserF < VALEUR_MIN_RESISTANCE))
			{
				erreur = 1;
				printf("!!! Erreur de valeur !!!\n");
				while ((getchar() != '\n') && (getchar() != EOF));
			}
			else
				demoPontDiv->taille_resistance[i] = valeurUserF;

		} while (erreur == 1);

	}

	//Tension de circuit avec test de valeur comprise entre limite
	printf("Entrer la tension du circuit (Max %d / type entier):\n", TENSION_MAX_PONT_DIVISEUR);
	scanf("%d", &valeurUserI);
	if (valeurUserI > TENSION_MAX_PONT_DIVISEUR)
		valeurUserI = TENSION_MAX_PONT_DIVISEUR;
	else if (valeurUserI < 1)
		valeurUserI = 1;
	demoPontDiv->tension_ve = valeurUserI;

	while ((getchar() != '\n') && (getchar() != EOF));

}
//Calcul de la tension aux bornes des res
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv)
{
	float RTot = 0.0;
	int i;

	// Resistance total
	for (i = 0; i < demoPontDiv->nbr_resistance; i++)
	{
		RTot += demoPontDiv->taille_resistance[i];
	}

	// Tension de chaque resistance
	for (i = 0; i < demoPontDiv->nbr_resistance; i++)
	{
		demoPontDiv->valeur_tension_R[i] = demoPontDiv->tension_ve * demoPontDiv->taille_resistance[i] / RTot;
	}
}
//Fonction d'affichge
void AffichageTensionDiviseur(pontDiviseur demoPontDiv)
{
	int i;
	for (i = 0; i < demoPontDiv.nbr_resistance; i++)
	{
		printf("Tension sur la resistance %d : %.2e\n", i, demoPontDiv.valeur_tension_R[i]);
	}
}
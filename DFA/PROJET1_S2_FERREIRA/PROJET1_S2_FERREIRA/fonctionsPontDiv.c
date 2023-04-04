//Nom du projet			: fonction pont diviseur
//Nom du fichier		: fonctionsPontDiv.c
//Nom auteur			: Diogo Ferreira
//Date de création		: 07.03.2023
//Date de modification	: 04.04.2023 DF
/*
  Description:
  fonction qui permet d'initialiser les valeurs de résistance, calculer et afficher le résultat

  Remarque:
  nécessaire des librairie local PontResistifs.h pour les valeurs max et min 
  et le type de structure compatible pour les fonctions
*/

//--- librairie standart ---//
#include <stdio.h>                  // entrée - sortie

//-- librairie personnelle --// 
#include "PontResistifs.h"


//fonction pour initialiser une structure avec le nombre de résistance/valeur de résistance/tension alim
void InitInfoPontDiviseur(pontDiviseur *demoPontDiv)
{
	float valeurUserFloat;
	int valeurUserInt;
	unsigned int i;
	int Error = 0;
	//nombre de résistance
	printf("Entrer le nombre de resistance (Max %d / type entier):\n", MAXNBRRES);
	scanf_s("%d", &valeurUserInt);
	if (valeurUserInt > MAXNBRRES)
		valeurUserInt = MAXNBRRES;
	else if (valeurUserInt < 1)
		valeurUserInt = 1;
	demoPontDiv->NbrMaxRes = valeurUserInt;
	//insertion des valeurs de résistance
	for (i = 0; i < demoPontDiv->NbrMaxRes; i++)
	{
		printf("Entrer la valeur de resistance %d (Max 10M / Min 0.1):\n", i+1);
		do
		{
			Error = 0;
			scanf_s("%f", &valeurUserFloat);
			if ((valeurUserFloat > MAXRES) || (valeurUserFloat < MINRES))
			{
				Error = 1;
				printf("ERREUR: VALEUR INCORRECT\n");
				while ((getchar() != '\n') && (getchar() != EOF));
			}
			else
				demoPontDiv->TbResistor[i] = valeurUserFloat;
				
		} while (Error == 1);
	}
	//tension circuit
	printf("Entrer la tension du circuit (Max %d / type entier):\n", MAXVALIM);
	scanf_s("%d", &valeurUserInt);
	if (valeurUserInt > MAXVALIM)
		valeurUserInt = MAXVALIM;
	else if (valeurUserInt < 1)
		valeurUserInt = 1;
	demoPontDiv->VAlim = valeurUserInt;

	//fin de l'initialisation
	while ((getchar() != '\n') && (getchar() != EOF));
}

//fonction pour calculer les différente tension des résistances
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv) 
{
	float RTotal = 0;
	float Rdiv = 0;
	unsigned int i;
	//initialisation de la résitance max du circuit
	for (i = 0; i < demoPontDiv->NbrMaxRes; i++) 
	{
		RTotal += demoPontDiv->TbResistor[i];
		
	}
	Rdiv = RTotal;

	//algorithme pour les différentes tensions
	for (i = 0; i < demoPontDiv->NbrMaxRes; i++)
	{
		
		demoPontDiv->TbVResistor[i] = demoPontDiv->VAlim * (Rdiv / RTotal);
		Rdiv -= demoPontDiv->TbResistor[i];
	}

}

//fonction qui permet d'afficher les réstultats des tensions des résistance.
void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv)
{
	unsigned int i;
	//espace entre initialisation et les résultats
	printf("\n\n");
	//affichage de chaque résistance avec ses valeurs
	for (i = 0; i < demoPontDiv.NbrMaxRes; i++)
	{
		printf("R%d  Valeur:%f  Tension:%f\n", i+1, demoPontDiv.TbResistor[i], demoPontDiv.TbVResistor[i]);
	}
}
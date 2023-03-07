//Nom du projet			: fonction pont diviseur
//Nom du fichier		: fonctionsPontDiv.c
//Nom auteur			: Diogo Ferreira
//Date de création		: 07.03.2023
//Date de modification	: 07.03.2023 DF
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
void InitInfoPontDiviseur(struct pontDiviseur* demoPontDiv)
{
	float valeurUser;
	unsigned int i;
	int Error = 0;
	//nombre de résistance
	printf("Entrer le nombre de resistance (Max %d / type entier):\n", MAXNBRRES);
	scanf_s("%f", &valeurUser);
	if (valeurUser > MAXNBRRES)
		valeurUser = MAXNBRRES;
	if (valeurUser < 1)
		valeurUser = 1;
	demoPontDiv->NbrMaxRes = valeurUser;

	//insertion des valeurs de résistance
	for (i = 0; i < demoPontDiv->NbrMaxRes; i++)
	{
		printf("Entrer la valeur de resistance %d (Max 10M / Min 0.1):\n", i+1);
		do
		{
			Error = 0;
			scanf_s("%f", &valeurUser);
			if ((valeurUser > MAXRES) || (valeurUser < MINRES))
			{
				Error = 1;
				printf("ERREUR: VALEUR INCORRECT\n");
				while ((getchar() != '\n') && (getchar() != EOF));
			}
			else
				demoPontDiv->TbResistor[i] = valeurUser;
				
		} while (Error == 1);
		
	}

	//tension circuit
	printf("Entrer la tension du circuit (Max %d / type entier):\n", MAXVALIM);
	scanf_s("%f", &valeurUser);
	if (valeurUser > MAXVALIM)
		valeurUser = MAXVALIM;
	if (valeurUser < 1)
		valeurUser = 1;
	demoPontDiv->VAlim = valeurUser;

	//fin de l'initialisation
	while ((getchar() != '\n') && (getchar() != EOF));
}

//fonction pour calculer les différente tension des résistances
void CalculTensionPontDiviseur(struct pontDiviseur* demoPontDiv) 
{
	float RTotal = 0;
	float Rdiv = 0;
	int i;
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
void AffichageTensionPontDiviseur(struct pontDiviseur demoPontDiv)
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
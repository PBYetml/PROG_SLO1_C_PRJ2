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

#include "PontResistifs.h"

//Librairie (standart)
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>


//Initialisation du pont diviseur
void InitInfoPontDiviseur(int a) 
{
	pontDiviseur.nbr_resistance = a;
	if (a>nbr_max_resist)
	{
		pontDiviseur.nbr_resistance = 10;
	}
	else if (a<0)
	{
		pontDiviseur.nbr_resistance = 1;
	}

	int valresistanceUser;
	for (int i = 0; i < pontDiviseur.nbr_resistance; i++)
	{
		printf("Résistance %d:\n", i);
		scanf("%d", &valresistanceUser);

	}

}
//Calcul de la tension aux bornes des res
void CalculTensionPontDivisueur() 
{

}
//Fonction d'affichge
void AffichageTensionDivisueur() 
{

}
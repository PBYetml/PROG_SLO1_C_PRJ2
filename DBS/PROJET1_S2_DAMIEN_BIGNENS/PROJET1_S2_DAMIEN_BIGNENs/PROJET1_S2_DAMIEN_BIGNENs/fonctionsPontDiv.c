


//-- librairie (standart) --//
#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <stdint.h>
#include <math.h>

//-- libraire (perso) --// 
#include "PontResistifs.h"  

void InitInfoPontDiviseur(double* pt_demoPontDiv)
{
	char valeur;
	printf("\n veuillez inserer le nombre de resistance possible dans votre pont diviseur:");
	scanf_s("%c", &valeur);
	if (valeur > NB_MAX_resistance)
	{
		*pt_demoPontDiv = valeur; 
	}
	if (valeur <= 0)
	{

		valeur = 1; 
	}
	printf("\n veuillez inserer une valeur de tension");
	scanf_s("%c", &valeur);
	if (valeur > TENSION_MAX)
	{
		valeur = TENSION_MAX; 
	}
	if (valeur <= 1)
	{

		valeur = 1;
	}

	pt_demoPontDiv >> 1 = valeur; 
}

void CalculTensionPontDivisueur(struct str_ParamA* pt_ParamA)
{
	int valeurR2;
	int valeurR1;
	int V_pont;
	int valeur_optonue; 
	valeurR2  = pt_ParamA->com_resistance * pt_ParamA->tb_valeur;
	valeurR1 = pt_ParamA->com_resistance  *pt_ParamA->tb_valeur;
	valeur_optonue = V_pont * (valeurR2 / (valeurR2 + valeurR1));

}

void AffichageTensionPontDivisueur(int demoPontDiv)
{
	printf("\n la valeur entre chaque resistance %f3 ", demoPontDiv);


}
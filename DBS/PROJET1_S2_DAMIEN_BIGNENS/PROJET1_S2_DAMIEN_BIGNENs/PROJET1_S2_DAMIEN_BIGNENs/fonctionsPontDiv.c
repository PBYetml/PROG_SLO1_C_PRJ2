


//-- librairie (standart) --//
#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <stdint.h>
#include <math.h>

//-- libraire (perso) --// 
#include "PontResistifs.h"  

void InitInfoPontDiviseur(str_pontDiviseur* pt_demoPontDiv)
{
	int valeur;
	printf("\n veuillez inserer le nombre de resistance possible dans votre pont diviseur:");
	scanf_s("%d", &valeur);
	while ((getchar() != '\n') && (getchar() != EOF));
	if (valeur > NB_MAX_resistance)
	{
		valeur = NB_MAX_resistance;
	}
	else if (valeur <= 0)
	{
		valeur = 1;
	}
	pt_demoPontDiv -> com_resistance = valeur;
	int i;
	for (i = 0; i < valeur; i++)
	{
		printf("Veuillez inserer une valeur de resistance allant de 0.1 a 10Mohm pour R%d:", i + 1);
		scanf_s("%lf", &pt_demoPontDiv->tb_valeur_R[i]); 
		while ((getchar() != '\n') && (getchar() != EOF));
		if (pt_demoPontDiv->tb_valeur_R[i] < VAL_MIN_resistance || pt_demoPontDiv->tb_valeur_R[i] > VAL_MAX_resistance)
		{
			printf("!!! Erreur de valeur !!! \n");
			i--;				 
		}
	}

	printf("Veuillez inserer la tension d'alimentation du montage :");
	scanf_s("%d", &valeur);
	while ((getchar() != '\n') && (getchar() != EOF));

	if (valeur > TENSION_MAX)
	{
		valeur = TENSION_MAX;
	}
	else if (valeur < 1)
	{
		valeur = 1;
	}
	pt_demoPontDiv->alime = valeur; //Stock la valeur dans la variable tensionAlimVe
}



void CalculTensionPontDivisueur(str_pontDiviseur* pt_demoPontDiv)
{
	double sommeResistances = 0;  
	double EnretResistances = 0;
	int i;
	for (i = 0; i < pt_demoPontDiv->com_resistance; i++)
	{
		sommeResistances = pt_demoPontDiv->tb_valeur_R[i] + sommeResistances;
	}

	int e;  //Index
	double tensionResistance_n; //variable pour VpontRu
	for (e = 0; e < pt_demoPontDiv->com_resistance; e++)
	{
		tensionResistance_n = pt_demoPontDiv->alime * (pt_demoPontDiv->tb_valeur_R[e] / sommeResistances);		//tensionResistanceU = VpontRu
		pt_demoPontDiv->tb_bornes_resistance[e] = tensionResistance_n;
	}
	EnretResistances = sommeResistances ; 
	for (e = 0; e < pt_demoPontDiv->com_resistance; e++)
	{
		EnretResistances -= pt_demoPontDiv->tb_valeur_R[e];
		pt_demoPontDiv->tb_v_Entre_Resistances[e] = pt_demoPontDiv->alime * (EnretResistances / sommeResistances);

	}


}


void AffichageTensionPontDivisueur(str_pontDiviseur pt_demoPontDiv)
{
	int i;
	for (i = 0; i < pt_demoPontDiv.com_resistance; i++)
	{
		printf("Tension sur la resistance R%d vaut %.2e[V]\n", i + 1, pt_demoPontDiv.tb_bornes_resistance[i]);
	}

	for (i = 0; i < pt_demoPontDiv.com_resistance; i++)
	{
		printf("Tension sur la tension VS%d vaut %.2e[V]\n", ((pt_demoPontDiv.com_resistance - 1) - i), pt_demoPontDiv.tb_v_Entre_Resistances[i]);
	}

}
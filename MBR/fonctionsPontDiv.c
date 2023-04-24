//--- librairie standart ---//
#include <stdio.h>                  // entrée - sortie

//-- librairie personnelle --// 
#include "PontResistifs.h"

//déclarations des fonctions
//type_de_retour nom_de_la_fonction(type_argument_1 arg1, type_argument_2 arg2, ...);



void InitInfoPontDiviseur(pontDiviseur* demoPontDiv)
{
	unsigned char i = 0;

	printf("Veuillez insérer le nombre de résistances possibles dans votre pont diviseur :\n");
	scanf("%d", &demoPontDiv->nbDeResistance);

	if (demoPontDiv->nbDeResistance > nbMaxResistance)
	{
		demoPontDiv->nbDeResistance = nbMaxResistance;
		printf("La valeur entrée est trop grande. Votre nombre de résistances est %d\n", nbMaxResistance);
	}

	else if (demoPontDiv->nbDeResistance <= 0)
	{
		demoPontDiv->nbDeResistance = 1;
		printf("La valeur entrée sur le clavier est trop petite. Le nombre de résistances est de 1\n");
	}

	while ((getchar() != '\n') && (getchar() != EOF));

	//si ne marche pas remplacer par une while pour rester dedans

	while(i < demoPontDiv->nbDeResistance)
	{
		printf("Veuillez entrer la valeur de la résistance %d\n", i);
		scanf("%f", &demoPontDiv->valeurResistance[i]);

		if ((demoPontDiv->valeurResistance[i] > valMaxResistance) || (demoPontDiv->valeurResistance[i] < valMinResistance))
		{
			printf("La valeur entrée n'est pas dans les limites (maximum %f et minimum %f)\n", valMinResistance, valMaxResistance);
		}
		else
		{
			i++;
		}
	}

	while ((getchar() != '\n') && (getchar() != EOF));

	printf("Veuillez entrer la tension d'alimentation du pont\n");
	scanf("%d", &demoPontDiv->tensionAlimVe);

	if (demoPontDiv->tensionAlimVe > tensionMax)
	{
		demoPontDiv->tensionAlimVe = tensionMax;
		printf("La valeur entree est plus grande que la limite. La tension d'alimentation est de %dV\n", tensionMax);
	}
	else if (demoPontDiv->tensionAlimVe < 1)
	{
		demoPontDiv->tensionAlimVe = 1;
		printf("La valeur entree est plus petite que la limite inférieure. La tension d'alimentation est de %d V\n", demoPontDiv->tensionAlimVe);
	}

	while ((getchar() != '\n') && (getchar() != EOF));
}



void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv)
{
	unsigned char i = 0;
	float valResistanceTotale = 0;

	// Calcul de la résistance totale
	for (i = 0; i < demoPontDiv->nbDeResistance; i++)
	{
		valResistanceTotale = valResistanceTotale + demoPontDiv->valeurResistance[i];
	}

	// Calcul de la tension sur chaque résistance
	for (i = 0; i < demoPontDiv->nbDeResistance; i++)
	{
		demoPontDiv->valeurTension[i] = demoPontDiv->tensionAlimVe * demoPontDiv->valeurResistance[i] / valResistanceTotale;
	}
}



void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv)
{
	//fonction affichant la tension se trouvant sur chaque résistance avec 3 chiffres significatif

	unsigned char i = 0;

	for (i = 0; i < demoPontDiv.nbDeResistance; i++)
	{
		printf("La tension sur la résistance %d: %.2ev \n", i, demoPontDiv.valeurTension[i]);
	}
}
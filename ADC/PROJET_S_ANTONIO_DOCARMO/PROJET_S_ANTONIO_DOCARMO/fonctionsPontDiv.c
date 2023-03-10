
//INCLUDES

#include "PontsResistifs.h"

#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <stdint.h>

//Fonction

void InitInfoPontDiviseur(int demoPontDiv *pontDiviseur) {
	int valeurUser;
	int valRes;
	int valTension;

	printf("Veuillez ineserer le nombre de resistances possible dans votre pont diviseur: ");
	scanf("%d", &valeurUser);

	if (valeurUser > MAX_RES_PONT)
	{
		valeurUser = MAX_RES_PONT;
	}

	else if (valeurUser <= 0)
	{
		valeurUser = 1;
	}

	pontDiviseur->nbDeRes = valeurUser;

	for (int i = 0; i <= valeurUser; i++)
	{
		printf("\nVeuillez inserer une valeur de resistance allant de 0.5 a 10Mohm pour R%d", &i);
		scanf("%d", &valRes);

		if ((valRes > VAL_MAX_RES) || (valRes < VAL_MIN_RES))
		{
			printf("\n!!! Erreur de valeur !!!");
			i--;
		}
		else 
		{
			pontDiviseur->tb_valRes[i] = valRes;
		}
	}

	for (int i = 0; i <= valeurUser; i++)
	{
		printf("Tension sur la resistance R%d", &i);
		scanf("%d", &valTension);

		if (valTension > U_MAX_PONT)
		{
			valTension = U_MAX_PONT;
		}

		else if (valTension < 1)
		{
			valTension = 1;
		}

		pontDiviseur->tb_uRes[i] = valTension;
	}

	while ((getchar() != '\n') && (getchar() != EOF));
}

void CalculTensionPontDiviseur(int demoPontDiv *pontDiviseur) {

	int tensionR;
	int R2;

	for(int i = 0; i < pontDiviseur->nbDeRes; i++)
	{
		R2 = i + 1;

		tensionR = pontDiviseur->uAlimPont * (pontDiviseur->tb_valRes[R2] / (pontDiviseur->tb_valRes[i] + pontDiviseur->tb_valRes[R2]));

		tb_uRes[i] = tensionR;

	}
	
}

void AffichageTensionPontDiviseur(demoPontDiv) {

	for (int i = 0; i < nbDeRes; i++)
	{
		printf("\nTension sur la resistance R%d : %3d", &i + 1, &pontDiviseur->tb_uRes);
	}

}
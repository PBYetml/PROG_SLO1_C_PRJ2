//--- librairie standart ---//
#include <stdio.h>                  // entr�e - sortie
#include <stdlib.h>                 // pour les fonctions syst�mes
#include <stdint.h>

//-- librairie personnelle --// 
#include "PontResistifs.h"

//...................................Fonctions

void InitInofoPontDiviseur(PontDiviseur* demoPonDiv)
{
	// D�claration de variables locales
	int valeur = 0;
	float tempValRes;

	printf("Veuillez inserer le nombre de r�sistances possibles dans votre pont diviseur :\n");
	scanf("%d", &demoPonDiv->nbResComposantPonRes);

	// V�rification de la limite sup�rieure du nombre de r�sistances
	if (demoPonDiv->nbResComposantPonRes > nombreMaxDeResPontDiv)
	{
		demoPonDiv->nbResComposantPonRes = nombreMaxDeResPontDiv;
		printf("La valeur entree est trop grande. Le nombre de r�sistances est limite � %d\n", nombreMaxDeResPontDiv);
	}
	// V�rification de la limite inf�rieure du nombre de r�sistances
	else if (demoPonDiv->nbResComposantPonRes <= 0)
	{
		demoPonDiv->nbResComposantPonRes = 1;
		printf("La valeur entree est trop petite. Le nombre de r�sistances est fixe � 1\n");
	}

	// Vidage du buffer d'entr�e
	while ((getchar() != '\n') && (getchar() != EOF));

	while (valeur < demoPonDiv->nbResComposantPonRes)
	{
		printf("Veuillez entrer la valeur de la r�sistance %d :\n", valeur + 1);
		scanf("%f", &demoPonDiv->tbValRes[valeur]);

		// V�rification des limites des valeurs de r�sistances
		if ((demoPonDiv->tbValRes[valeur] > valeurMaxRes) || (demoPonDiv->tbValRes[valeur] < valeurMinRes))
		{
			printf("La valeur entree n'est pas dans les limites (maximum %f et minimum %f)\n", valeurMaxRes, valeurMinRes);
		}
		else
		{
			//demoPonDiv->tbValRes[valeur] = tempValRes;
			valeur++;
		}

		// Vidage du buffer d'entr�e
		while ((getchar() != '\n') && (getchar() != EOF));
	}

	printf("Veuillez entrer la tension d'alimentation du pont :\n");
	scanf("%d", &demoPonDiv->tensionAlimPontRes);

	// V�rification des limites de la tension d'alimentation
	if (demoPonDiv->tensionAlimPontRes > tensionMaxPontDiv)
	{
		demoPonDiv->tensionAlimPontRes = tensionMaxPontDiv;
		printf("La valeur entree est plus grande que la limite. La tension d'alimentation est fix�e � %dV\n", tensionMaxPontDiv);
	}
	else if (demoPonDiv->tensionAlimPontRes < 1)
	{
		demoPonDiv->tensionAlimPontRes = 1;
		printf("La valeur entree est plus petite que la limite inf�rieure. La tension d'alimentation est fix�e � %dV\n", 1);
	}

	// Vidage du buffer d'entr�e
	while ((getchar() != '\n') && (getchar() != EOF));
}

void CalculTensionPontDiviseur(PontDiviseur* demoPonDiv)
{
	// D�claration des variables locales
	float restotal = 0;
	int i;
	float ValTensionResTot = 0;

	// Calcul de la r�sistance totale
	for (i = 0; i < demoPonDiv->nbResComposantPonRes; i++)
	{
		restotal = restotal + demoPonDiv->tbValRes[i];
	}
	
	// Calcul de la tension sur chaque r�sistance
	for (i = 0; i < demoPonDiv->nbResComposantPonRes; i++)
	{
		demoPonDiv->tbValTensionRes[i] = (demoPonDiv->tensionAlimPontRes * demoPonDiv->tbValRes[i]) / restotal;
	}
	for (i = 0; i < demoPonDiv->nbResComposantPonRes; i++)
	{
		ValTensionResTot = ValTensionResTot + demoPonDiv->tbValTensionRes[i];
		demoPonDiv->ValTensionEntreRes[i] = demoPonDiv->tensionAlimPontRes - ValTensionResTot;
	}

}

void affichageTensionPontDiviseur(PontDiviseur demoPonDiv)
{
	// D�claration des variables locales
	int i = 0;

	// Affichage de la chute de tension sur chaque r�sistance
	for (i = 0; i < demoPonDiv.nbResComposantPonRes; i++)
	{
		printf("Chute de tension sur la resistance %d: %.2eV\n", i +1, demoPonDiv.tbValTensionRes[i]);
	}
	// Affichage de la chute de tension entre chaque r�sistance
	for (i = 0; i < demoPonDiv.nbResComposantPonRes; i++)
	{
		printf("Valeur de la tension au point VF %d: %.2eV\n", i + 1, demoPonDiv.ValTensionEntreRes[i]);
	}
}


/*
 -------------------------------------------------
 -- Projet : PROJET1_S2_LEO_MENDES				--
 -- Fichier : fonctionsPontDiv.c				--
 -- Versions : 1.0								--
 -- Date : 07.03.23								--
 -- Autheur : Léo Mendes						--
 -------------------------------------------------
*/
#include <stdio.h>
#include <stdint.h>
//Demande combien de RES et test la réponce
void InitInfoPontDiviseur(int * pt_DemoPontdiviseur) {
	char valUser = 0;
	int i = 0;
	float valRes = 0;
	int valTension = 0;
	do
	{
		printf("\n Combien de résistance ce trouve dans le ponts ?");
		scanf("%c", &valUser);
		if (valUser > pt_DemoPontdiviseur) {
			valUser = 10;
		}
		else if (valUser <= 0) 
		{
			valUser = 1; 
		}
	} while ((getchar() != '\n') && (getchar() != EOF));
	
	do
	{
		for (i = 0; i < valUser; i++)
		{
			printf("\n Quelle valeur est la resistance n %d ?", i);
			scanf("%c", &valRes);
			if ((valRes < maxRes) && (valRes > minRes)) 
			{
				printf("Valeur Ok");
				// return Valeur dans struct
			}
			else 
			{
				printf("ERREUR DE VALEUR");
				i--;
			}
		}
		i = 0;
	} while ((getchar() != '\n') && (getchar() != EOF));

	do
	{
		printf("\n Quelle est la tension du au borne du pont ?", i);
		scanf("%c", &valTension);
		if (valTension < maxTension) 
		{
			valTension = maxTension;
		}
		else if (valTension < 1) 
		{
			valTension = 1; 
		}
		// return Valeur dans struct
	} while ((getchar() != '\n') && (getchar() != EOF));

};

void CalculTensionPontDiviseur(int* pt_DemoPontdiviseur) {


};

void AffichageTensionPontDiviseur(int* pt_DemoPontdiviseur) {
	int i = 0;
	for (i = 0; i < /*ValRes*/ ; i++)
	{
		printf("\n Tension sur la resistance R1 vaut %e ", /* tab_ValTension[i]*/);
	}
	i = 0;
};
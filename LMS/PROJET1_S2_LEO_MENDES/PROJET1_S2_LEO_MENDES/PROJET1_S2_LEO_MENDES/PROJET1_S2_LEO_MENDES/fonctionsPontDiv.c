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
#include "PontResistifs.h"

void InitInfoPontDiviseur(pontDiviseur* demoPontDiv) {
	int valUser = 0;
	int i = 0;
	float valRes = 0;
	int valTension = 0;

	do {
		printf("Veuillez inserer le nombre de resistance possible dans votre pont diviseur : ");
		if (scanf("%d", &valUser) != 1)
		{};
		if (valUser > nbrMaxRes) {
			valUser = nbrMaxRes;
		}
		else if (valUser <= 0) {
			valUser = DEFAULTMINRES;
		}
		demoPontDiv->nbrRes = valUser;
	} while ((getchar() != '\n') && (getchar() != EOF));

	do {
		for (i = 0; i < demoPontDiv->nbrRes; i++) {
			printf("\nVeuillez inserer une valeur de resistance allant de 0.5 a 10 Mohm pour R%d: ", i + 1);
			if (scanf("%f", &valRes) != 1) 
			{};
			if ((valRes <= maxRes) && (valRes >= minRes)) {
				printf("Valeur Ok :)");
				demoPontDiv->tab_ValRes[i] = valRes;
			}
			else {
				printf("!!! ERREUR DE VALEUR !!!");
				i--;
			}
		}
	} while ((getchar() != '\n') && (getchar() != EOF));

	do {
		printf("\nVeuillez insererl la tension d'alimentation du montage : ");
		if (scanf("%d", &valTension) != 1)
		{};
		if (valTension > maxTension) {
			valTension = maxTension;
		}
		else if (valTension < 1) {
			valTension = DEFAULTVMIN;
		}
		else {}
		demoPontDiv->vAlim = valTension;
	} while ((getchar() != '\n') && (getchar() != EOF));
}

void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv) {
	float rTot = 0;
	float tensionSuivante = 0;

	// Calcul de la résistance totale
	for (int i = 0; i < demoPontDiv->nbrRes; i++) {
		rTot += demoPontDiv->tab_ValRes[i];
	}

	// Calcul du facteur de correction
	float correction = demoPontDiv->vAlim / rTot;

	// Calcul de la tension du potentieé chaque résistance
	for (int i = demoPontDiv->nbrRes - 1; i >= 0; i--) {
		tensionSuivante = tensionSuivante + demoPontDiv->tab_ValRes[i] * correction;
		demoPontDiv->tab_ValTension[i] = tensionSuivante;
	}
}

void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv) {
	int i;
	for (i = 0; i < demoPontDiv.nbrRes; i++) {
		printf("\nTension sur la resistance R%d vaut : %.3e", i+1 , demoPontDiv.tab_ValTension[i]);
	}
}
//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 1 Semestre2 Pont resistif 
// Nom du fichier 		: fonctionsPontDiv.h
// Date de cr�ation 	: 07.03.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR (J�r�my Affolter)
//
// Description          : 
//
//
// Remarques			: voir donnee de l'�preuve            
//----------------------------------------------------------------------------------//

// Librairie perso
#include "PontResistifs.h"
#include <stdio.h>                  // entr�e - sortie

//---
// Nom fonction : InitInfoPontDiviseur
// Param�tres entr�e / sortie / inout : -/-/demoPontDiv
// Description : Initialise une structure pontDiviseur
// Remarque : -
// Auteur : JAR
// Date modification : 07.03.2023
//---
void InitInfoPontDiviseur(pontDiviseur* demoPontDiv)
{
	// Variables locales
	char i = 0;

	// Affichage Fonction Init
	printf("Vous Etes dans la fonction d'initialisation de pont diviseur\n\n");
	// Afficher une demande du nombre de r�sistances
	printf("Entrer le nombre de resistances de votre pont\n");
	// R�cup�ration du nombres de r�sistances
	scanf("%d", &demoPontDiv->nbRes);
	// Test que le nombres de r�sistances entr�es ne soit pas plus grand ou plus petit que les limites
	if (demoPontDiv->nbRes > NBMAXRES)
	{
		demoPontDiv->nbRes = NBMAXRES;
		printf("La valeur entree est trop grande. Votre nombre de resistances est %d\n", NBMAXRES);
	}
	else if (demoPontDiv->nbRes <= 0)
	{
		demoPontDiv->nbRes = 1;
		printf("La valeur entree est trop petit. Votre nombre de resistances est 1\n");
	}

	//-- s'assure que le buffer est vider pour refaire une nouvelle demande --//
	while ((getchar() != '\n') && (getchar() != EOF));

	i = 0;
	do
	{
		// Afficher une demande de la valeur de la r�sistance
		printf("Entrer la valeur de la resistance %d\n", i);
		// R�cup�ration de la valeur de la r�sistance
		scanf("%f", &demoPontDiv->tb_ValRes[i]);
		// Test que la valeur soit dans les limites d�finies si non recommencer
		if ((demoPontDiv->tb_ValRes[i] > RMAX) || (demoPontDiv->tb_ValRes[i] < RMIN))
		{
			printf("La valeur ne rentre pas dans les limites(maximum %f et minimum %f)\n", RMAX, RMIN);
		}
		else
		{
			i++;
		}
	} while (i < demoPontDiv->nbRes);

	//-- s'assure que le buffer est vider pour refaire une nouvelle demande --//
	while ((getchar() != '\n') && (getchar() != EOF));

	// Afficher	une demande de Vcc du pont
	printf("Entrer la tension de votre pont\n");
	// R�cup�ration de la tension du pont
	scanf("%d", &demoPontDiv->vccPont);
	// Test que la tension du pont ne soit pas plus grand ou plus petit que les limites
	if (demoPontDiv->vccPont > VCCMAX)
	{
		demoPontDiv->vccPont = VCCMAX;
		printf("La valeur entree est trop grande. Votre tension de pont est %dV\n", VCCMAX);
	}
	else if (demoPontDiv->vccPont < 1)
	{
		demoPontDiv->vccPont = 1;
		printf("La valeur entree est trop petit. Votre tension de pont est 1V\n");
	}

	//-- s'assure que le buffer est vider pour refaire une nouvelle demande --//
	while ((getchar() != '\n') && (getchar() != EOF));
}


//---
// Nom fonction : CalculTensionPontDiviseur
// Param�tres entr�e / sortie / inout : -/-/demoPontDiv
// Description : Calcul la tension sur chaque r�sistance
// Remarque : -
// Auteur : JAR
// Date modification : 07.03.2023
//---
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv)
{
	// Variables locales
	float rTot = 0;
	float rPoint = 0;
	char i = 0;

	for (i = 0; i < demoPontDiv->nbRes; i++)
	{
		rTot = rTot + demoPontDiv->tb_ValRes[i];
	}
	for (i = 0; i < demoPontDiv->nbRes; i++)
	{
		rPoint += demoPontDiv->tb_ValRes[i];
		demoPontDiv->tb_URes[i] = demoPontDiv->vccPont * rPoint / rTot;
	}
}


//---
// Nom fonction :AffichageTensionPontDiviseur
// Param�tres entr�e / sortie / inout : demoPontDiv/-/-
// Description : Affiche la tension sur chaque r�sistance
// Remarque : -
// Auteur : JAR
// Date modification : 07.03.2023
//---
void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv)
{
	// Variables locales
	char i = 0;
	float uPass = 0;

	for (i = 0; i < demoPontDiv.nbRes; i++)
	{
		printf("Tension sur la resistance %d: %.2eV\n", i, demoPontDiv.tb_URes[i] - uPass);
		uPass = demoPontDiv.tb_URes[i];
	}
}
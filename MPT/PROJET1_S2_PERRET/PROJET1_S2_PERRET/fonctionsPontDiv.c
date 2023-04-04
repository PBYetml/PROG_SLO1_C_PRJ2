//-------------------------------------------
// Auteur: Mélissa Perret
// Date de création: 07.03.2023
// Description: la fonction demande le nombre de résistances que compose le pont 
// Entrées: pointeur de type struct 
// Sorties: void
//-------------------------------------------

#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include "PontResistifs.h"			// pour le struct et les définitions



void InitInfoPontDiviseur(str_pontDiviseur* pt_demoPontDiv)
{
	int valeurUtilisateur; 
	printf("Veuillez inserer le nombre de resistances possible dans votre pont diviseur :");
	scanf_s("%d", &valeurUtilisateur);
	while ((getchar() != '\n') && (getchar() != EOF));

	if (valeurUtilisateur > NB_MAX_RESISTANCES)
	{
		printf("la valeur minimum est de %d resistance \n", NB_MAX_RESISTANCES);
		valeurUtilisateur = NB_MAX_RESISTANCES;
	}
	else if (valeurUtilisateur <= 0)
	{
		printf("la valeur minimum est de 1 resistance \n");
		valeurUtilisateur = 1; 
	}
	pt_demoPontDiv->nbResistances = valeurUtilisateur;  //Stock la valeur de valeurUtilisateur dans la struc dans la variable nbResistances

	int indexResistance;   //variable pour la boucle for
	for (indexResistance = 0; indexResistance < valeurUtilisateur; indexResistance++)
	{
		printf("Veuillez inserer une valeur de resistance allant de %1.1lf a %.0lfMohm pour R%d:", VALEUR_MIN_RESISTANCE, VALEUR_MAX_RESISTANCE / 10e6, indexResistance + 1);
		scanf_s("%lf", &pt_demoPontDiv->tb_valResistances[indexResistance]); // modifie les valeurs du tableau valReistance à la première itération ce sera la case0, la 2ème case1, etc..
		//-- s'assure que le buffer est vidé pour refaire une nouvelle demande --//
		while ((getchar() != '\n') && (getchar() != EOF));

		if (pt_demoPontDiv->tb_valResistances[indexResistance] < VALEUR_MIN_RESISTANCE || pt_demoPontDiv->tb_valResistances[indexResistance] > VALEUR_MAX_RESISTANCE) 
		{
			printf("!!! Erreur de valeur !!! \n");
			indexResistance--;				 //retourne dans la boucle for avec avec la valeur avant le message d'erreur, répètera la même itération de la boucle
		}
	}

	printf("Veuillez inserer la tension d'alimentation du montage :");
	scanf_s("%d", &valeurUtilisateur);
	//-- s'assure que le buffer est vidé pour refaire une nouvelle demande --//
	while ((getchar() != '\n') && (getchar() != EOF));

	if (valeurUtilisateur > TENSION_MAX_PONTDIV)
	{
		valeurUtilisateur = TENSION_MAX_PONTDIV;
	}
	else if (valeurUtilisateur < 1)
	{
		valeurUtilisateur = 1;
	}
	pt_demoPontDiv->tensionAlimVe = valeurUtilisateur; //Stock la valeur dans la variable tensionAlimVe
}

void CalculTensionPontDiviseur(str_pontDiviseur* pt_demoPontDiv)
{
	double sommeResistances = 0;   //correspond à mon diviseur  
	int indexResistances;
	for (indexResistances = 0; indexResistances < pt_demoPontDiv->nbResistances; indexResistances++)
	{
		sommeResistances = pt_demoPontDiv->tb_valResistances[indexResistances] + sommeResistances;
	}

	int u;  //Index
	double tensionResistanceU; //variable pour VpontRu
	for (u = 0; u < pt_demoPontDiv->nbResistances; u++)
	{
		tensionResistanceU = pt_demoPontDiv->tensionAlimVe * (pt_demoPontDiv->tb_valResistances[u] / sommeResistances);		//tensionResistanceU = VpontRu
		pt_demoPontDiv->tb_tensionAuBornes[u] = tensionResistanceU;
	}
}

void AffichageTensionPontDiviseur(str_pontDiviseur demoPontDiv)
{
	int indexResistance;
	for (indexResistance = 0; indexResistance < demoPontDiv.nbResistances; indexResistance++)
	{
		printf("Tension sur la resistance R%d vaut %1.3lf[V]\n", indexResistance + 1, demoPontDiv.tb_tensionAuBornes[indexResistance]);
	}
}


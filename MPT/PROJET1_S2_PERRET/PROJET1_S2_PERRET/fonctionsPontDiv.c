//-------------------------------------------
// Auteur: Mélissa Perret
// Date de création: 07.03.2023
// Description: la fonction demande le nombre de résistances que compose le pont 
// Entrées: pointeur de type struct 
// Sorties: void
//-------------------------------------------

#include <stdio.h>                  // entrée - sortie
#include "PontResistifs.h"			// pour le struct et les définitions



void InitInfoPontDiviseur(str_pontDiviseur* pt_demoPontDiv)
{
	int retourScanF = 0;
	int valeurUtilisateur;

	do
	{
		printf("Veuillez inserer le nombre de resistances possible dans votre pont diviseur : ");
		retourScanF = scanf_s("%d", &valeurUtilisateur);
		while ((getchar() != '\n') && (getchar() != EOF));
		if (retourScanF == 0)
		{
			printf("!!! ERREUR !!! \n");
		}
	} while (retourScanF == 0);

	if (valeurUtilisateur > NB_MAX_RESISTANCES)
	{
		printf("la valeur minimum est de %d resistance, le nombre de resistance va etre ajuste a %d\n\n", NB_MAX_RESISTANCES, NB_MAX_RESISTANCES);
		valeurUtilisateur = NB_MAX_RESISTANCES;
	}
	else if (valeurUtilisateur <= 0)
	{
		printf("la valeur minimum est de 1 resistance, le nombre de resistance va etre ajuste a 1\n\n");
		valeurUtilisateur = 1;
	}
	pt_demoPontDiv->nbResistances = valeurUtilisateur;  //Stock la valeur de valeurUtilisateur dans la struc dans la variable nbResistances

	int indexResistance;   //variable pour la boucle for
	for (indexResistance = 0; indexResistance < valeurUtilisateur; indexResistance++)
	{
		printf("Veuillez inserer une valeur de resistance allant de %1.1lf a %.0lfMohm pour R%d: ", VALEUR_MIN_RESISTANCE, VALEUR_MAX_RESISTANCE / 10e6, indexResistance + 1);
		retourScanF = scanf_s("%lf", &pt_demoPontDiv->tb_valResistances[indexResistance]); // modifie les valeurs du tableau valReistance à la première itération ce sera la case0, la 2ème case1, etc..
		//-- s'assure que le buffer est vidé pour refaire une nouvelle demande --//


		while ((getchar() != '\n') && (getchar() != EOF));

		if (retourScanF == 0 || pt_demoPontDiv->tb_valResistances[indexResistance] < VALEUR_MIN_RESISTANCE || pt_demoPontDiv->tb_valResistances[indexResistance] > VALEUR_MAX_RESISTANCE)
		{
			printf("!!! Erreur de valeur !!! \n");
			indexResistance--;				 //retourne dans la boucle for avec avec la valeur avant le message d'erreur, répètera la même itération de la boucle
		}
	}
	printf("\n");

	do
	{
		printf("Veuillez inserer la tension d'alimentation du montage : ");
		retourScanF = scanf_s("%d", &valeurUtilisateur);
		while ((getchar() != '\n') && (getchar() != EOF));
		if (retourScanF == 0)
		{
			printf("!!! ERREUR !!! \n");
		}
	} while (retourScanF == 0);
	printf("\n");

	if (valeurUtilisateur > TENSION_MAX_PONTDIV)
	{
		printf("la valeur maximum de tension autorisee est de %d[V], la tension va etre ajustee a %d\n\n", TENSION_MAX_PONTDIV, TENSION_MAX_PONTDIV);
		valeurUtilisateur = TENSION_MAX_PONTDIV;
	}
	else if (valeurUtilisateur < 1)
	{
		printf("la valeur minimum de tension autorisee est de %d[V], la tension va etre ajustee\n\n", TENSION_MAX_PONTDIV);
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
	double tensionBorneResistance; //variable pour VpontRu
	for (u = 0; u < pt_demoPontDiv->nbResistances; u++)
	{
		tensionBorneResistance = pt_demoPontDiv->tensionAlimVe * (pt_demoPontDiv->tb_valResistances[u] / sommeResistances);		//tensionResistanceU = VpontRu
		pt_demoPontDiv->tb_tensionAuBornes[u] = tensionBorneResistance;
	}

	int indexTension;
	double resistances = sommeResistances;
	for (indexTension = 0; indexTension < pt_demoPontDiv->nbResistances; indexTension++)
	{
		resistances -= pt_demoPontDiv->tb_valResistances[indexTension];		//la variable résistance correspond aux résistance qui seront au numérateur de la formule 
		pt_demoPontDiv->tb_tentionEntreResistances[indexTension] = pt_demoPontDiv->tensionAlimVe * (resistances / sommeResistances);   //Calcul du pont diviseur 
	}
}

void AffichageTensionPontDiviseur(str_pontDiviseur demoPontDiv)
{
	int indexResistance;
	int indexTensionVs;
	for (indexResistance = 0; indexResistance < demoPontDiv.nbResistances; indexResistance++)
	{
		printf("Tension sur la resistance R%d vaut %.2e[V]\n", indexResistance + 1, demoPontDiv.tb_tensionAuBornes[indexResistance]);
	}
	printf("\n");

	for (indexTensionVs = 0; indexTensionVs < demoPontDiv.nbResistances; indexTensionVs++)
	{
		if (((demoPontDiv.nbResistances - 1) - indexTensionVs) == 0)
		{
			printf("Tension sur la tension GND vaut %.2e[V]\n", demoPontDiv.tb_tentionEntreResistances[indexTensionVs]);
		}
		else
		{
			printf("Tension sur la tension VS%d vaut %.2e[V]\n", ((demoPontDiv.nbResistances - 1) - indexTensionVs), demoPontDiv.tb_tentionEntreResistances[indexTensionVs]);
		}
	}
}
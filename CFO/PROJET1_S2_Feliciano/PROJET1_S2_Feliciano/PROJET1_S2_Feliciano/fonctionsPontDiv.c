#include <stdio.h>                  // entrée - sortie
#include "PontResistifs.h"


//déclaration de fonction
void InitInfoPontDiviseur(pontDiviseur* demoPontDiv)     // fonction information pont diviseur
{
	// Déclaration de variable local
	unsigned char valeur = 0;

	printf("Veuillez inserer le nombre de resistance possible dans votre pont diviseur :\n");				//Demande d'inscrire le nombre de résistance dans le pont
	scanf("%d", &demoPontDiv->Nb_Res);

	if (demoPontDiv->Nb_Res > Nb_Max_Res)
	{
		demoPontDiv->Nb_Res = Nb_Max_Res;
		printf("La valeur entree est trop grande. Votre nombre de resistance est %d\n", Nb_Max_Res);		//Affichage du message que le nombre de résistance entree est trop grand
	}
	else if (demoPontDiv->Nb_Res <= 0)
	{
		demoPontDiv->Nb_Res = 1;
		printf("La valeur entree sur le clavier est trop petite. Le nombre de resistances est de 1\n");		//Affichage du message que le nombre de résistance entree est trop petit
	}

	//-- s'assure que le buffer est vider pour refaire une nouvelle demande --//
	while ((getchar() != '\n') && (getchar() != EOF));

	
	while (valeur < demoPontDiv->Nb_Res)									// Tant que la variable valeur est plus petite que Nb_Res
	{
		printf("Veuillez entrer la valeur de la resistance %d\n", valeur);  // demande la valeur de la résistance
		scanf("%f", &demoPontDiv->ValRes[valeur]);							// Je récupère la valeur de la résistance

		if ((demoPontDiv->ValRes[valeur] > ValRes_Max) || (demoPontDiv->ValRes[valeur] < ValRes_Min))		//Test si la valeur entree est plus grande que les limites
		{
			printf("La valeur entree n'est pas das les limites (maximum %f et minimum %f)\n", ValRes_Max, ValRes_Min);		//Affichage de prevention que la valeur entree n'est pas les limites
		}
		else
		{
			valeur++;
		}
	}
		//-- s'assure que le buffer est vider pour refaire une nouvelle demande --//
		while ((getchar() != '\n') && (getchar() != EOF));

		
		printf("Veuillez entrer la tension d'alimentation du pont\n");		//Demande de la tension d'alimentation
		scanf("%d", &demoPontDiv->Vin);										//Je récupère la valeur tapé au clavier

		if (demoPontDiv->Vin > U_Alim_Max)									//Verifie que la tension entrée est dans les limites
		{
			demoPontDiv->Vin = U_Alim_Max;									
			printf("La valeur tapee est plus grande que la limite. La tension d'alimentation est de %dV\n", U_Alim_Max);	//Affichage du message que la tension d'alimentation est trop grande
		}
		else if (demoPontDiv->Vin < 1)
		{
			demoPontDiv->Vin = 1;
			printf("La valeur tapee est plus petite que la limite inferieur. La tension d'alimentation est de %d V\n");		//Affichage du message que la tension d'alimentation est trop petite
		}

		//-- s'assure que le buffer est vider pour refaire une nouvelle demande --//
		while ((getchar() != '\n') && (getchar() != EOF));
	
}

void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv)
{
	//Déclaration des variables locales
	float res_total = 0;
	char i = 0;
	float Val_U_Res_tot = 0;

	for (i = 0; i < demoPontDiv->Nb_Res; i++)
	{
		res_total = res_total + demoPontDiv->ValRes[i];					//Calcul de la résistance totale
	}
	for (i = 0; i < demoPontDiv->Nb_Res; i++)
	{
		demoPontDiv->Val_U_Res[i] = demoPontDiv->Vin * demoPontDiv->ValRes[i] / res_total;		//Calcul de la tension sur chaque résistance
	}
	for (i = 0; i < demoPontDiv->Nb_Res; i++)													//Calcul de la tension entre les résistances
	{
		Val_U_Res_tot = Val_U_Res_tot + demoPontDiv->Val_U_Res[i];								//Addition de la chute de tension sur les résistances	
		demoPontDiv->Val_U_Entre_Res[i] = demoPontDiv->Vin - Val_U_Res_tot;
	}
}


void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv)
{
	//Déclaration des variables locales
	char i = 0;

	for (i = 0; i < demoPontDiv.Nb_Res; i++)
	{
		printf("Chute de tension sur la resistance %d: %.2eV\n", i, demoPontDiv.Val_U_Res[i]);		//Affichage de la chute de tension sur chaque résistance
	}

	for (i = 0; i < demoPontDiv.Nb_Res; i++)
	{
		printf("Valeur de la tension au point VF %d: %.2eV\n", i, demoPontDiv.Val_U_Entre_Res[i]);	//Affichage de la tension entre les résistances
	}


}
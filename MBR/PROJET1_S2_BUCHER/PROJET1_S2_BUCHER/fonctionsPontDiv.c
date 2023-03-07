//--- librairie standart ---//
#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <stdint.h>

//-- librairie personnelle --// 
#include "PontResistifs.h"

//déclarations des fonctions
//type_de_retour nom_de_la_fonction(type_argument_1 arg1, type_argument_2 arg2, ...);




float InitInfoPontDiviseur(float valUser, double valMaxResistance)
{
	float valUser = 0;
	int valeurMax = 0;
	float valeurTension = 0;
	float valeurResistance = 0;
	int i = 1;			//compteur pour le nb de résistance


	//partie pour insérer le nombre de résistance max
	printf("Veuillez insérer le nombre de résistance possible dans votre pont diviseur : ");
	scanf("%f", valUser);

	if (valUser > nbMaxResistance)
	{
		valeurMax = nbMaxResistance;
	}
	else if (valUser <= 0)
	{
		valeurMax = 1;
	}
	else
	{
		valeurMax = valUser;
	}

	//Partie pour insérer les valeurs de résistances
	for (i = 1; i <= 10; i++)
	{
		printf("Veuillez insérer une valeur de résistance allant de 0.1 à 10Mohm pour R% : ",i);
		scanf("%f", valUser);

		//mettre les différentes valeur dans une variable
		valeurResistance = valUser;
	}



	//Partie inserer la valeur de tension
	printf("Veuillez insérer la valeur de tension du montage: ");
	scanf("%f", valUser);

	if (valUser > tensionMax)
	{
		valeurTension = tensionMax;
	}

	else if (valUser < 1)
	{
		valeurTension = 1;
	}

	else
	{
		valeurTension = valUser;
	}
	//mise en mémoire des valeurs dans la structure pontDiviseur
	struct pontDiviseur pontDiviseur = { valeurMax, valeurResistance, valeurTension };

}



float CalculTensionPontDiviseur(struct pontDiviseur *pointeurTension)
{
	float VpontDiviseur = 0;

	//VpontDiviseur = pontDiviseur.valeurTension;
}



float AffichageTensionPontDiviseur()
{

	//fonction affichant la tension se trouvant au borne de chaque résistance sous format scientifique de 3 chiffres significatif

}
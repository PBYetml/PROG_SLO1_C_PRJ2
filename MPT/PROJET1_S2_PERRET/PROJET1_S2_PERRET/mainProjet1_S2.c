//-----------------------------------------------------------------------------------//
// Nom du projet 		: Calculator Pont Diviseur 
// Nom du fichier 		: mainTest1_s3.c
// Date de création 	: 16.02.2021
// Date de modification : 18.02.2021
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : programme principal utilisé pour le test n°3
//
// Remarques :            lien pour la table ASCII :
// 						  -> http://www.asciitable.com/
// 						  lien pour la saisie de clavier avec getc & getchar pour ne pas
//                        avoir des erreurs d'interprétation
// 						  -> http://fr.openclassrooms.com/informatique/cours/utiliser-les-bonnes-fonctions-d-entree
// 						  lien vers différents
// 						  -> http://fr.wikipedia.org/wiki/String.h
//						  lien vers la méthode abs 
//						  -> https://www.gladir.com/CODER/C/abs.htm
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <stdint.h>
#include "PontResistifs.h"			// pour le struct et les définitions

//-- librairie personnelle --// 



//-- déclaration de constantes --// 
#define PERRET			"PERRET"


//-- programme princiaple --// 
void main()
{
	//-- déclaration de variables --// 
	char choixUser = 0;

	//-- déclaration de structure --// 
	str_pontDiviseur str_structureValeurs;

	//-- boucle permettant de savoir si l'utilisateur veut continuer ou pas --// 
	do
	{
		//-- appel de fonction
		//-- insertion de valeur de résistance pour le pont divisueur de tension --//
		InitInfoPontDiviseur(&str_structureValeurs);

		//-- calcul de la tension sur chaque résistance du pont diviseur --// 
		CalculTensionPontDiviseur(&str_structureValeurs);

		//-- afficahge de la tension sur chaque pont diviseur --// 
		AffichageTensionPontDiviseur(str_structureValeurs);

		printf("\nVoulez-vous quitter le programme ? [o/n]");
		scanf_s("%c", &choixUser);

		//-- s'assure que le buffer est vider pour refaire une nouvelle demande --//
		while ((getchar() != '\n') && (getchar() != EOF));

	} while (!(choixUser == 'o' || choixUser == 'O'));


	//pause du programme//
	system("pause");
}
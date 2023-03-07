//-----------------------------------------------------------------------------------//
// Nom du projet 		: Calculator Pont Diviseur 
// Nom du fichier 		: mainProject1_s2.c
// Date de création 	: 07.03.2023
// Date de modification : 07.03.2023
//
// Auteur 				: Allemann Kevin
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
#pragma warning(disable: 4996)
//--- librairie standart ---//
#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <stdint.h>

//-- librairie personnelle --// 
#include "PontResistifs.h"


//-- déclaration de constantes --// 
#define VOTRE_NOM			"Allemann"


//-- programme princiaple --// 
void main()
{
	//-- déclaration de variables --// 
	char choixUser = 0; 

	//-- déclaration de structure --// 
	
	typedef pontDiviseur;

	//-- boucle permettant de savoir si l'utilisateur veut continuer ou pas --// 
	do
	{
		//-- appel de fonction
		int valeurUser;
		printf("Combien de resistance? :\n");
		scanf("%d", &valeurUser);
		InitInfoPontDiviseur(valeurUser);
		//-- insertion de valeur de résistance pour le pont divisueur de tension --//
		

		//-- calcul de la tension sur chaque résistance du pont diviseur --// 

		
		//-- afficahge de la tension sur chaque pont diviseur --// 


		printf("\nVoulez-vous quitter le programme ? [o/n]"); 
		scanf("%c", &choixUser); 

		//-- s'assure que le buffer est vider pour refaire une nouvelle demande --//
		while ((getchar() != '\n') && (getchar() != EOF));
		
	} while (!(choixUser == 'o' || choixUser == 'O')); 


	//pause du programme//
	system("pause");
}
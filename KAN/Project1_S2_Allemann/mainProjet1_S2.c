//-----------------------------------------------------------------------------------//
// Nom du projet 		: Calculator Pont Diviseur 
// Nom du fichier 		: mainProject1_s2.c
// Date de cr�ation 	: 07.03.2023
// Date de modification : 07.03.2023
//
// Auteur 				: Allemann Kevin
//
// Description          : programme principal utilis� pour le test n�3
//
// Remarques :            lien pour la table ASCII :
// 						  -> http://www.asciitable.com/
// 						  lien pour la saisie de clavier avec getc & getchar pour ne pas
//                        avoir des erreurs d'interpr�tation
// 						  -> http://fr.openclassrooms.com/informatique/cours/utiliser-les-bonnes-fonctions-d-entree
// 						  lien vers diff�rents
// 						  -> http://fr.wikipedia.org/wiki/String.h
//						  lien vers la m�thode abs 
//						  -> https://www.gladir.com/CODER/C/abs.htm
//----------------------------------------------------------------------------------//
#pragma warning(disable: 4996)
//--- librairie standart ---//
#include <stdio.h>                  // entr�e - sortie
#include <stdlib.h>                 // pour les fonctions syst�mes


//-- librairie personnelle --// 
#include "PontResistifs.h"


//-- d�claration de constantes --// 
#define VOTRE_NOM			"Allemann"


//-- programme princiaple --// 
void main()
{
	//-- d�claration de variables --// 
	char choixUser = 0; 
	
	//-- d�claration de structure --// 
	
	pontDiviseur demoPontDiv;

	//-- boucle permettant de savoir si l'utilisateur veut continuer ou pas --// 
	do
	{
		//-- appel de fonction
		//-- insertion de valeur de r�sistance pour le pont divisueur de tension --//
		InitInfoPontDiviseur(&demoPontDiv);

		//-- calcul de la tension sur chaque r�sistance du pont diviseur --// 
		CalculTensionPontDivisueur(&demoPontDiv);
		
		//-- afficahge de la tension sur chaque pont diviseur --// 
		AffichageTensionDivisueur(demoPontDiv);

		printf("\nVoulez-vous quitter le programme ? [o/n]"); 
		scanf("%c", &choixUser, 1); 

		//-- s'assure que le buffer est vider pour refaire une nouvelle demande --//
		while ((getchar() != '\n') && (getchar() != EOF));
		
	} while (!(choixUser == 'o' || choixUser == 'O')); 


	//pause du programme//
	system("pause");
}
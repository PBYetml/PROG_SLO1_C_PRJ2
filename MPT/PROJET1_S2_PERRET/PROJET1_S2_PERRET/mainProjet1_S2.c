//-----------------------------------------------------------------------------------//
// Nom du projet 		: Calculator Pont Diviseur 
// Nom du fichier 		: mainTest1_s3.c
// Date de cr�ation 	: 16.02.2021
// Date de modification : 18.02.2021
//
// Auteur 				: Philou (Ph. Bovey)
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

//--- librairie standart ---//
#include <stdio.h>                  // entr�e - sortie
#include <stdlib.h>                 // pour les fonctions syst�mes
#include <stdint.h>
#include "PontResistifs.h"			// pour le struct et les d�finitions

//-- librairie personnelle --// 



//-- d�claration de constantes --// 
#define PERRET			"PERRET"


//-- programme princiaple --// 
void main()
{
	//-- d�claration de variables --// 
	char choixUser = 0;

	//-- d�claration de structure --// 
	str_pontDiviseur str_structureValeurs;

	//-- boucle permettant de savoir si l'utilisateur veut continuer ou pas --// 
	do
	{
		//-- appel de fonction
		//-- insertion de valeur de r�sistance pour le pont divisueur de tension --//
		InitInfoPontDiviseur(&str_structureValeurs);

		//-- calcul de la tension sur chaque r�sistance du pont diviseur --// 
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
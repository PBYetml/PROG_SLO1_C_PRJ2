//-------------------------------------------
// Auteur: Mélissa Perret
// Date de création: 07.03.2023
// Description: la fonction demande le nombre de résistances que compose le pont 
// Entrées: pointeur de type struct 
// Sorties: void
//-------------------------------------------

#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <stdint.h>
#include "PontResistifs.h"			// pour le struct et les définitions



void InitInfoPontDiviseur(struct str_pontDiviseur* pt_demoPontDiv)
{
	if(pt_demoPontDiv > NB_MAX_RESISTANCES)
	{
		*pt_demoPontDiv = NB_MAX_RESISTANCES;
	}
	else if (pt_demoPontDiv <= 0)
	{
		pt_demoPontDiv = 1;
	}
}

void CalculTensionPontDiviseur(struct str_pontDiviseur* pt_demoPontDiv)
{
	if (pt_demoPontDiv > TENSION_MAX_PONTDIV)
	{
		pt_demoPontDiv = TENSION_MAX_PONTDIV;
	}
	else if (pt_demoPontDiv <= 1)
	{
		pt_demoPontDiv = 1;
	}
}

void AffichageTensionPontDiviseur(demoPontDiv)
{
	printf("La tension se trouvant aux bornes de chaque résistannce %f", demoPontDiv);
}



//Nom du projet			: Pont Résistif
//Nom du fichier		: PontResistifs.h
//Nom auteur			: Diogo Ferreira
//Date de création		: 07.03.2023
//Date de modification	: 07.03.2023 DF
/*
  Description:
  -

  Remarque:
  -
*/

#ifndef PONT_RESISTIFS_CALCUL
#define PONT_RESISTIFS_CALCUL

#define MAXNBRRES 10
#define MAXVALIM 30
#define MAXRES 10000000
#define MINRES 0.1

extern struct pontDiviseur
{
	unsigned int NbrMaxRes;
	unsigned int VAlim;
	float TbResistor[MAXNBRRES];
	float TbVResistor[MAXNBRRES];
};

extern void InitInfoPontDiviseur(struct pontDiviseur* demoPontDiv);
extern void CalculTensionPontDiviseur(struct pontDiviseur* demoPontDiv);
extern void AffichageTensionPontDiviseur(struct pontDiviseur demoPontDiv);


#endif
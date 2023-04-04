#ifndef PONT_RESISTIFS
#define PONT_RESISTIFS

#define NB_MAX_RESISTANCES 10
#define TENSION_MAX_PONTDIV 30
#define VALEUR_MAX_RESISTANCE 10e7
#define VALEUR_MIN_RESISTANCE 0.1

typedef struct
{
	int nbResistances;
	int tensionAlimVe;
	double tb_valResistances[NB_MAX_RESISTANCES];
	double tb_tensionAuBornes[NB_MAX_RESISTANCES];
} str_pontDiviseur; 


void InitInfoPontDiviseur (str_pontDiviseur* pt_demoPontDiv);
void CalculTensionPontDiviseur(str_pontDiviseur* pt_demoPontDiv);
void AffichageTensionPontDiviseur(str_pontDiviseur demoPontDiv);

#endif // PONT_RESISTIFS

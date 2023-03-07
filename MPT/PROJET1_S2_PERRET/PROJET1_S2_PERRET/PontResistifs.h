#ifndef PONT_RESISTIFS
#define PONT_RESISTIFS

#define NB_MAX_RESISTANCES 10
#define TENSION_MAX_PONTDIV 30
#define VALEUR_MAX_RESISTANCE 10e6
#define VALEUR_MIN_RESISTANCE 0.1

typedef struct
{
	int nbResistances;
	int tensionAlimVe;
	double tb_valResistances[10];
	double tb_tensionAuBornes[30];
} str_pontDiviseur; 


void InitInfoPontDiviseur(struct str_pontDiviseur* pt_demoPontDiv);
void CalculTensionPontDiviseur(struct str_pontDiviseur* pt_demoPontDiv);
void AffichageTensionPontDiviseur(demoPontDiv);

#endif // PONT_RESISTIFS

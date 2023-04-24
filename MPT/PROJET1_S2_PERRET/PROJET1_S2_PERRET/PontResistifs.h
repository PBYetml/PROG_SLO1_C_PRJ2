#ifndef PONT_RESISTIFS
#define PONT_RESISTIFS

/*D�claration des constantes globales*/
#define NB_MAX_RESISTANCES 10
#define TENSION_MAX_PONTDIV 30
#define VALEUR_MAX_RESISTANCE 10e6
#define VALEUR_MIN_RESISTANCE 0.1

/*D�finition de la structure*/
typedef struct
{
	int nbResistances;
	int tensionAlimVe;
	double tb_valResistances[10];
	double tb_tensionAuBornes[10];   //tension aux bornes des r�sistances 
	double tb_tentionEntreResistances[10];
} str_pontDiviseur;

/*D�claration des prototype de fonction*/
void InitInfoPontDiviseur(str_pontDiviseur* pt_demoPontDiv);
void CalculTensionPontDiviseur(str_pontDiviseur* pt_demoPontDiv);
void AffichageTensionPontDiviseur(str_pontDiviseur demoPontDiv);

#endif // PONT_RESISTIFS

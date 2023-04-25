#ifndef PONT_RESISTIFS_H 
#define PONT_RESISTIFS_H 


//-- variable gloable --// 

#define NB_MAX_resistance 10
#define TENSION_MAX 30
#define VAL_MAX_resistance 10e6
#define VAL_MIN_resistance 0.1

//--structur --//
typedef struct
{
	double tb_v_Entre_Resistances[10];
	int com_resistance;
	int alime;
	double tb_valeur_R[10];
	double tb_bornes_resistance[10];


}str_pontDiviseur;

//-- prototype --// 

void InitInfoPontDiviseur(str_pontDiviseur* pt_demoPontDiv);
void CalculTensionPontDivisueur(str_pontDiviseur* pt_demoPontDiv);
void AffichageTensionPontDivisueur(str_pontDiviseur pt_demoPontDiv);
#endif
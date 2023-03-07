




#ifndef PONT_RESISTIFS_H 
#define PONT_RESISTIFS_H 


//-- variable gloable --// 

#define NB_MAX_resistance 10
#define TENSION_MAX 30
#define VAL_MAX_resistance 1000
#define VAL_MIN_resistance 0.1


//-- prototype --// 

void InitInfoPontDiviseur(double* pt_demoPontDiv);
void CalculTensionPontDivisueur(double* demoPondDiv);
void AffichageTensionPontDivisueur(int demoPontDiv);
#endif
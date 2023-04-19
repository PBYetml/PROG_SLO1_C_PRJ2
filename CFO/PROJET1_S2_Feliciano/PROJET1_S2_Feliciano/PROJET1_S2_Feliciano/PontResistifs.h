#ifndef PontResistifs
#define PontResistifs


//d�claration des constantes global
#define Nb_Max_Res		10				// Nombre maximum de r�sistances dans le pont diviseur
#define U_Alim_Max		30				// Tension maximale d'alimentation
#define ValRes_Max			10e6			// Valeur maximale d'une r�sistance
#define ValRes_Min			0.1				// Valeur minimale d'une r�sistance


//d�finition de la structure

typedef struct
{
	unsigned char Nb_Res;		//Nombre de r�sistances dans le pont
	unsigned char Vin;			//Tension d'alimentation du pont
	float ValRes[10];			//Valeur des r�sistances
	float Val_U_Res[10];		//Valeur de la tension sur une r�sistance
	float Val_U_Entre_Res[10];	//Valeur entre deux r�sistance
}pontDiviseur;

//D�claration des prototype de fonction
void InitInfoPontDiviseur(pontDiviseur* demoPontDiv);
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv);
void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv);

#endif  //PontResistifs;

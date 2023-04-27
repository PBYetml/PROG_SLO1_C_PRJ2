#ifndef PontResistifs
#define PontResistifs

//...................................constantes

#define nombreMaxDeResPontDiv 10
#define tensionMaxPontDiv     30
#define valeurMaxRes          10e6
#define valeurMinRes          0.1

//...................................structures

typedef struct {
	unsigned char nbResComposantPonRes;
	unsigned char tensionAlimPontRes;
	float tbValRes [10];
	float tbValTensionRes [10];
	float ValTensionEntreRes[10];
}PontDiviseur;

//...................................Prototypes

void InitInofoPontDiviseur(PontDiviseur *demoPonDiv);
void CalculTensionPontDiviseur(PontDiviseur *demoPonDiv);
void affichageTensionPontDiviseur(PontDiviseur demoPonDiv);


#endif //PontResistifs

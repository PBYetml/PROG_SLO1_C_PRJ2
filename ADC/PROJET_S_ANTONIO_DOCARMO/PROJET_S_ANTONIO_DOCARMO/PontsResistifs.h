#pragma once


//CONSTANTES

const int MAX_RES_PONT = 10;
const int U_MAX_PONT = 30;
const int VAL_MAX_RES = 10e6;
const double VAL_MIN_RES = 0.1;

//STRUCTURE

typedef struct{
	int nbDeRes;
	int uAlimPont;
	int tb_valRes[9];
	int tb_uRes[9];
}pontDiviseur;

pontDiviseur* demoPontDiv;
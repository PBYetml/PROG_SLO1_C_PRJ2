/*
 -------------------------------------------------
 -- Projet : PROJET1_S2_LEO_MENDES				--
 -- Fichier : pontsResistifs.h					--
 -- Versions : 1.0								--
 -- Date : 07.03.23								--
 -- Autheur : Léo Mendes						--
 -------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "fonctionsPontDiv.c"

//Déclaration de constante 
const int nbrMaxRes = 10;
const int maxTension = 30; //en volt
const double maxRes = 10000000; //10 Mega Ohm
const float minRes = 0.1; //Ohm

#ifndef FONTIONS
#define FONCTIONS_;

//Prototype de fonctions 
void InitInfoPontDiviseur(int* pt_DemoPontdiviseur);
void CalculTensionPontDiviseur();
void AffichageTensionPontDiviseur();

#endif
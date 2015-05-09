/*
 * strategie.h
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#ifndef SRC_H_STRATEGIE_H_
#define SRC_H_STRATEGIE_H_
#include <vector>
#include "Feld.h"
#include "SpielBrett.h"
#include "KI.h"
#include "Stein.h"

class Strategie {
protected:
	const KI &ki;
	Stein &h1, &h2, &h3, &k;
	const SpielBrett &brett;

	int wert;
	std::vector<Feld*> mZuege; 	//Mögliche Züge
	std::vector<Feld*> aZuege; 	//Auswahl der Zuege nach priorietät sortiert
	Feld *nZug;					// Nächster zug

	std::vector<Feld*> getmZuege();
	virtual void bewerten()=0;
public:
	Strategie(KI &ki, SpielBrett &b);
	int getWert();
	Feld& nexstZug();
	virtual ~Strategie();
};

#endif /* SRC_H_STRATEGIE_H_ */

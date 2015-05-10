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
#include "zug.h"

class Strategie {
protected:
	KI &ki;
	Stein &h1, &h2, &h3, &k;
	SpielBrett &brett;

	int wert;
	std::vector<zug> mZuege; 	//M�gliche Z�ge
	std::vector<zug> aZuege; 	//Auswahl der Zuege nach prioriet�t sortiert
	zug nZug;					// N�chster zug

	std::vector<zug> getmZuege();
	virtual void bewerten()=0;
public:
	Strategie(KI &ki, SpielBrett &b);
	Strategie();
	int getWert();
	zug nexstZug();
	virtual ~Strategie();
};

#endif /* SRC_H_STRATEGIE_H_ */

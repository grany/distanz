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
#include "Team.h"
#include "Stein.h"
#include "zug.h"


class Strategie {
protected:
	Team &team;
	Stein &h1, &h2, &h3, &k;
	SpielBrett &brett;

	int wert;
	std::vector<zug> mZuege; 	//Mögliche Züge
	std::vector<zug> aZuege; 	//Auswahl der Zuege nach priorietät sortiert
	zug nZug;					// Nächster zug

	void getmZuege(std::vector<zug> &zuege);
	virtual void bewerten()=0;
public:
	Strategie(Team &team, SpielBrett &b);
	Strategie();
	int getWert() const;
	zug nexZug();
	std::vector<zug> getZuege() const;
	virtual ~Strategie();
};

#endif /* SRC_H_STRATEGIE_H_ */

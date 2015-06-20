/*
 * strategie.h
 *
 *  Created on: 09.05.2015
 *      Author: franz*
 */

#ifndef SRC_H_STRATEGIE_H_
#define SRC_H_STRATEGIE_H_
#include <vector>
#include "Feld.h"
#include "SpielBrett.h"
#include "Team.h"
#include "Stein.h"
#include "zug.h"

/*
 * class Strategie
 *
 * Abstrakte Klasse zur Erzeugung von speziellen Zug-Strategien.
 *
 *Als Strategien sind jene Funktionen gemeint, welche neben der Bewegung im Feld, zusätzlich auch 	
 dafür sorgen, dass es zu einer Sieg/Niederlage Situation kommt. Sie stellen die Möglichkeiten dar, 	
 welche die Spielfiguren in den jeweiligen Momenten besitzen. Die Bewertung erfolgt in Echtzeit.
 *
 */
class Strategie {
protected:
	Team &team;
	Stein &h1, &h2, &h3, &k;
	SpielBrett &brett;

	int wert;
	std::vector<zug> mZuege; 	//Moegliche Zuege
	std::vector<zug> aZuege; 	//Auswahl der Zuege nach Prioritaet sortiert
	zug nZug;					// Naechster zug

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

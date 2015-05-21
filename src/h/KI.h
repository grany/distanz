/*
 * KI.h
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#ifndef SRC_H_KI_H_
#define SRC_H_KI_H_

#include "Team.h"
#include "SpielBrett.h"
#include "zug.h"
#include "SsK.h"

class Strategie;

class KI {
private:
	static const int anzstrat=3;
	Team &t;
	SpielBrett &abrett; //Echtes Spielbrett
	Strategie* strat[anzstrat];
	SsK *dv;

	zug nZug;
	std::vector<zug> mergeStrategie(std::vector<zug> st2Zuege, Strategie *st1);
	std::vector<zug> mergeStrategie(Strategie *st1, Strategie *st2);
	std::vector<zug> mergeStrategie(Strategie *st1, std::vector<zug> st2Zuege);
	void seachBestZug(int a);
public:
	Team& getTeam();
	SpielBrett& getBrett();
	void nexZug();
	KI(Team &t);
	virtual ~KI();
};

#endif /* SRC_H_KI_H_ */

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
	Team &t;
	SpielBrett &abrett; //Echte Spielbrett
	Strategie *tk;
	SsK *dv;
	Strategie *gp;
	zug nZug;
	void seachBestZug(int a);
public:
	Team& getTeam();
	SpielBrett& getBrett();
	void nexZug();
	KI(Team &t);
	virtual ~KI();
};

#endif /* SRC_H_KI_H_ */

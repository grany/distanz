/*
 * SbK.cpp
 *
 *  Created on: 21.05.2015
 *      Author: franz
 */

#include "../h/SbK.h"
#include "../h/Feld.h"
#include <vector>

SbK::SbK(Team &team, SpielBrett &b): Strategie(team, b){}

void SbK::bewerten(){
	aZuege.clear();
	getmZuege(aZuege);
	mZuege=aZuege;
	std::vector<Feld*> gkzuege = team.getGegner()->getStein(4).zuege();
	for(auto& aZ : aZuege){
		aZ.zpos;
	}
}

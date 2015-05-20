/*
 * SrH.cpp
 *
 *  Created on: 12.05.2015
 *      Author: franz
 */

#include "../h/SrH.h"
#include <algorithm>

void SrH::bewerten(){
	aZuege.clear();
	getmZuege(aZuege);
	mZuege=aZuege;
	for(auto it : aZuege){
		(it).wert=((it).zpos==team.getStein(1).getOrt()->getPos() \
				||(it).zpos==team.getStein(2).getOrt()->getPos() \
				|| (it).zpos==team.getStein(3).getOrt()->getPos())\
						?20:(it).wert+1;
	}

	std::sort(aZuege.begin(),aZuege.end());
	nZug=aZuege[0];
	wert=nZug.wert;
}
SrH::SrH(Team &team, SpielBrett &b): Strategie(team, b){}
SrH::~SrH() {
	// TODO Auto-generated destructor stub
}


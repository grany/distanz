/*
 * SfH.cpp
 *
 *  Created on: 12.05.2015
 *      Author: franz
 */

#include "../h/SfH.h"
#include <algorithm>

void SfH::bewerten(){
	aZuege.clear();
	getmZuege(aZuege);
	mZuege=aZuege;
	for(auto it : aZuege){
		it.wert=(it.zpos==team.getGegner()->getStein(1).getOrt()->getPos() && !team.getGegner()->getStein(1).getGeffangen()) \
				|| (it.zpos==team.getGegner()->getStein(2).getOrt()->getPos() && !team.getGegner()->getStein(2).getGeffangen())\
				|| (it.zpos==team.getGegner()->getStein(3).getOrt()->getPos() && !team.getGegner()->getStein(3).getGeffangen())\
				|| (it.zpos==team.getGegner()->getStein(4).getOrt()->getPos() && !team.getGegner()->getStein(4).getGeffangen())\
						?20:(it).wert+1;
	}

	std::sort(aZuege.begin(),aZuege.end());
	nZug=aZuege[0];
	wert=(!nZug.wert)?1:2;
}
SfH::SfH(Team &team, SpielBrett &b): Strategie(team, b){}
SfH::~SfH() {
	// TODO Auto-generated destructor stub
}


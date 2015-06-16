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
		if(it.stein->getid()==4){
			it.wert=(  it.zpos==team.getStein(1).getOrt()->getPos()   && team.getStein(1).getGeffangen()) \
					||(it.zpos==team.getStein(2).getOrt()->getPos()   && team.getStein(2).getGeffangen()) \
					||(it.zpos==team.getStein(3).getOrt()->getPos()   && team.getStein(3).getGeffangen()) \
							?10:(it).wert+1;
		}else{
			it.wert+=10;
		}

	}

	std::sort(aZuege.begin(),aZuege.end());
	nZug=aZuege[0];
	wert=3;
	if(team.getStein(1).getGeffangen()&& team.getStein(2).getGeffangen()&& team.getStein(2).getGeffangen()) wert=0;
}
SrH::SrH(Team &team, SpielBrett &b): Strategie(team, b){}
SrH::~SrH() {
	// TODO Auto-generated destructor stub
}


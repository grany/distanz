/*
 * SfK.cpp
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#include "../h/SfK.h"
#include <cmath>
#include <algorithm>
#include "../h/zug.h"
#include <iostream>

void SfK::bewerten(){
	aZuege.clear();
	getmZuege(aZuege);
	mZuege=aZuege;
	Possition gk = team.getGegner()->getStein(4).getOrt()->getPos();//Possition des Gegnerischen Königs
	for(auto& i : aZuege){
		i.wert=std::abs((i).zpos.x-gk.x)+std::abs((i).zpos.y-gk.y);
	}

	std::sort(aZuege.begin(),aZuege.end());
	if(!aZuege.size()) std::cerr<<"Error SfK::bewerten :Keine Züge"<<std::endl;
	nZug=aZuege[0];
	wert=(!nZug.wert)?0:1;
}

SfK::SfK(Team &team, SpielBrett &b): Strategie(team, b){}

SfK::~SfK() {}


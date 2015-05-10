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
	Possition gk = ki.getTeam().getGegner()->getStein(4).getOrt()->getPos();//Possition des Gegnerischen Königs
	for(std::vector<zug>::iterator it=aZuege.begin(); it!=aZuege.end(); ++it){
		(*it).wert=std::abs((*it).zpos.x-gk.x)+std::abs((*it).zpos.y-gk.y);
	}
	std::sort(aZuege.begin(),aZuege.end());
	if(!aZuege.size()) std::cerr<<"Error SfK::bewerten :Keine Züge"<<std::endl;
	nZug=aZuege[0];

}

SfK::SfK(KI &ki, SpielBrett &b): Strategie(ki, b){}

SfK::~SfK() {}


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

void SfK::bewerten(){
	Possition gk = ki.getTeam().getGegner()->getStein(4).getOrt()->getPos();//Possition des Gegnerischen Königs
	aZuege=mZuege;
	for(std::vector<zug>::iterator it; it!=aZuege.end(); ++it){
		(*it).wert=std::abs((*it).zpos.x-gk.x)+std::abs((*it).zpos.y-gk.y);
	}

	std::sort(aZuege.begin(),aZuege.end(),[&](zug a, zug b){
		return a.wert < b.wert;
	});
	nZug=(aZuege.size()>0)?aZuege[0]:zug();
}

SfK::SfK(KI &ki, SpielBrett &b): Strategie(ki, b){
	// TODO Auto-generated constructor stub

}

SfK::~SfK() {
	// TODO Auto-generated destructor stub
}


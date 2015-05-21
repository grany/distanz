/*
 * SsK.cpp
 *
 *  Created on: 11.05.2015
 *      Author: franz
 */

#include "../h/SsK.h"
#include <cmath>
#include <algorithm>
#include "../h/zug.h"
#include "../h/SpielBrett.h"
#include "../h/Team.h"
#include <iostream>

bool SsK::posSicher(Possition p){
	if(gZuege.size()){
		gegner.bewerten();
		gZuege=gegner.getZuege();
	}
	for(auto& it :gZuege){
		if(it.zpos==p) return false;
	}
	return true;
}

void SsK::bewerten(){
	mZuege.clear();
		getmZuege(mZuege);
		aZuege=mZuege;
		gegner.bewerten();
		gZuege=gegner.getZuege();
		wert=4;
		if(gZuege[0].wert==0){
			wert=0;
			for(auto it : aZuege){
				if(it.zpos==gZuege[0].stein->getOrt()->getPos())  it.wert=0;
				if(it.stein->getid()==4 && posSicher(it.zpos)) it.wert=1;
				if(posSicher(it.zpos)){
					--(it).wert;
				}else{
					++(it).wert;
				}
			}
		}else{
			this->wert=gZuege[0].wert+1;
			for(auto it : aZuege){
				if(posSicher((it).zpos)){
					--(it).wert;
				}else{
					++(it).wert;
				}
			}
		}
		std::sort(aZuege.begin(),aZuege.end());
		nZug=aZuege[0];
}

SsK::SsK(Team &team, SpielBrett &b): Strategie(team, b),gegner(*team.getGegner(), b){}

SsK::~SsK() {}


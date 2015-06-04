/*
 * KI.cpp
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#include "../h/KI.h"
#include "../h/SfK.h"
#include "../h/SsK.h"
#include "../h/SfH.h"
#include "../h/SrH.h"
#include "../h/Strategie.h"
#include <iostream>
#include <algorithm>
using namespace std;

KI::KI(Team &t):t(t), abrett(*t.getBrett()), dv(new SsK(t, abrett)) {
	strat[0]=new SfK(t, abrett);
	strat[1]=new SfH(t, abrett);
	strat[2]=new SrH(t, abrett);
	strat[3]=dv;

}
void KI::nexZug(){
	seachBestZug(1);
	cout<<"KI Stein:"<<nZug.stein->getid()<<" Nach :"<<nZug.zpos.x<<":"<<nZug.zpos.y<<endl;
	nZug.stein->ziehenach(nZug.zu);
}

std::vector<zug> KI::mergeStrategie(Strategie *st1, Strategie *st2){
	st1->nexZug();
	std::vector<zug> st1Zuege(st1->getZuege());
	st2->nexZug();
	std::vector<zug> st2Zuege(st2->getZuege());
	std::vector<zug> ret;
	int i = 0;
	for(auto& s1 : st1Zuege){
		ret.push_back(s1);
		ret.back().wert=st1->getWert()+i;
		i++;
		int j=5;
		for(auto& s2 : st2Zuege){
			if((ret.back().zpos==s2.zpos)) ret.back().wert -=j;
			j--;
			if(!j) break;
		}
	}
	std::sort(ret.begin(), ret.end());
	return ret;
}
std::vector<zug> KI::mergeStrategie(Strategie *st1, std::vector<zug> st2Zuege){
	st1->nexZug();
	std::vector<zug> st1Zuege(st1->getZuege());
	std::vector<zug> ret;
	int i = 0;
	for(auto& s2 : st2Zuege){
		ret.push_back(s2);
		ret.back().wert=st1->getWert()+i;
		i++;
		int j=5;
		for(auto& s1 : st1Zuege){
			if((ret.back().zpos==s1.zpos)) ret.back().wert -=j;
			j--;
			if(!j) break;
		}
	}
	std::sort(ret.begin(), ret.end());
	return ret;
}
std::vector<zug> KI::mergeStrategie(std::vector<zug> st1Zuege, Strategie *st2){
	st2->nexZug();
	std::vector<zug> st2Zuege(st2->getZuege());
	std::vector<zug> ret;
	int i = 0;
	for(auto& s1 : st1Zuege){
		ret.push_back(s1);
		ret.back().wert+=i;
		i++;
		int j=5;
		for(auto& s2 : st2Zuege){
			if((ret.back().zpos==s2.zpos)) ret.back().wert -=j;
			j--;
			if(!j) break;
		}
	}
	std::sort(ret.begin(), ret.end());
	return ret;
}

void KI::seachBestZug(int a=1){
	dv->nexZug();
	if(dv->getWert()){
		std::vector<zug> ret =mergeStrategie(strat[0], strat[1]);
		for(int k=2;k<anzstrat;k++){
			ret = mergeStrategie(strat[k],ret);
		}
		std::sort(ret.begin(), ret.end());
		nZug=(*ret.begin());
		bool i =true;
		while(nZug.stein->getid() == 4 && i){
			i=false;
			if(!dv->posSicher(nZug.zpos)){
				i=true;
				ret.erase(ret.begin());
				cerr<<"lieber nicht"<<endl;
			}
			nZug=(*ret.begin());
		}
		for(auto& r: ret){
			cerr<<"Stein: "<<r.stein->getid()<<" Zpos: "<<r.zpos.x<<":"<<r.zpos.y<<" Wert:"<<r.wert<<endl;
		}

	}else{
		nZug=dv->nexZug();
		cerr<<"gefahr"<<endl;
		for(auto& r: dv->getZuege()){
			cerr<<"Stein: "<<r.stein->getid()<<" Zpos: "<<r.zpos.x<<":"<<r.zpos.y<<" Wert:"<<r.wert<<endl;
		}
	}



}
Team& KI::getTeam(){
	return t;
}
SpielBrett& KI::getBrett(){
	return abrett;
}

KI::~KI() {
	delete strat[0];
	delete strat[1];
	delete strat[2];
	delete dv;
	// TODO Auto-generated destructor stub
}


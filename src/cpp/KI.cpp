/*
 * KI.cpp
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#include "../h/KI.h"
#include "../h/Sfk.h"
#include <iostream>
using namespace std;

KI::KI(Team &t):t(t), abrett(*t.getBrett()), tk(new SfK(t, abrett)), dv(nullptr), gp(nullptr) {}
void KI::nexZug(){
	seachBestZug(1);
	cout<<"KI Stein:"<<nZug.stein->getid()<<" Nach :"<<nZug.zpos.x<<":"<<nZug.zpos.y<<endl;
	nZug.stein->zihenach(nZug.zu);
}
void KI::seachBestZug(int a=1){
	while(a){
		nZug=tk->nexstZug();
		a--;
	}
}
Team& KI::getTeam(){
	return t;
}
SpielBrett& KI::getBrett(){
	return abrett;
}

KI::~KI() {
	delete tk;
	// TODO Auto-generated destructor stub
}


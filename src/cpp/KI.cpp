/*
 * KI.cpp
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#include "../h/KI.h"
#include "../h/SfK.h"
#include "../h/SsK.h"
#include <iostream>
using namespace std;

KI::KI(Team &t):t(t), abrett(*t.getBrett()), tk(new SfK(t, abrett)), dv(new SsK(t, abrett)), gp(nullptr) {}
void KI::nexZug(){
	seachBestZug(1);
	cout<<"KI Stein:"<<nZug.stein->getid()<<" Nach :"<<nZug.zpos.x<<":"<<nZug.zpos.y<<endl;
	nZug.stein->zihenach(nZug.zu);
}
void KI::seachBestZug(int a=1){
			if(dv->getWert()){
				nZug=tk->nexstZug();
				if(tk->getZuege()[1]==dv->getZuege()[1]) nZug=tk->getZuege()[1];
				if(tk->nexstZug()==dv->nexstZug()) nZug=tk->nexstZug();
			}else{
				nZug=dv->nexstZug();
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
	delete dv;
	// TODO Auto-generated destructor stub
}


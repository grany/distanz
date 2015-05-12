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
			dv->nexstZug();
			tk->nexstZug();
			std::vector<zug> dvZuege(dv->getZuege());
			std::vector<zug> tkZuege(tk->getZuege());
			dv->nexstZug();
			if(dv->getWert()){
					nZug=tk->nexstZug();
					if(tkZuege[1]==dvZuege[1]) nZug=dvZuege[1];
					if(tk->nexstZug()==dv->nexstZug()) nZug=dv->nexstZug();
					bool i =true;
					while(i){
						i=false;
						if(!dv->posSicher(nZug.zpos) && nZug.stein->getid() == 4) i=true;
						tkZuege.erase(tkZuege.begin());
						nZug=tkZuege[1];
						cout<<"lieber nicht"<<endl;

					}

			}else{
				nZug=dv->nexstZug();
				cout<<"gefahr"<<endl;
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


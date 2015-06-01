/*
 * KI.cpp
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#include "../h/KI1.h"
#include "../h/SfK.h"
#include "../h/SsK.h"
#include "../h/SfH.h"
#include <iostream>
using namespace std;

KI1::KI1(Team &t):t(t), abrett(*t.getBrett()), tk(new SfK(t, abrett)), dv(new SsK(t, abrett)), gp(new SfH(t, abrett)) {}
void KI1::nexZug(){
	seachBestZug(1);
	cout<<"KI Stein:"<<nZug.stein->getid()<<" Nach :"<<nZug.zpos.x<<":"<<nZug.zpos.y<<endl;
	nZug.stein->ziehenach(nZug.zu);
}
void KI1::seachBestZug(int a=1){
			dv->nexZug();
			tk->nexZug();
			gp->nexZug();
			std::vector<zug> dvZuege(dv->getZuege());
			std::vector<zug> tkZuege(tk->getZuege());
			std::vector<zug> gpZuege(gp->getZuege());
			dv->nexZug();
			if(dv->getWert()){
				for(int k=0,j=4;k<4;k++,j--){
					nZug=(dvZuege[k]==tkZuege[j])?tkZuege[j]:tkZuege[0];
					nZug=(gpZuege[k]==tkZuege[j])?tkZuege[j]:tkZuege[0];
					nZug=(gpZuege[0].wert==20 && tkZuege[0].wert > 3)?gpZuege[0]:tkZuege[0];


				}

					bool i =true;
					while(i){
						i=false;
						if(!dv->posSicher(nZug.zpos) && nZug.stein->getid() == 4) i=true;
						tkZuege.erase(tkZuege.begin());
						nZug=tkZuege[1];
						cerr<<"lieber nicht"<<endl;

					}

			}else{
				nZug=dv->nexZug();
				cerr<<"gefahr"<<endl;
			}


}
Team& KI1::getTeam(){
	return t;
}
SpielBrett& KI1::getBrett(){
	return abrett;
}

KI1::~KI1() {
	delete tk;
	delete dv;
	// TODO Auto-generated destructor stub
}


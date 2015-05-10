/*
 * strategie.cpp
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#include "../h/Strategie.h"
#include <algorithm>
#include <iostream>
using namespace std;

Strategie::Strategie(KI &ki, SpielBrett &b) : ki(ki),  \
	h1(ki.getTeam().getStein(1)), h2(ki.getTeam().getStein(2)), h3(ki.getTeam().getStein(3)), \
	k(ki.getTeam().getStein(4)), brett(b), wert(0) \
	//,mZuege(getmZuege())
	{}

void Strategie::bewerten(){}

void Strategie::getmZuege(std::vector<zug> &zuege){
	std::vector<Feld*> th1 = h1.zuege();
	std::vector<Feld*> th2 =h2.zuege();
	std::vector<Feld*> th3 =h3.zuege();
	std::vector<Feld*> tk =k.zuege();
	for(std::vector<Feld*>::iterator it=th1.begin();it!=th1.end();it++){
		zuege.push_back(zug((*it), &h1));
	}
	for(std::vector<Feld*>::iterator it=th2.begin();it!=th2.end();it++){
			zuege.push_back(zug((*it), &h2));
		}
	for(std::vector<Feld*>::iterator it=th3.begin();it!=th3.end();it++){
			zuege.push_back(zug((*it), &h3));
		}
	for(std::vector<Feld*>::iterator it=tk.begin();it!=tk.end();it++){
			zuege.push_back(zug((*it), &k));
		}
}
zug Strategie::nexstZug(){
	bewerten();
	return nZug;
}
Strategie::~Strategie() {
	// TODO Auto-generated destructor stub
}

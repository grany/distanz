/*
 * strategie.cpp
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#include "../h/Strategie.h"
#include <algorithm>

Strategie::Strategie(KI &ki, SpielBrett &b) : ki(ki),  \
	h1(ki.getTeam().getStein(1)), h2(ki.getTeam().getStein(2)), h3(ki.getTeam().getStein(3)), \
	k(ki.getTeam().getStein(4)), brett(b), wert(0), \
	mZuege(getmZuege()), \
	nZug(Feld(), Stein()){

}

std::vector<zug> Strategie::getmZuege(){
	std::vector<Feld*> th1 = h1.zuege();
	std::vector<Feld*> th2 =h2.zuege();
	std::vector<Feld*> th3 =h3.zuege();
	std::vector<Feld*> tk =k.zuege();
	//zue.insert(zue.end(),th2.begin(), th2.end());
	//zue.insert(zue.end(),th3.begin(), th3.end());
	//zue.insert(zue.end(),tk.begin(), tk.end());
	std::vector<zug> zuege;
	for(unsigned int i = 0;i<th1.size();i++){
		zuege.push_back(zug(*th1[i], h1));
	}
	for(unsigned int i = 0;i<th2.size();i++){
		zuege.push_back(zug(*th2[i], h2));
	}
	for(unsigned int i = 0;i<th3.size();i++){
		zuege.push_back(zug(*th3[i], h3));
	}
	for(unsigned int i = 0;i<tk.size();i++){
		zuege.push_back(zug(*tk[i], k));
	}
	return  zuege;
}
zug Strategie::nexstZug(){
	return nZug;
}
Strategie::~Strategie() {
	// TODO Auto-generated destructor stub
}

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
	nZug(nullptr){

}

std::vector<Feld*> Strategie::getmZuege(){
	std::vector<Feld*> zue = h1.zuege();
	std::vector<Feld*> th2 =h2.zuege();
	std::vector<Feld*> th3 =h3.zuege();
	std::vector<Feld*> tk =k.zuege();
	zue.insert(zue.end(),th2.begin(), th2.end());
	zue.insert(zue.end(),th3.begin(), th3.end());
	zue.insert(zue.end(),tk.begin(), tk.end());

	std::sort(zue.begin(), zue.end(),[&](Feld* a, Feld* b){
		return a < b;
	});
		std::vector<Feld*>::iterator it;
		it = std::unique(zue.begin(), zue.end());
		zue.resize(std::distance(zue.begin(),it));

	return  zue;
}
Feld& Strategie::nexstZug(){
	return *nZug;
}
Strategie::~Strategie() {
	// TODO Auto-generated destructor stub
}

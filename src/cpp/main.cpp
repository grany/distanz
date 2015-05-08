/*
 * main.cpp

 *
 *  Created on: 26.04.2015
 *      Author: franz
 */

#include <iostream>
#include "../h/Spielbrett.h"
using namespace std;


int main(int _argc, char *argv[]){

	SpielBrett *br = new SpielBrett();
	Team *we = br->getWeis();
	Team *sc = br->getSchwarz();
	vector<Feld*> zue = sc->getStein(1).zuege();
	sc->getStein(1).zihenach(zue[6]);
	zue = sc->getStein(1).zuege();
	for(vector<Feld*>::iterator it = zue.begin(); it != zue.end(); it++){
		cout<<(*it)->getPos().x<<" : "<<(*it)->getPos().y<<endl;
	}
	delete br;
	return 1;
}



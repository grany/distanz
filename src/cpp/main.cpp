/*
 * main.cpp

 *
 *  Created on: 26.04.2015
 *      Author: franz
 */

#include <iostream>
#include "../h/Spielbrett.h"
#include <stdlib.h>
using namespace std;

void zeichneFeld(SpielBrett *brett){
	for(int y =0;y<8;y++){
		for(int x =0;x<8;x++){
			//((x==7) && (y==0))?cout<<"#":"";
			(!y &&!x)?cout<<" 0 1 2 3 4 5 6 7"<<endl:"";
			cout<<((brett->getFeld(x,y)->getBesetzt())?"|S":"| ");
		}
		cout<<"|"<<y<<endl;

	}

}

int main(int _argc, char *argv[]){

	SpielBrett *br = new SpielBrett();
	//Team *we = br->getWeis();
	Team *sc = br->getSchwarz();
	vector<Feld*> zue = sc->getStein(1).zuege();
	for(vector<Feld*>::iterator it = zue.begin(); it != zue.end(); it++){
			cout<<(*it)->getPos().x<<" : "<<(*it)->getPos().y<<endl;
		}
//	cout<<"#################"<<endl;
	sc->getStein(1).zihenach(zue[2]);
	zue = sc->getStein(1).zuege();
//	for(vector<Feld*>::iterator it = zue.begin(); it != zue.end(); it++){
//		cout<<(*it)->getPos().x<<" : "<<(*it)->getPos().y<<endl;
//	}
//	system("cls");

	SpielBrett cbr = *br;
	Team b = *cbr.getSchwarz();
	zue = b.getStein(2).zuege() ;
	b.getStein(2).zihenach(zue[3]);
	zeichneFeld(br);

	cout<<"##########"<<endl;

	for(vector<Feld*>::iterator it = zue.begin(); it != zue.end(); ++it){
		cout<<(*it)->getPos().x<<" : "<<(*it)->getPos().y<<endl;
	}


	zeichneFeld(&cbr);
	delete br;
	return 1;
}



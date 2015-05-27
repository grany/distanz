/*
 * main.cpp

 *
 *  Created on: 26.04.2015
 *      Author: franz
 */

#include <iostream>
#include <memory>
#include "../h/Spielbrett.h"
#include <stdlib.h>
#include "../h/KI.h"
#include "../h/KI1.h"
using namespace std;

void zeichneFeld(SpielBrett *brett){
	for(int y =0;y<8;y++){
		for(int x =0;x<8;x++){
			//((x==7) && (y==0))?cout<<"#":"";
			(!y &&!x)?cout<<"  0  1  2  3  4  5  6  7"<<endl:"";
			if(brett->getFeld(x,y)->getBesetzt()){
				if(brett->getFeld(x,y)->getGast()->getMteam()->getFarbe()){
					cout<<"|s"<<brett->getFeld(x,y)->getGast()->getid();
				}else{
					cout<<"|S"<<brett->getFeld(x,y)->getGast()->getid();
				}
			}else{
				cout<<"|  ";
			}

		}
		cout<<"|"<<y<<endl;

	}
cout<<endl;
}

int main(int _argc, char *argv[]){

	unique_ptr<SpielBrett>  br( new SpielBrett() );
	Team *we = br->getWeis();
	Team *sc = br->getSchwarz();
	KI gegner(*sc);
	KI w(*we);
	int e=0;
	int i=1;
	int j=0;
	while(e!=100){
		//system("cls");
		if(i%2){
			gegner.nexZug();
			zeichneFeld(br.get());
			if(sc->getSieg()){
				cout<<"KI Gewonnen!!!"<<endl;
				e=100;
			}
		}else{
			cout<<"--------------------------------"<<endl;
			w.nexZug();
			zeichneFeld(br.get());
			cout<<++j<<endl;

			/*
			cout<<"Stein?:"<<endl;
			int k =0;
			cin>>k;
			vector<Feld*> zue = we->getStein(k).zuege();
			int j=0;
			for(vector<Feld*>::iterator it = zue.begin(); it != zue.end(); it++){
					cout<<j<<"#"<<(*it)->getPos().x<<" : "<<(*it)->getPos().y<<endl;
					j++;
			}
			cout<<"Zug?:"<<endl;
			cin>>e;
			we->getStein(k).zihenach(zue[e]);
			*/
			if(we->getSieg()){
				cout<<"Gewonnen!!!"<<endl;
				e=100;
			}
		}
		i++;
	}
	cin>>e;
	//delete br;
	return 1;
}



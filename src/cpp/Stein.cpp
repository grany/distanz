#ifndef STEIN_C
#define STEIN_C

// Constructors/Destructors
//  

#include <iostream>

#include "../h/Feld.h"
#include "../h/Team.h"
#include "../h/Stein.h"
#include <cmath>
#include <vector>
#include <algorithm>

Stein::Stein (int id, Feld *startplatz, Team *mt) : id(id) {
	this->ort=startplatz;
	startplatz->setStein(this);
	this->geffangen=false;
	mteam=mt;
}
int Stein::getid(){
	return id;
}
Stein::~Stein(){}
void Stein::setGeffangen(){
	geffangen=true;
}
bool Stein::getGeffangen ( )   {
    return geffangen;
  }

bool sortPointer(Feld* a, Feld* b){
	return a < b;
}

std::vector<Feld*> Stein::zuege(){
	int arr[6]= {};
	std::vector<Feld*> zue;
	zue.reserve(12);
	this->mteam->distanzen(*this,arr);

	for(short int i = 0; i<5; i++){
		int px = this->ort->getPos().x + arr[i];
		int mx = this->ort->getPos().x - arr[i];

		int py = this->ort->getPos().y + arr[i+1];
		int my = this->ort->getPos().y - arr[i+1];


		if(px <= 8 && px >=0 ){
			if(py <= 8 && py >=0 ){
					zue.push_back(this->mteam->getBrett()->getFeld(px, py));
			}
			if(my >= 0 && my <= 8){
					zue.push_back(this->mteam->getBrett()->getFeld(px, my));
			}
		}
		if(mx >= 0 && mx <= 8){
					if(py <= 8 && py >=0 ){
							zue.push_back(this->mteam->getBrett()->getFeld(mx, py));
					}
					if(my >= 0 && my <= 8){
							zue.push_back(this->mteam->getBrett()->getFeld(mx, my));
					}
		}
	}

	std::sort(zue.begin(), zue.end(),sortPointer);
	std::vector<Feld*>::iterator it;
	it = std::unique(zue.begin(), zue.end());
	zue.resize(std::distance(zue.begin(),it));
	return zue;
}
void Stein::setFrei(){
	geffangen=false;
}

void Stein::zihenach(Feld *ziehe){
	if(ziehe->getBesetzt()){
		if(ziehe->getGast()->mteam==this->mteam){
			ziehe->setStein(this);
		}else{
			ziehe->getGast()->setGeffangen();
			ziehe->setStein(this);
		}
	}else{
		ziehe->setStein(this);
		ort->delStein();
		ort=ziehe;
	}
}
Team* Stein::getMteam(){
	return mteam;
}
Feld* Stein::getOrt(){
	return ort;
}
void Stein::setOrt(Feld *o){
	this->ort=o;
}
#endif

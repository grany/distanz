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
Stein::Stein(): id(0) {
	ort=nullptr;
	geffangen=false;
	mteam=nullptr;
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


		if(px <= 7 && px >=0 ){
			if(py <= 7 && py >=0 ){
					zue.push_back(this->mteam->getBrett()->getFeld(px, py));
			}
			if(my >= 0 && my <= 7){
					zue.push_back(this->mteam->getBrett()->getFeld(px, my));
			}
		}
		if(mx >= 0 && mx <= 7){
					if(py <= 7 && py >=0 ){
							zue.push_back(this->mteam->getBrett()->getFeld(mx, py));
					}
					if(my >= 0 && my <= 7){
							zue.push_back(this->mteam->getBrett()->getFeld(mx, my));
					}
		}
	}

	std::sort(zue.begin(), zue.end(),[&](Feld* a, Feld* b){
			return a < b;
		});
	std::vector<Feld*>::iterator it;
	it = std::unique(zue.begin(), zue.end());
	zue.resize(std::distance(zue.begin(),it));
	return zue;
}
void Stein::setFrei(){
	geffangen=false;
}

bool Stein::zihenach(Feld *ziehe){
	if(geffangen) return false;
	if(ziehe->getBesetzt()){
		if(ziehe->getGast()->mteam==this->mteam){
			ziehe->setStein(this);
		}else{
			ziehe->getGast()->setGeffangen();
			ziehe->setStein(this);
		}
		return true;
	}else{
		ziehe->setStein(this);
		ort->delStein();
		ort=ziehe;
		return true;
	}
	return false;
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

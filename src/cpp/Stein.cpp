#ifndef STEIN_C
#define STEIN_C

// Constructors/Destructors
//  

#include "../h/Feld.h"
#include "../h/Team.h"
#include "../h/Stein.h"
#include <cmath>
#include <vector>

Stein::Stein (Feld *startplatz, Team *mt) {
	this->ort=startplatz;
	this->geffangen=false;
	mteam=mt;
}
Stein::~Stein(){}
void Stein::setGeffangen(){
	geffangen=true;
}
bool Stein::getGeffangen ( )   {
    return geffangen;
  }

std::vector<Feld*> Stein::zuege(){
	int *arr= new int[6];
	std::vector<Feld*> zue;
	zue.reserve(12);
	this->mteam->distanzen(*this,arr);
	short int i = 6;

	while(i){
		int px = this->ort->getPos().x + *arr;
		int mx = this->ort->getPos().x - *arr;
		++arr;
		int py = this->ort->getPos().y + *arr;
		int my = this->ort->getPos().y - *arr;
		++arr;
		if(px <= 8 ){
			if(py <= 8 ){
					zue.push_back(this->mteam->getBrett()->getFeld(px, py));
			}
			if(my >= 0){
					zue.push_back(this->mteam->getBrett()->getFeld(px, my));
			}
		}
		if(mx >= 0 ){
					if(py <= 8 ){
							zue.push_back(this->mteam->getBrett()->getFeld(mx, py));
					}
					if(my >= 0){
							zue.push_back(this->mteam->getBrett()->getFeld(mx, my));
					}
		}
		i--;
	}
	delete arr;
	zue.capacity();
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
	}ziehe->setStein(this);
}
Team* Stein::getMteam(){
	return mteam;
}
Feld* Stein::getOrt(){
	return ort;
}
#endif

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

Stein::Stein (int id, Feld *startplatz, Team *mt) : id(id) {
	this->ort=startplatz;
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

std::vector<Feld*> Stein::zuege(){
	int arr[6]= {};
	std::vector<Feld*> zue;
	zue.reserve(12);
	this->mteam->distanzen(*this,arr);

	for(short int i = 0; i<5; i++){
		int px = this->ort->getPos().x + arr[i];
		int mx = this->ort->getPos().x - arr[i];
		std::cout<<"px::"<<px<<" : mx "<<mx<<std::endl;

		int py = this->ort->getPos().y + arr[i+1];
		int my = this->ort->getPos().y - arr[i+1];
		std::cout<<"py::"<<py<<" : my "<<my<<std::endl;
		std::cout<<arr[i]<<":"<<arr[i+1]<<std::endl;
		if(px <= 8 && px >=0 ){
			if(py <= 8 && py >=0 ){
					zue.push_back(this->mteam->getBrett()->getFeld(px, py));
					std::cout<<"px py"<<std::endl;
			}
			if(my >= 0 && my <= 8){
					zue.push_back(this->mteam->getBrett()->getFeld(px, my));
					std::cout<<"px my"<<std::endl;
			}
		}
		if(mx >= 0 && mx <= 8){
					if(py <= 8 && py >=0 ){
							zue.push_back(this->mteam->getBrett()->getFeld(mx, py));
							std::cout<<"mx py"<<std::endl;
					}
					if(my >= 0 && my <= 8){
							zue.push_back(this->mteam->getBrett()->getFeld(mx, my));
							std::cout<<"mx my"<<std::endl;
					}
		}
	}
	zue.shrink_to_fit();
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

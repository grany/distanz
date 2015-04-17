#ifndef STEIN_C
#define STEIN_C
#include "../h/head.h"

// Constructors/Destructors
//  

Stein::Stein (Feld *startplatz, Team *mt) {
	this->ort=startplatz;
	this->geffangen=false;
	mteam=mt;
}

void Stein::setGeffangen(){
	geffangen=true;
}
bool Stein::getGeffangen ( )   {
    return geffangen;
  }

Feld* Stein::zuege(){

	// Implementieren!!!!!!
	return new Feld(1, 2);
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
#endif

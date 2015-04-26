#ifndef STEIN_C
#define STEIN_C

// Constructors/Destructors
//  

#include "../h/Feld.h"
#include "../h/Team.h"
#include "../h/Stein.h"

Stein::Stein (Feld *startplatz, Team *mt) {
	this->ort=startplatz;
	this->geffangen=false;
	mteam=mt;
}
Stein::Stein(){}
Stein::~Stein(){}
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


#ifndef KOEING_C
#define KOEING_C
#include "../h/head.h"

// Constructors/Destructors
//  
Koenig::Koenig(Feld *startplatz, Team *mt) {
	this->ort=startplatz;
	this->geffangen=false;
	mteam=mt;
}

void Koenig::zihenach(Feld *ziehe){
	if(ziehe->getBesetzt()){
		if(ziehe->getGast()->getMteam()==this->mteam){
			ziehe->getGast()->setFrei();
			ziehe->setStein(this);
		}else{
			ziehe->getGast()->setGeffangen();
			ziehe->setStein(this);
		}
	}else{
		ziehe->setStein(this);
		this->ort->delStein();
		this->ort=ziehe;
	}ziehe->setStein(this);
}
void Koenig::setGeffangen(){
	this->mteam->getGegner()->setSieg(true);// Verloren !!!!!!!!
	this->mteam->~Team();
}
#endif

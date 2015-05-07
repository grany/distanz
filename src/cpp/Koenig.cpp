
#ifndef KOEING_C
#define KOEING_C

#include "../h/Koenig.h"
#include "../h/Feld.h"
#include "../h/Team.h"
// Constructors

Koenig::Koenig(Feld* startplatz, Team* mt) :Stein(startplatz, mt){}

void Koenig::ziehenach(Feld *ziehe){
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

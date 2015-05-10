
#ifndef KOEING_C
#define KOEING_C

#include "../h/Koenig.h"
#include "../h/Feld.h"
#include "../h/Team.h"
// Constructors

Koenig::Koenig(int id, Feld* startplatz, Team* mt) :Stein(id, startplatz, mt){}

bool Koenig::ziehenach(Feld *ziehe){
	if(geffangen){
		return false;
	}
	if(ziehe->getBesetzt()){
		if(ziehe->getGast()->getMteam()==this->mteam){
			ziehe->getGast()->setFrei();
			ziehe->setStein(this);
		}else{
			ziehe->getGast()->setGeffangen();
			ziehe->setStein(this);
		}
		return true;
	}else{
		ziehe->setStein(this);
		this->ort->delStein();
		this->ort=ziehe;
		ziehe->setStein(this);
		return true;
	}
	return false;
}
void Koenig::setGeffangen(){
	this->mteam->getGegner()->setSieg(true);// Verloren !!!!!!!!
	//this->mteam->~Team();
}
#endif

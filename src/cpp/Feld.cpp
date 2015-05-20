#ifndef STEIN_C
#define STEIN_C
#include "../h/Feld.h"
Feld::Feld(short int nx, short int ny){
	pos.x=nx;
	pos.y=ny;
	gast=nullptr;
	besetzt=false;
}
Feld::Feld(){
	pos.x=-1;
	pos.y=-1;
	gast=nullptr;
	besetzt=false;
}
Feld::Feld(Feld &f):besetzt(f.getBesetzt()), pos(f.getPos()), gast(f.getGast()){}

bool Feld::getBesetzt(){

	return this->besetzt;
}

void Feld::setStein(Stein *newstein){
	if(this->besetzt){
		//gast auf Feld von newstein Setzen
		this->gast->setOrt(newstein->getOrt());
		newstein->getOrt()->delStein();
		newstein->getOrt()->setStein(this->gast);
		//newstein auf dises Feld setzen
		this->gast=newstein;
		newstein->setOrt(this);


	}else{
		this->gast=newstein;
		this->besetzt=true;
	}
}

void Feld::delStein(){
	this->gast=nullptr;
	this->besetzt=false;
}


Possition Feld::getPos(){
	return pos;
}
Stein* Feld::getGast(){
	return gast;
}
#endif


#ifndef STEIN_C
#define STEIN_C

#include "../h/head.h"

Feld::Feld(short int nx, short int ny){
	this->pos.x=nx;
	this->pos.y=ny;
	this->gast=nullptr;
	this->besetzt=false;
}
Feld::~Feld(){}

bool Feld::getBesetzt(){

	return this->besetzt;
}

void Feld::setStein(Stein *newstein){
	if(this->besetzt){
		//Tauschen muss noch implementiertwerden
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

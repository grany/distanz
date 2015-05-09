
#ifndef TEAM_C
#define TEAM_C

// Constructors/Destructors
//  

#include <cmath>
#include "../h/Team.h"
#include "../h/Stein.h"
#include "../h/Koenig.h"
#include "../h/Possition.h"

Team::Team (SpielBrett *br, bool f, Feld *s1, Feld *s2, Feld *s3, Feld *k, Team *g=nullptr ) {
	brett=br;
	Farbe=f;
	Sieg=false;
	gegner=g;
	helfer1 = new Stein(1, s1, this);
	helfer2 = new Stein(2, s2, this);
	helfer3 = new Stein(3, s3, this);

	koenig = new Koenig(4, k, this);

}
Team::Team () {
	brett=nullptr;
	Farbe=false;
	Sieg=false;
	gegner=nullptr;
	helfer1 = nullptr;
	helfer2 = nullptr;
	helfer3 = nullptr;
	koenig = nullptr;
}

Team::~Team ( ) {
	delete helfer1;
	delete helfer2;
	delete helfer3;
	delete koenig;
}


  /**
   * @return unsigned short
   * @param  anfrage
   */
void Team::distanzen (const Stein &anfrage, int *arr ){
	Possition a, b, c;

	if(helfer1 != &anfrage){
		a = helfer1->getOrt()->getPos();
	}else{
		a = koenig->getOrt()->getPos();
	}
	if(helfer2 !=&anfrage){
		b = helfer2->getOrt()->getPos();
	}else{
		b = koenig->getOrt()->getPos();
	}
	if(helfer3 != &anfrage){
		c =helfer3->getOrt()->getPos();
	}else{
		c = koenig->getOrt()->getPos();
	}
	//a - b
	arr[0]=std::abs(a.x-b.x);
	arr[1]=std::abs(a.y-b.y);

	// a -c
	arr[2]=std::abs(a.x-c.x);
	arr[3]=std::abs(a.y-c.y);

	//b - c
	arr[4]=std::abs(b.x-c.x);
	arr[5]=std::abs(b.y-c.y);
  }


 /**
  * Set the value of Sieg
  * @param new_var the new value of Sieg
  */
 void Team::setSieg ( bool new_var )   {
     this->Sieg = new_var;
     //Gewonnen
 }
 Stein& Team::getStein(int id){
	 switch(id){
	 case 1: return *helfer1;
	 	 	 break;
	 case 2: return *helfer2;
	 	 	 	 break;
	 case 3: return *helfer3;
	 	 	 	 break;
	 case 4: return *koenig;
	 	 	 	 break;
	 }
	 return *helfer1;
 }
 void Team::setGegner ( Team *new_var ){
	 this->gegner=new_var;
 }
Team* Team::getGegner(){
	return gegner;
}
SpielBrett* Team::getBrett(){
	return this->brett;
}
#endif

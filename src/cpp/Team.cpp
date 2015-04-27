
#ifndef TEAM_C
#define TEAM_C

// Constructors/Destructors
//  
#include "../h/Team.h"
#include "../h/Stein.h"
#include "../h/Koenig.h"
#include "../h/Possition.h"

Team::Team (SpielBrett *br, bool f, Feld *s1, Feld *s2, Feld *s3, Feld *k, Team *g=nullptr ) {
	brett=br;
	Farbe=f;
	Sieg=false;
	gegner=g;
	helfer1 = new Stein(s1, this);
	helfer2 = new Stein(s2, this);
	helfer3 = new Stein(s3, this);

	koenig = new Koenig(k, this);

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
int* Team::distanzen (Stein *anfrage ){
	Possition a, b, c;
	int* arr = new int[3];
	if(helfer1 != anfrage){
		a = helfer1->getOrt()->getPos();
	}else{
		a = koenig->getOrt()->getPos();
	}
	if(helfer2 !=anfrage){
		b = helfer2->getOrt()->getPos();
	}else{
		b = koenig->getOrt()->getPos();
	}
	if(helfer3 != anfrage){
		c =helfer3->getOrt()->getPos();
	}else{
		c = koenig->getOrt()->getPos();
	}
	*arr=(a.y-b.y)+((a.x-b.x)-(a.y-b.y));
	arr++;
	*arr=(a.y-c.y)+((a.x-c.x)-(a.y-c.y));
	arr++;
	*arr=(b.y-c.y)+((b.x-c.x)-(b.y-c.y));
	  return arr;
  }


 /**
  * Set the value of Sieg
  * @param new_var the new value of Sieg
  */
 void Team::setSieg ( bool new_var )   {
     this->Sieg = new_var;
     //Gewonnen
 }

 void Team::setGegner ( Team *new_var ){
	 this->gegner=new_var;
 }
Team* Team::getGegner(){
	return gegner;
}
#endif

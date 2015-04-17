#include "../h/head.h"
#ifndef TEAM_C
#define TEAM_C


// Constructors/Destructors
//  

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
std::vector<unsigned short int> Team::distanzen (Stein *anfrage ){
	  return std::vector<unsigned short int>(1);
  }

 /**
  * Set the value of Sieg
  * @param new_var the new value of Sieg
  */
 void Team::setSieg ( bool new_var )   {
     Sieg = new_var;
     //Gewonnen
 }

 void Team::setGegner ( Team *new_var ){
	 gegner=new_var;
 }
Team* Team::getGegner(){
	return gegner;
}
#endif

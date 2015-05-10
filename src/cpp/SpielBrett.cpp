#ifndef SPIELBRETT_C
#define SPIELBRETT_C

#include <stdlib.h>
#include <iostream>
#include "../h/SpielBrett.h"

// Constructors/Destructors
//  
 SpielBrett::SpielBrett (){
	 initBrett();
	 weis = new Team(this, true, &Brett[2][7], &Brett[3][7], &Brett[6][7], &Brett[5][7], nullptr );
	 schwarz = new Team(this, false, &Brett[1][0], &Brett[4][0], &Brett[5][0], &Brett[2][0], weis );
	 weis->setGegner(schwarz);
}
 SpielBrett::SpielBrett (const SpielBrett &sb){
	 initBrett();
	 weis= new Team(this, true, this->getFeld(sb.getWeis()->getStein(1).getOrt()->getPos().x, sb.getWeis()->getStein(1).getOrt()->getPos().y) , \
			 this->getFeld(sb.getWeis()->getStein(2).getOrt()->getPos().x, sb.getWeis()->getStein(2).getOrt()->getPos().y) , \
			 this->getFeld(sb.getWeis()->getStein(3).getOrt()->getPos().x, sb.getWeis()->getStein(3).getOrt()->getPos().y), \
			 this->getFeld(sb.getWeis()->getStein(4).getOrt()->getPos().x, sb.getWeis()->getStein(4).getOrt()->getPos().y),\
			 nullptr );
	 schwarz = new Team(this, false, this->getFeld(sb.getSchwarz()->getStein(1).getOrt()->getPos().x, sb.getSchwarz()->getStein(1).getOrt()->getPos().y) , \
				 this->getFeld(sb.getSchwarz()->getStein(2).getOrt()->getPos().x, sb.getSchwarz()->getStein(2).getOrt()->getPos().y) , \
				 this->getFeld(sb.getSchwarz()->getStein(3).getOrt()->getPos().x, sb.getSchwarz()->getStein(3).getOrt()->getPos().y), \
				 this->getFeld(sb.getSchwarz()->getStein(4).getOrt()->getPos().x, sb.getSchwarz()->getStein(4).getOrt()->getPos().y),\
				 weis );
	 weis->setGegner(schwarz);
 }
 Feld* SpielBrett::getFeld(int x, int y) const {

	 if(x >=0 && x <=7 && y >=0 && y <=7) return &this->Brett[x][y];
	 std::cerr<<"Error Stein::getFeld out of bounds: x "<<x<<" | y "<<y<<std::endl;
	 exit (-1);
	 return nullptr;
 }

 void SpielBrett::initBrett(){
	 Brett = new Feld*[dimmension];
	 for(short int i = 0; i < dimmension; i++ ){
		 Brett[i] = new Feld[dimmension];
		 for(short int j = 0; j < dimmension; j++ ){
			 Brett[i][j] = Feld(i, j);
		 }
	 }
 }

Team* SpielBrett::getWeis() const{
	return this->weis;
}
Team* SpielBrett::getSchwarz() const{
	return this->schwarz;
}
SpielBrett::~SpielBrett ( ) {
	for(short int i = 0; i < dimmension; i++ ){
			 delete[] Brett[i];
	}
	delete[] Brett;
	delete weis;
	delete schwarz;
}


#endif

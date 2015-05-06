#ifndef SPIELBRETT_C
#define SPIELBRETT_C

#include "../h/SpielBrett.h"

// Constructors/Destructors
//  
 SpielBrett::SpielBrett (){
	 initBrett();
	 weis = new Team(this, true, &Brett[7][1], &Brett[7][4], &Brett[7][5], &Brett[7][2], nullptr );
	 schwarz = new Team(this, false, &Brett[0][1], &Brett[0][4], &Brett[0][5], &Brett[0][2], weis );
	 weis->setGegner(schwarz);
}
 Feld* SpielBrett::getFeld(int x, int y){

	 return &this->Brett[x][y];
 }

 void SpielBrett::initBrett(){
	 Brett = new Feld*[dimmension];
	 for(short int i = 0; i < dimmension; i++ ){
		 Brett[i] = new Feld[dimmension];
		 for(short int j = 0; j < dimmension; j++ ){
			 Brett[i][j] = Feld(j, i);
		 }
	 }
 }

Team* SpielBrett::getWeis(){
	return this->weis;
}
Team* SpielBrett::getSchwarz(){
	return this->schwarz;
}
SpielBrett::~SpielBrett ( ) {
	for(short int i = 0; i < dimmension; i++ ){
			 for(short int j = 0; j < dimmension; j++ ){
				 delete &Brett[i][j];
			 }
			 delete[] Brett[i];
	}
	delete[] Brett;
	delete weis;
	delete schwarz;
}


#endif

#ifndef SPIELBRETT_C
#define SPIELBRETT_C

#include "../h/SpielBrett.h"

// Constructors/Destructors
//  
 SpielBrett::SpielBrett (){
	 initBrett();
	 weis = new Team(this, true, &Brett[2][7], &Brett[3][7], &Brett[6][7], &Brett[5][7], nullptr );
	 schwarz = new Team(this, false, &Brett[1][0], &Brett[4][0], &Brett[5][0], &Brett[2][0], weis );
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
			 Brett[i][j] = Feld(i, j);
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
			 delete[] Brett[i];
	}
	delete[] Brett;
	delete weis;
	delete schwarz;
}


#endif

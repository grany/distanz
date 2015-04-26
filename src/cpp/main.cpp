/*
 * main.cpp

 *
 *  Created on: 26.04.2015
 *      Author: franz
 */

#include <iostream>
#include "../h/Spielbrett.h"


int main(int _argc, char *argv[]){

	SpielBrett *br = new SpielBrett();
	Team *we = br->getWeis();
	Team *sc = br->getSchwarz();

	delete br;
	return 1;
}



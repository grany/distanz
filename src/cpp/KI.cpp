/*
 * KI.cpp
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#include "../h/KI.h"

KI::KI(Team &t):t(t) {}

Team& KI::getTeam(){
	return t;
}

KI::~KI() {
	// TODO Auto-generated destructor stub
}


/*
 * zug.h
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#ifndef SRC_H_ZUG_H_
#define SRC_H_ZUG_H_

#include "Feld.h"
#include "Stein.h"

struct zug{
	Feld  &zu;
	Stein &stein;
	zug(Feld  z, Stein s): zu(z), stein(s){}
};



#endif /* SRC_H_ZUG_H_ */

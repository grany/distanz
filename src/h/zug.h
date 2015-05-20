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
#include "Possition.h"

struct zug{
	Feld  *zu=nullptr;
	Stein *stein=nullptr;
	int wert=100;
	Possition zpos;
	zug()=default;
	zug(Feld  *z, Stein *s): zu(z), stein(s), wert(100), zpos(zu->getPos()){}
	zug(const zug &z):zu(z.zu), stein(z.stein), wert(z.wert), zpos(z.zpos){}
	zug& operator =(const zug &z){
		zu=z.zu;
		stein=z.stein;
		wert=z.wert;
		zpos=z.zpos;
		return *this;
	}
	bool operator < (const zug& z) const{
			return wert<z.wert;
		}
	bool operator == (const zug& z) const{
				return zpos==z.zpos;
			}
};



#endif /* SRC_H_ZUG_H_ */

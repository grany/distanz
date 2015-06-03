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
/**
 * struct zug
 * Daten Struktur die einen Spiel-Zug Symbolysiert.
 */
struct zug{
	Feld  *zu=nullptr; 	  /**Feld auf das gezogen werden soll*/
	Stein *stein=nullptr; /*< pointer auf Stein*/
	int wert=100;
	Possition zpos;		/*< possition auf die gezogen werden soll*/
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
	/**
	 * kleiner als Operator
	 * vergleicht züge nach wertigkeit;
	 * @param z
	 * @return
	 */
	bool operator < (const zug& z) const{
			return wert<z.wert;
		}
	/**
	 * Vergleichs Operator
	 * Vergleicht züge auf gleiche Ziel Position
	 * @param z
	 * @return
	 */
	bool operator == (const zug& z) const{
				return zpos==z.zpos;
			}
};



#endif /* SRC_H_ZUG_H_ */

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
#include "Possition.h"				//Position
/**
 * struct Zug
 * Daten Struktur die einen Spiel-Zug Symbolysiert.
 */
struct zug{
	Feld  *zu=nullptr; 	  /*Das Feld, auf welches gezogen werden soll.*/
	Stein *stein=nullptr; /*< Pointer auf Stein*/
	int wert=100;
	Possition zpos;		/*< Position auf die gezogen werden soll.*/	//Position
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
	 * Kleiner als Operator
	 * Vergleicht Züge nach Wertigkeit;
	 * @param z
	 * @return
	 */
	bool operator < (const zug& z) const{
			return wert<z.wert;
		}
	/**
	 * Vergleichs-Operator
	 * Vergleicht Züge auf gleiche Ziel-Position
	 * @param z
	 * @return
	 */
	bool operator == (const zug& z) const{
				return zpos==z.zpos;
			}
};



#endif /* SRC_H_ZUG_H_ */

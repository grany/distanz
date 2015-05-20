/*
 * SsK.h
 *
 *  Created on: 11.05.2015
 *      Author: franz
 */

#ifndef SRC_H_SSK_H_
#define SRC_H_SSK_H_

#include "Strategie.h"
#include "SfK.h"
/**
 * class SsK (Strategie sch�tze K�nig)
 * ist eine Ableitung der abstrakten Klasse Strategie.
 * �berschreibt/implementiert die methode bewerten();
 * @param &team reverence auf instanz von Team
 * @param &b 	reverence auf instanz von SpielBrett
 */
class SsK: public Strategie {
private:
	SfK gegner;
	std::vector<zug> gZuege;	//Gegnerische z�ge
public:
	/*
	 * bewerten()
	 * bewerted m�gliche z�ge nach der m�glichkeit eigenen K�nig zu sichern.
	 */
	virtual void bewerten() override;

	/*
	 * posSicher(Possition p)
	 *
	 * pr�ft ob �bergebene Possition vom gegner im n�chsten zug besetzt werden kann.
	 * @param p : Possition
	 * @return bool false-> gef�rdet; true->sicher;
	 */
	bool posSicher(Possition p);
	SsK(Team &team, SpielBrett &b);
	SsK();
	virtual ~SsK();
};

#endif /* SRC_H_SSK_H_ */

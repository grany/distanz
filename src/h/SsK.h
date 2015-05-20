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
 * class SsK (Strategie schütze König)
 * ist eine Ableitung der abstrakten Klasse Strategie.
 * Überschreibt/implementiert die methode bewerten();
 * @param &team reverence auf instanz von Team
 * @param &b 	reverence auf instanz von SpielBrett
 */
class SsK: public Strategie {
private:
	SfK gegner;
	std::vector<zug> gZuege;	//Gegnerische züge
public:
	/*
	 * bewerten()
	 * bewerted mögliche züge nach der möglichkeit eigenen König zu sichern.
	 */
	virtual void bewerten() override;

	/*
	 * posSicher(Possition p)
	 *
	 * prüft ob übergebene Possition vom gegner im nächsten zug besetzt werden kann.
	 * @param p : Possition
	 * @return bool false-> gefärdet; true->sicher;
	 */
	bool posSicher(Possition p);
	SsK(Team &team, SpielBrett &b);
	SsK();
	virtual ~SsK();
};

#endif /* SRC_H_SSK_H_ */

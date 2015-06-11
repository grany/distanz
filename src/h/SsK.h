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
 * Ist eine Ableitung der abstrakten Klasse Strategie.
 * Überschreibt/implementiert die Methode bewerten();
 * @param &team Referenz auf Instanz von Team
 * @param &b 	Referenz auf Instanz von SpielBrett
 */
class SsK: public Strategie {
private:
	SfK gegner;
	std::vector<zug> gZuege;	//Gegnerische Züge
public:
	/*
	 * bewerten()
	 * Bewertet mögliche Züge nach der Möglichkeit eigenen König zu sichern.
	 */
	virtual void bewerten() override;

	/*
	 * posSicher(Position p)
	 *
	 * Prüft ob übergebene Position vom Gegner im nächsten Zug besetzt werden kann.
	 * @param p : Position
	 * @return bool false-> gefährdet; true->sicher;
	 */
	bool posSicher(Possition p);		//Position
	SsK(Team &team, SpielBrett &b);
	SsK();
	virtual ~SsK();
};

#endif /* SRC_H_SSK_H_ */

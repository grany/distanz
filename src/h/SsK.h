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
 * class SsK (Strategie schuetze Koenig)
 * Ist eine Ableitung der abstrakten Klasse Strategie.
 * Ueberschreibt/implementiert die Methode bewerten();
 * @param &team Referenz auf Instanz von Team
 * @param &b 	Referenz auf Instanz von SpielBrett
 */
class SsK: public Strategie {
private:
	SfK gegner;
	std::vector<zug> gZuege;	//Gegnerische Zuege
public:
	/*
	 * bewerten()
	 * Bewertet moegliche Zuege nach der Moeglichkeit eigenen Koenig zu sichern.
	 */
	virtual void bewerten() override;

	/*
	 * posSicher(Position p)
	 *
	 * Prueft ob uebergebene Position vom Gegner im naechsten Zug besetzt werden kann.
	 * @param p : Position
	 * @return bool false-> gefaehrdet; true->sicher;
	 */
	bool posSicher(Possition p);		//Position
	SsK(Team &team, SpielBrett &b);
	SsK();
	virtual ~SsK();
};

#endif /* SRC_H_SSK_H_ */

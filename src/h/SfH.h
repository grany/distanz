/*
 * SfH.h
 *
 *  Created on: 12.05.2015
 *      Author: franz
 */

#ifndef SRC_H_SFH_H_
#define SRC_H_SFH_H_

#include "Strategie.h"

/**
 * class SfH (Strategie fange Helfer)
 * Ist eine Ableitung der abstrakten Klasse Strategie.
 * Ueberschreibt/implementiert die Methode bewerten();
 * @param &team Referenz auf Instanz von Team
 * @param &b 	Referenz auf Instanz von SpielBrett
 */
class SfH: public Strategie {
public:
	/*
	 * bewerten()
	 * Bewertet moegliche Zuege nach der Moeglichkeit gegnerische Helfer zu fangen.
	 */
	virtual void bewerten() override;
	SfH(Team &team, SpielBrett &b);
	virtual ~SfH();
};

#endif /* SRC_H_SFH_H_ */

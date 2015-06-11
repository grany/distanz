/*
 * SfK.h
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#ifndef SRC_SFK_H_
#define SRC_SFK_H_

#include "Team.h"
#include "SpielBrett.h"
#include "Strategie.h"

/**
 * class SfK (Strategie fange König)
 * Ist eine Ableitung der abstrakten Klasse Strategie.
 * Überschreibt/implementiert die methode bewerten();
 * @param &team Referenz auf Instanz von Team
 * @param &b 	Referenz auf Instanz von SpielBrett
 */
class SfK: public Strategie {
public:
	/*
	 * bewerten()
	 * Bewertet mögliche Züge nach der Möglichkeit gegnerischen König zu fangen.
	 */
	virtual void bewerten() override;
	SfK(Team &team, SpielBrett &b);
	SfK();
	virtual ~SfK();
};

#endif /* SRC_SFK_H_ */

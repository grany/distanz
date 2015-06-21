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
 * class SfK (Strategie fange K�nig)
 * Ist eine Ableitung der abstrakten Klasse Strategie.
 * ################################################################################################################
 * Diese Strategie sorgt daf�r, dass sich die Spielfiguren dem gegnerischen K�nig n�hern, um in festsetzen/gefangen nehmen
 * zu k�nnen. Ein festgesetzter/gefangener K�nig bedeutet das Spielende. Ein Sieg wird erzielt, sobald der gegnerische K�nig
 * festgesetzt/gefangen ist.
 * ################################################################################################################
 * �berschreibt/implementiert die Methode bewerten();
 * @param &team Referenz auf Instanz von Team
 * @param &b 	Referenz auf Instanz von SpielBrett
 */
class SfK: public Strategie {
public:
	/*
	 * bewerten()
	 * Bewertet moegliche Zuege nach der Moeglichkeit gegnerischen Koenig zu fangen.
	 */
	virtual void bewerten() override;
	SfK(Team &team, SpielBrett &b);
	SfK();
	virtual ~SfK();
};

#endif /* SRC_SFK_H_ */

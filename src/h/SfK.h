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
 * ist eine Ableitung der abstrakten Klasse Strategie.
 * �berschreibt/implementiert die methode bewerten();
 * @param &team reverence auf instanz von Team
 * @param &b 	reverence auf instanz von SpielBrett
 */
class SfK: public Strategie {
public:
	/*
	 * bewerten()
	 * bewerted m�gliche z�ge nach der m�glichkeit gegnerischen K�nig zu fangen.
	 */
	virtual void bewerten() override;
	SfK(Team &team, SpielBrett &b);
	SfK();
	virtual ~SfK();
};

#endif /* SRC_SFK_H_ */

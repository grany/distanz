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
 * ist eine Ableitung der abstrakten Klasse Strategie.
 * Überschreibt/implementiert die methode bewerten();
 * @param &team reverence auf instanz von Team
 * @param &b 	reverence auf instanz von SpielBrett
 */
class SfH: public Strategie {
public:
	/*
	 * bewerten()
	 * bewerted mögliche züge nach der möglichkeit gegnerische Helfer zu fangen.
	 */
	virtual void bewerten() override;
	SfH(Team &team, SpielBrett &b);
	virtual ~SfH();
};

#endif /* SRC_H_SFH_H_ */

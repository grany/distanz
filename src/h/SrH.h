/*
 * SrH.h
 *
 *  Created on: 12.05.2015
 *      Author: franz
 */

#ifndef SRC_H_SRH_H_
#define SRC_H_SRH_H_

#include "Strategie.h"

/**
 * class SrH (Strategie rette Helfer)
 * ist eine Ableitung der abstrakten Klasse Strategie.
 * �berschreibt/implementiert die methode bewerten();
 * @param &team reverence auf instanz von Team
 * @param &b 	reverence auf instanz von SpielBrett
 */
class SrH: public Strategie {
public:
	/*
	 * bewerten()
	 * bewerted m�gliche z�ge nach der m�glichkeit Helfer zu retten.
	 */
	virtual void bewerten() override;
	SrH(Team &team, SpielBrett &b);
	virtual ~SrH();
};

#endif /* SRC_H_SRH_H_ */

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
 * Ist eine Ableitung der abstrakten Klasse Strategie.
 * Überschreibt/implementiert die Methode bewerten();
 * @param &team Referenz auf Instanz von Team
 * @param &b 	Referenz auf Instanz von SpielBrett
 */
class SrH: public Strategie {
public:
	/*
	 * bewerten()
	 * Bewertet mögliche Züge nach der Möglichkeit Helfer zu retten.
	 */
	virtual void bewerten() override;
	SrH(Team &team, SpielBrett &b);
	virtual ~SrH();
};

#endif /* SRC_H_SRH_H_ */

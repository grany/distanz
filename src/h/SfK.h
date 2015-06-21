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
 * ################################################################################################################
 * Diese Strategie sorgt dafür, dass sich die Spielfiguren dem gegnerischen König nähern, um in festsetzen/gefangen nehmen
 * zu können. Ein festgesetzter/gefangener König bedeutet das Spielende. Ein Sieg wird erzielt, sobald der gegnerische König
 * festgesetzt/gefangen ist.
 * ################################################################################################################
 * Überschreibt/implementiert die Methode bewerten();
 * @param &team Referenz auf Instanz von Team
 * @param &b 	Referenz auf Instanz von SpielBrett
 */
class SfK: public Strategie {
public:
	/**
		 * bewerten()
		 * Bewertet mögliche Züge nach der Möglichkeit gegnerischen König zu fangen.
		 * \image html SfK_bewerten.png
		 * \image latex SfK_bewerten.eps
		 * @startuml{SfK_bewerten.png}
		 * start
		 * :Berechne Mögliche Züge;
		 * :Hohle Position vom gegnerischen König;
		 * note right: Wert initalisiert mit 100
		 * while (nächster Zug?)
		 *  :zug wert=|x_zug-x_könig| + |y_zug - y_könig|;
		 * endwhile
		 * :Sortiere Züge nach Wert;
		 * if (Erster zug wert = 0) then (ja)
		 *  :Wert der Strategie = 0;
		 * else (nein)
		 *  :Wert der Strategie = 1;
		 *  endif
		 * end
		 * @enduml
		 */
	virtual void bewerten() override;
	SfK(Team &team, SpielBrett &b);
	SfK();
	virtual ~SfK();
};

#endif /* SRC_SFK_H_ */

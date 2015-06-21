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
 * implementiert die Methode bewerten();
 * ################################################################################################################
 * Diese Strategie sorgt dafür, dass die gegnerischen Helfer festgesetzt/gefangen werden. Ein festgesetzter/gefangener
 * Helfer stellt insofern keine Bedrohung mehr dar, bis er wieder vom Koenig befreit wird. Dies gilt es durch andere
 * Strategien zu verhindern.
 * ################################################################################################################
 *
 * @param &team Referenz auf Instanz von Team
 * @param &b 	Referenz auf Instanz von SpielBrett
 */
class SfH: public Strategie {
public:
	/**
	 * bewerten()
	 * Bewertet mögliche Züge nach der Möglichkeit gegnerische Helfer zu fangen.
	 * \image html SfH_bewerten.png
	 * \image latex SfH_bewerten.png
	 * @startuml{SfH_bewerten.png}
	 * start
	 * :Berechne Mögliche Züge;
	 * note right: Wert initalisiert mit 100
	 * while (nächster Zug?)
	 *  if (Zug Position = Position von Gegner) then (ja)
	 *   :Zug wert = 20;
	 *  else (nein)
	 *   :Zug Wert + 1;
	 *  endif
	 * endwhile
	 * :Sortiere Züge nach Wert;
	 *  :Wert der Strategie = 2;
	 * end
	 * @enduml
	 */
	virtual void bewerten() override;
	SfH(Team &team, SpielBrett &b);
	virtual ~SfH();
};

#endif /* SRC_H_SFH_H_ */

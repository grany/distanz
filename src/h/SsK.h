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
 * ################################################################################################################
 * Diese Strategie sorgt dafuer, dass der teameigene Koenig vor festsetzen/gefangen nehmen durch feindliche Spielfiguren
 * geschuetzt wird. Zu beobachten ist hierbei das fangen von gegnerischen Spielfiguren, sobald sie dem König zu nahe kommen.
 * Auch der Koenig selber nimmt ein sehr defensives Verhalten an und haelt sich von den Gegnern fern, um ein fruehzeitiges
 * Ableben zu verhindern.
 * ################################################################################################################
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

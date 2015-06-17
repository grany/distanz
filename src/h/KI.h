/*
 * KI.h
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#ifndef SRC_H_KI_H_
#define SRC_H_KI_H_

#include "Team.h"
#include "SpielBrett.h"
#include "zug.h"
#include "SsK.h"

class Strategie;
/**
 * class KI
 * Ist eine Klasse die aus den Möglichen Spielzügen den besten Auswählt
 * sie ist mit zusetzlichen Strategien erweiterbar.
 */
class KI {
private:
	static const int anzstrat=4;	/*<Anzahl verwendeter Strategien*/
	Team &t;
	SpielBrett &abrett; //Echtes Spielbrett
	Strategie* strat[anzstrat];
	SsK *dv;

	zug nZug;
	/**
	 * mergeStrategie
	 * Vereint zwei Strategien und fürt die Wertigkeiten zusammen
	 * @param [in] st1 Pointer auf eine Strategie
	 * @param [in] st2Zuege Vector mit Zügen.
	 * @return	Vector mit nach wertigkeit sortierten zügen.
	 */
	std::vector<zug> mergeStrategie(Strategie *st1 ,std::vector<zug> st2Zuege);
	/**
	 * * mergeStrategie
	 * Vereint zwei Strategien und fürt die Wertigkeiten zusammen
	 * @param [in] st1 Pointer auf eine Strategie.
	 * @param [in] st2 Pointer auf eine Strategie.
	 * @return Vector mit nach wertigkeit sortierten zügen.
	 */
	std::vector<zug> mergeStrategie(Strategie *st1, Strategie *st2);

	/**
	 * seachBestZug
	 * Wählt aus den Zusammen gefürten Strategieen den besten aus.
	 * Und stelt sicher das der könig nicht in gefar ist/kommt.
	 *
	 */
	void seachBestZug();
public:
	/**
	 * getTeam
	 * @return Reference auf das Gesteuerte Team
	 */
	Team& getTeam();

	/**
	 * getBrett
	 * @return Reference auf Spielbrett
	 */
	SpielBrett& getBrett();

	/**
	 * nexZug
	 * Führt den nächsten Zug aus
	 */
	void nexZug();
	/**
	 * KI Konstruktor
	 * @param [in,out] t Reference auf das Team was gesteuertwerden soll
	 */
	KI(Team &t);
	virtual ~KI();
};

#endif /* SRC_H_KI_H_ */

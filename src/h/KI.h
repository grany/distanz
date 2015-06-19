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
 * Ist eine Klasse die aus den M�glichen Spielz�gen den besten Ausw�hlt
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
	 * Vereint zwei Strategien und f�rt die Wertigkeiten zusammen.
	 * Je kleiner die wertigkeits Zahl desto besser ist der zug.
	 * \image html KI_mergeStrategie.png
	 * \image latex KI_mergeStrategie.png
	 * @param [in] st1 Pointer auf eine Strategie
	 * @param [in] st2Zuege Vector mit Z�gen.
	 * @return	Vector mit nach wertigkeit sortierten z�gen.
	 * @startuml{KI_mergeStrategie.png}
	 * start
	 * :Hohle Z�ge f�r Strategie 1;
	 * :Hohle Z�ge f�r schon zusammen gef�hrte Strategien 2;
	 * :z�hler;
	 * while (n�chster zug f�r Strategie 1?)
	 *  :Speichere zug;
	 *  :Wertigkeit zug = Wertigkeit Strategie + Z�hler;
	 *  :z�hler2 = 5;
	 *  while (ersten 5 Z�ge Strategien 2)
	 *   if (Gleicher zug?) then (ja)
	 *    :Wertigkeit zug - z�hler2;
	 *    :z�hler2 - 1;
	 *  else (nein)
	 *
	 *  endif
	 *  endwhile
	 * endwhile
	 * :Sortiere Gespeicherte z�ge;
	 * :return z�ge;
	 * end
	 * @enduml
	 */
	std::vector<zug> mergeStrategie(Strategie *st1 ,std::vector<zug> st2Zuege);
	/**
	 * * mergeStrategie
	 * Vereint zwei Strategien und f�rt die Wertigkeiten zusammen.
	 * Je kleiner die wertigkeits Zahl desto besser ist der zug.
	 * @param [in] st1 Pointer auf eine Strategie.
	 * @param [in] st2 Pointer auf eine Strategie.
	 * @return Vector mit nach wertigkeit sortierten z�gen.
	 */
	std::vector<zug> mergeStrategie(Strategie *st1, Strategie *st2);

	/**
	 * seachBestZug
	 * W�hlt aus den Zusammen gef�rten Strategieen den besten aus.
	 * Und stelt sicher das der k�nig nicht in gefar ist/kommt.
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
	 * F�hrt den n�chsten Zug aus
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

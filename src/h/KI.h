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
 * Ist eine Klasse, die aus den moeglichen Spielzuegen den besten auswaehlt.
 * Sie ist mit zusaetzlichen Strategien erweiterbar.
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
	 * Vereint zwei Strategien und fuehrt die Wertigkeiten zusammen.
	 * Je kleiner die Wertigkeits-Zahl desto besser ist der Zug.
	 * \image html KI_mergeStrategie.png
	 * \image latex KI_mergeStrategie.png
	 * @param [in] st1 Pointer auf eine Strategie
	 * @param [in] st2Zuege Vector mit Zuegen.
	 * @return	Vector mit nach Wertigkeit sortierten Zuegen.
	 * @startuml{KI_mergeStrategie.png}
	 * start
	 * :Hohle Zuege für Strategie 1;
	 * :Hohle Zuege für schon zusammen gefuehrte Strategien 2;
	 * :zaehler;
	 * while (naechster Zug für Strategie 1?)
	 *  :Speichere Zug;
	 *  :Wertigkeit Zug = Wertigkeit Strategie + Zaehler;
	 *  :zaehler2 = 5;
	 *  while (ersten 5 Zuege Strategien 2)
	 *   if (Gleicher zug?) then (ja)
	 *    :Wertigkeit zug - zaehler2;
	 *    :zaehler2 - 1;
	 *  else (nein)
	 *
	 *  endif
	 *  endwhile
	 * endwhile
	 * :Sortiere Gespeicherte Zuege;
	 * :return Zuege;
	 * end
	 * @enduml
	 */
	std::vector<zug> mergeStrategie(Strategie *st1 ,std::vector<zug> st2Zuege);
	/**
	 * * mergeStrategie
	 * Vereint zwei Strategien und fuehrt die Wertigkeiten zusammen.
	 * Je kleiner die wertigkeits Zahl desto besser ist der Zug.
	 * \image html KI_mergeStrategie.png
	 * \image latex KI_mergeStrategie.png
	 * @param [in] st1 Pointer auf eine Strategie.
	 * @param [in] st2 Pointer auf eine Strategie.
	 * @return Vector mit nach Wertigkeit sortierten Zuegen.
	 */
	std::vector<zug> mergeStrategie(Strategie *st1, Strategie *st2);

	/**
	 * searchBestZug
	 * Waehlt aus den zusammengefuehrten Strategien den Besten aus.
	 * Und stellt sicher, dass der Koenig nicht in Gefahr ist/kommt.
	 * \image html KI_searchBestZug.png
	 * \image latex KI_searchBestZug.png
	 * @startuml{KI_searchBestZug.png}
	 * start
	 * :Strategie schuetze Koenig->Berechnen;
	 * if (Koenig in Gefahr?) then (nein)
	 *  while (naechste Strategie?)
	 *   :mergeStrategie(Strategie, naechste Strategie);
	 *  endwhile
	 *  :Naechster Zug = erster Eintrag in gemergten Strategien;
	 *  while (Naechster Zug von Koenig?)
	 *   if (ist der Zug sicher?) then (ja)
	 *    :Naechster Zug = erster Eintrag in gemergten Strategien;
	 *    :Schleife abbrechen;
	 *   else (nein)
	 *    :Loesche ersten Zug aus gemergten Strategien;
	 *   endif
	 *  endwhile
	 * else (ja)
	 *  :naechster Zug = Erster zug aus Defensiver Strategie;
	 * endif
	 * end
	 * @enduml
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
	 * Fuehrt den naechsten Zug aus
	 * \image html nexZug.png
	 * \image latex nexZug.png
	 * @startuml{KI_nexZug.png}
	 * start
	 * :searchBestZug;
	 * :fuehre naechsten Zug aus;
	 * end
	 * @enduml
	 */
	void nexZug();
	/**
	 * KI Konstruktor
	 * @param [in,out] t Reference auf das Team was gesteuert werden soll
	 */
	KI(Team &t);
	virtual ~KI();
};

#endif /* SRC_H_KI_H_ */

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
 * Ist eine Klasse die aus den möglichen Spielzügen den besten auswählt.
 * Sie ist mit zusätzlichen Strategien erweiterbar.
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
	 * Vereint zwei Strategien und führt die Wertigkeiten zusammen.
	 * Je kleiner die Wertigkeits-Zahl desto besser ist der zug.
	 * \image html KI_mergeStrategie.png
	 * \image latex KI_mergeStrategie.eps
	 * @param [in] st1 Pointer auf eine Strategie
	 * @param [in] st2Zuege Vector mit Zügen.
	 * @return	Vector mit nach wertigkeit sortierten zügen.
	 * @startuml{KI_mergeStrategie.png}
	 * start
	 * :Hohle Züge für Strategie 1;
	 * :Hohle Züge für schon zusammen geführte Strategien 2;
	 * :zähler;
	 * while (nächster zug für Strategie 1?)
	 *  :Speichere zug;
	 *  :Wertigkeit zug = Wertigkeit Strategie + Zähler;
	 *  :zähler2 = 5;
	 *  while (ersten 5 Züge Strategien 2)
	 *   if (Gleicher zug?) then (ja)
	 *    :Wertigkeit zug - zähler2;
	 *    :zähler2 - 1;
	 *  else (nein)
	 *
	 *  endif
	 *  endwhile
	 * endwhile
	 * :Sortiere Gespeicherte züge;
	 * :return züge;
	 * end
	 * @enduml
	 */
	std::vector<zug> mergeStrategie(Strategie *st1 ,std::vector<zug> st2Zuege);
	/**
	 * * mergeStrategie
	 * Vereint zwei Strategien und fürt die Wertigkeiten zusammen.
	 * Je kleiner die wertigkeits Zahl desto besser ist der Zug.
	 * \image html KI_mergeStrategie.png
	 * \image latex KI_mergeStrategie.eps
	 * @param [in] st1 Pointer auf eine Strategie.
	 * @param [in] st2 Pointer auf eine Strategie.
	 * @return Vector mit nach Wertigkeit sortierten Zügen.
	 */
	std::vector<zug> mergeStrategie(Strategie *st1, Strategie *st2);

	/**
	 * seachBestZug
	 * Wählt aus den zusammengefürten Strategien den besten Zug aus.
	 * Und stelt sicher das der König nicht in Gefahr ist bzw. kommt.
	 * \image html KI_searchBestZug.png
	 * \image latex KI_searchBestZug.eps
	 * @startuml{KI_searchBestZug.png}
	 * start
	 * :Strategie schütze König->berechnen;
	 * if (König in Gefahr?) then (nein)
	 *  while (nächste Strategie?)
	 *   :mergeStrategie(Strategie, nächste Strategie);
	 *  endwhile
	 *  :Nächster Zug = erster Eintrag in gemergten Strategien;
	 *  while (Nächster Zug von König?)
	 *   if (ist der Zug sicher?) then (ja)
	 *    :Nächster Zug = erster Eintrag in gemergten Strategien;
	 *    :Schleife abbrechen;
	 *   else (nein)
	 *    :Lösche ersten zug aus gemergten Strategien;
	 *   endif
	 *  endwhile
	 * else (ja)
	 *  :nächster Zug = Erster Zug aus defensiver Strategie;
	 * endif
	 * end
	 * @enduml
	 *
	 */
	void seachBestZug();
public:
	/**
	 * getTeam
	 * @return Referenz auf das gesteuerte Team
	 */
	Team& getTeam();

	/**
	 * getBrett
	 * @return Referenz auf das Spielbrett
	 */
	SpielBrett& getBrett();

	/**
	 * nexZug
	 * Führt den nächsten Zug aus
	 * \image html KI_nexZug.png
	 * \image latex KI_nexZug.eps
	 * @startuml{KI_nexZug.png}
	 * start
	 * :searchBestZug;
	 * :führe nächsten Zug aus;
	 * end
	 * @enduml
	 */
	void nexZug();
	/**
	 * KI Konstruktor
	 * @param [in,out] t Referenz auf das Team, das gesteuert werden soll
	 */
	KI(Team &t);
	virtual ~KI();
};

#endif /* SRC_H_KI_H_ */

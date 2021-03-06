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
 * Ist eine Klasse die aus den m�glichen Spielz�gen den besten ausw�hlt.
 * Sie ist mit zus�tzlichen Strategien erweiterbar.
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
	 * Vereint zwei Strategien und f�hrt die Wertigkeiten zusammen.
	 * Je kleiner die Wertigkeits-Zahl desto besser ist der zug.
	 * \image html KI_mergeStrategie.png
	 * \image latex KI_mergeStrategie.eps
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
	 * Je kleiner die wertigkeits Zahl desto besser ist der Zug.
	 * \image html KI_mergeStrategie.png
	 * \image latex KI_mergeStrategie.eps
	 * @param [in] st1 Pointer auf eine Strategie.
	 * @param [in] st2 Pointer auf eine Strategie.
	 * @return Vector mit nach Wertigkeit sortierten Z�gen.
	 */
	std::vector<zug> mergeStrategie(Strategie *st1, Strategie *st2);

	/**
	 * seachBestZug
	 * W�hlt aus den zusammengef�rten Strategien den besten Zug aus.
	 * Und stelt sicher das der K�nig nicht in Gefahr ist bzw. kommt.
	 * \image html KI_searchBestZug.png
	 * \image latex KI_searchBestZug.eps
	 * @startuml{KI_searchBestZug.png}
	 * start
	 * :Strategie sch�tze K�nig->berechnen;
	 * if (K�nig in Gefahr?) then (nein)
	 *  while (n�chste Strategie?)
	 *   :mergeStrategie(Strategie, n�chste Strategie);
	 *  endwhile
	 *  :N�chster Zug = erster Eintrag in gemergten Strategien;
	 *  while (N�chster Zug von K�nig?)
	 *   if (ist der Zug sicher?) then (ja)
	 *    :N�chster Zug = erster Eintrag in gemergten Strategien;
	 *    :Schleife abbrechen;
	 *   else (nein)
	 *    :L�sche ersten zug aus gemergten Strategien;
	 *   endif
	 *  endwhile
	 * else (ja)
	 *  :n�chster Zug = Erster Zug aus defensiver Strategie;
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
	 * F�hrt den n�chsten Zug aus
	 * \image html KI_nexZug.png
	 * \image latex KI_nexZug.eps
	 * @startuml{KI_nexZug.png}
	 * start
	 * :searchBestZug;
	 * :f�hre n�chsten Zug aus;
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

#include "SpielBrett.h"
#include "../h/KI.h"
/**
 * class GUI
 * Die Abk�rzung GUI steht f�r graphical user interface bzw. grafische Benutzeroberfl�che.
 * Durch diese Klasse wird dem Benutzer eine grafische Oberfl�che zur Verf�gung gestellt, �ber die er mit dem Programm interagierien kann.
 * Alle Benutzereingaben erfolgen ausschlie�lich �ber die Tastatur. Unterst�tzend wird die Strucktur der erwarteten Eingabe in Klammern
 * mit angegeben. Sollte dennoch der Benutzer eine Falsch Eingabe t�tigen, so wird er darauf hingewiesen und kann seine Eingabe nach 3 Sekunken wiederholen.
 * Die Darstellung des Spielfeldes und wichtiger Spielparameter erfolgt in der Windows Konsole �ber ANSI-Zeichen.
 */
class GUI
{
private:
SpielBrett *brett;
KI *KIsw;
public:
	GUI(SpielBrett *br, KI *ki);
	/**GUI
	* Diese Funktion ist ein Konstructor f�r eine Instanz von der Klasse Spielbrett.
	*
	*/

	void zeichneSpielfeld(int zug,int spieler);
	/**zeichneSpielfeld(zug,spieler)
	* Mit dieser Funktion wird das Spielfeld grafisch f�r den Spieler aufbereitet.
	* @param [int] zug		gibt den aktuelle Zug an
	* @param [int] spieler	gibt an, welcher Spieler an Zug ist
	*
	* \image html GUI_zeichneSpielfeld.png
	* @startuml {GUI_zeichneSpielfeld.png}
	* start
	* :Bereinigen der Komandozeile;
	* :Ausgabe der Spielparameter;
	* :Ausgabe der Spalten;
	* while (Z�hler < 7) is (Z�hler <-- Z�hler + 1)
	* :Ausgabe Zeile & Leerzeile;
	* while (Z�hler1 < 7) is (Z�hler1 <-- Z�hler + 1)
	* :Ausgabe "Leerzeichen";
	* if (Feld besetzt) then (ja)
	* if (Farbe)then (wei�)
	* if (gefangen) then (ja)
	* :Ausgabe "G";
	* else (nein)
	* if (K�nig) then (ja)
	* :Ausgabe "K";
	* else (nein)
	* :Ausgabe "H";
	* endif
	* endif
	* else (schwarz)
	* if (gefangen) then (ja)
	* :Ausgabe "g";
	* else (nein)
	* if (K�nig) then (ja)
	* :Ausgabe "k";
	* else (nein)
	* :Ausgabe "h";
	* endif
	* endif
	* endif
	* :Ausgabe "Leerzeichen";
	* else (nein)
	* :Ausgabe "Leerzeichen";
	* endif
	* endwhile
	* :Ausgabe Leerzeile;
	* endwhile
	* :Ausgabe Legende;
	* stop
	* @enduml
	*/

	void zeichneAnleitung();
	/**zeichenAnleitung()
	 * Diese Funktion gibt dem Benutzer Auskunft �ber die Spielregeln.
	 *
	 * \image html GUI_zeichneAnleitung.png
	 * @startuml {GUI_zeichneAnleitung.png}
	 * start
	 * :Ausgabe Spielbeschreibung;
	 * stop
	 * @enduml
	 *
	 */
	void zeichneZug(int zug,int spieler,int zeile,int spalte);
	/**zeichneZug(zug,spieler,zeile,spalte)
	 * Mit dieser Funktion wird dem Spieler alle zul�ssigen Z�ge des ausgew�hlten Steins angezeigt.
	 *
	 * @param 	[int] 	zug			gibt den aktuellen Zug an
	 * @param	[int]	spieler		gibt an, welcher Spieler gerade am Zug ist
	 * @param	[int]	zeile		Zeile des ausgew�hlten Steins
	 * @param	[int]	spalte		Spalte des ausgew�hlten Steins
	 *
	 * \image html GUI_zeichneZug.png
	 * @startuml {GUI_zeichneZug.png}
	 * start
	 * :Bereinigen der Komandozeile;
	 * :Ausgabe der Spielparameter;
	 * :Ausgabe der Spalten;
	 * while (Z�hler < 7) is (Z�hler <-- Z�hler + 1)
	 * :Ausgabe Zeile & Leerzeile;
	 * while (Z�hler1 < 7) is (Z�hler1 <-- Z�hler + 1)
	 * :Ausgabe "Leerzeichen";
	 * if (Feld besetzt) then (ja)
	 * if (Zug M�glichkeit) then (ja)
	 * :Ausgabe "X";
	 * else (no)
	 * if (Farbe)then (wei�)
	 * if (gefangen) then (ja)
	 * :Ausgabe "G";
	 * else (nein)
	 * if (K�nig) then (ja)
	 * :Ausgabe "K";
	 * else (nein)
	 * :Ausgabe "H";
	 * endif
	 * endif
	 * else (schwarz)
	 * if (gefangen) then (ja)
	 * :Ausgabe "g";
	 * else (nein)
	 * if (K�nig) then (ja)
	 * :Ausgabe "k";
	 * else (nein)
	 * :Ausgabe "h";
	 * endif
	 * endif
	 * endif
	 * endif
	 * :Ausgabe "Leerzeichen";
	 * else (nein)
	 * if (Zug M�glichkeit) then (ja)
	 * :Ausgabe "x";
	 * else (nein)
	 * :Ausgabe "Leerzeichen";
	 * endif
	 * endif
	 * endwhile
	 * :Ausgabe Leerzeile;
	 * endwhile
	 * :Ausgabe Legende;
	 * stop
	 * @enduml
	 */
	void Spieler(bool farbe,int zug,int spieler);
	/**Spieler (farbe,zug,spieler)
	 * Mit dieser Funktion werden alle Informationen von einem Benutzer gesammelt, die f�r den n�chsten Zug
	 * ben�tigt werden. Dies umfasst die Auswahl eines Steins und dessen Zielfeldes. Hierzu wird der Benutzer
	 * durch ein Men� gef�hrt, das auch falsch Eingabe abfangen soll.	 *
	 *
	 * @param	[bool]	farbe		Farbe des aktiven Spielers
	 * @param	[int] 	zug			gibt den akuellen Zug an
	 * @param	[int]	spieler		gibt an welcher Spieler gerade am Zug ist
	 *
	 * \image html GUI_Spieler.png
	 *@startuml {GUI_Spieler.png}
	 * start
	 * while (neues Feld) is (kein Abbruch)
	 * while (Stein) is (kein Abbruch)
	 * :Eingabe <-- Auswahl Stein;
	 * if (Auswahl) then ("0A")
	 * :spalte <-- 0;
	 * :zeile  <-- 0;
	 * :abbruch <-- true;
	 * elseif (Auswahl) then ("0B")
	 * :spalte <-- 1;
	 * :zeile  <-- 0;
	 * :abbruch <-- true;
	 * elseif (...) then (...)
	 * endif
	 * if (Zug erlaubt) then ("ja")
	 * else (nein)
	 * :abbruch <-- false;
	 * endif
	 * endwhile (Abbruch)
	 * :Eingabe <-- neues Feld;
	 * if (Auswahl) then ("0A")
	 * :spalte <-- 0;
	 * :zeile  <-- 0;
	 * :abbruch <-- true;
	 * elseif (Auswahl) then ("0B")
	 * :spalte <-- 1;
	 * :zeile  <-- 0;
	 * :abbruch <-- true;
	 * elseif (...) then (...)
	 * endif
	 * if (Zug erlaubt) then ("ja")
	 * else (nein)
	 * :abbruch <-- false;
	 * endif
	 * endwhile (Abbruch)
	 * :Zug durchf�hren;
	 * stop
	 * @enduml
	 *
	 */
};

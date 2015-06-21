#include "SpielBrett.h"
#include "../h/KI.h"
/**
 * class GUI
 * Die Abkürzung GUI steht für graphical user interface bzw. grafische Benutzeroberfläche.
 * Durch diese Klasse wird dem Benutzer eine grafische Oberfläche zur Verfügung gestellt, über die er mit dem Programm interagierien kann.
 * Alle Benutzereingaben erfolgen ausschließlich über die Tastatur. Unterstützend wird die Strucktur der erwarteten Eingabe in Klammern
 * mit angegeben. Sollte dennoch der Benutzer eine Falsch Eingabe tätigen, so wird er darauf hingewiesen und kann seine Eingabe nach 3 Sekunken wiederholen.
 * Die Darstellung des Spielfeldes und wichtiger Spielparameter erfolgt in der Windows Konsole über ANSI-Zeichen.
 */
class GUI
{
private:
SpielBrett *brett;
KI *KIsw;
public:
	GUI(SpielBrett *br, KI *ki);
	/**GUI
	* Diese Funktion ist ein Konstructor für eine Instanz von der Klasse Spielbrett.
	*
	*/

	void zeichneSpielfeld(int zug,int spieler);
	/**zeichneSpielfeld(zug,spieler)
	* Mit dieser Funktion wird das Spielfeld grafisch für den Spieler aufbereitet.
	* @param [int] zug		gibt den aktuelle Zug an
	* @param [int] spieler	gibt an, welcher Spieler an Zug ist
	*
	* \image html GUI_zeichneSpielfeld.png
	* @startuml {GUI_zeichneSpielfeld.png}
	* start
	* :Bereinigen der Komandozeile;
	* :Ausgabe der Spielparameter;
	* :Ausgabe der Spalten;
	* while (Zähler < 7) is (Zähler <-- Zähler + 1)
	* :Ausgabe Zeile & Leerzeile;
	* while (Zähler1 < 7) is (Zähler1 <-- Zähler + 1)
	* :Ausgabe "Leerzeichen";
	* if (Feld besetzt) then (ja)
	* if (Farbe)then (weiß)
	* if (gefangen) then (ja)
	* :Ausgabe "G";
	* else (nein)
	* if (König) then (ja)
	* :Ausgabe "K";
	* else (nein)
	* :Ausgabe "H";
	* endif
	* endif
	* else (schwarz)
	* if (gefangen) then (ja)
	* :Ausgabe "g";
	* else (nein)
	* if (König) then (ja)
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
	 * Diese Funktion gibt dem Benutzer Auskunft über die Spielregeln.
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
	 * Mit dieser Funktion wird dem Spieler alle zulässigen Züge des ausgewählten Steins angezeigt.
	 *
	 * @param 	[int] 	zug			gibt den aktuellen Zug an
	 * @param	[int]	spieler		gibt an, welcher Spieler gerade am Zug ist
	 * @param	[int]	zeile		Zeile des ausgewählten Steins
	 * @param	[int]	spalte		Spalte des ausgewählten Steins
	 *
	 * \image html GUI_zeichneZug.png
	 * @startuml {GUI_zeichneZug.png}
	 * start
	 * :Bereinigen der Komandozeile;
	 * :Ausgabe der Spielparameter;
	 * :Ausgabe der Spalten;
	 * while (Zähler < 7) is (Zähler <-- Zähler + 1)
	 * :Ausgabe Zeile & Leerzeile;
	 * while (Zähler1 < 7) is (Zähler1 <-- Zähler + 1)
	 * :Ausgabe "Leerzeichen";
	 * if (Feld besetzt) then (ja)
	 * if (Zug Möglichkeit) then (ja)
	 * :Ausgabe "X";
	 * else (no)
	 * if (Farbe)then (weiß)
	 * if (gefangen) then (ja)
	 * :Ausgabe "G";
	 * else (nein)
	 * if (König) then (ja)
	 * :Ausgabe "K";
	 * else (nein)
	 * :Ausgabe "H";
	 * endif
	 * endif
	 * else (schwarz)
	 * if (gefangen) then (ja)
	 * :Ausgabe "g";
	 * else (nein)
	 * if (König) then (ja)
	 * :Ausgabe "k";
	 * else (nein)
	 * :Ausgabe "h";
	 * endif
	 * endif
	 * endif
	 * endif
	 * :Ausgabe "Leerzeichen";
	 * else (nein)
	 * if (Zug Möglichkeit) then (ja)
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
	 * Mit dieser Funktion werden alle Informationen von einem Benutzer gesammelt, die für den nächsten Zug
	 * benötigt werden. Dies umfasst die Auswahl eines Steins und dessen Zielfeldes. Hierzu wird der Benutzer
	 * durch ein Menü geführt, das auch falsch Eingabe abfangen soll.	 *
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
	 * :Zug durchführen;
	 * stop
	 * @enduml
	 *
	 */
};

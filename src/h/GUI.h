/*  GUI.cpp

 *	
 *	Diese Klasse stellt die Grafische Ausgabe bereit.
 * 	Man unterscheidet zwischen 4 verschiedenen Ausgaben
 *		1. Spielanleitung
 *		2. Spielbrett
 *		3. Gewonnen
 *		4. Verloren
 *
 *  @Created on: 26.04.2015;
 *  @Author: Martin Bauer
 */
#include "SpielBrett.h"
class GUI{
private:
SpielBrett *brett;
public:
	GUI(SpielBrett *brett);
	void zeichneSpielfeld(int,int);
	void zeichneAnleitung();
	void zeichneZug();
	void Spieler();
	void Computer();
};

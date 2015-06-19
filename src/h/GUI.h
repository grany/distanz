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
#include "../h/KI.h"
class GUI{
private:
SpielBrett *brett;
KI *KIsw;
public:
	GUI(SpielBrett *br, KI *ki);
	/*
	* Diese Funktion ist ein Constructor für eine Instanz von der Klasse Spielbrett.
	*
	*/

	void zeichneSpielfeld(int,int);
	/*
	* Mit dieser Funktion wird das Spielfeld grafisch für den Spieler aufbereitet.
	*
	*/

	void zeichneAnleitung();
	void zeichneZug(int,int,int,int);
	void Spieler(bool,int,int);
};

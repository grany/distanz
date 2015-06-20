
#ifndef SPIELBRETT_H
#define SPIELBRETT_H

/**
  * class SpielBrett
  * 	Das Spielfeld besteht aus einem 8x8 großen Feld. Jedes der 64 Felder besitzt eine eigene ID, welche
	bei Bewegungen und oder Besetzung abgefragt wird. Mithilfe von Pointern werden die Spielfiguren, je 
	nach Spielzug, auf die Felder verwiesen. Die 2 Teams (Schwarz & Weiß) stehen sich auf dem Spielfeld 	
	gegenueber. Damit sind, egal zu welchem Zeitpunkt des Spielverlaufs, immer insgesamt 8 Figuren und 	
	damit 4 pro Team auf dem Feld.
  */

#include "Feld.h"
#include "Team.h"
class Team;

class SpielBrett
{
private:
	static const short int dimmension = 8;	//Dimension
	Feld** Brett=nullptr;
	Team *schwarz=nullptr, *weis=nullptr;	//weiß

	void initBrett();
public:

  SpielBrett ();
  SpielBrett (const SpielBrett &sb);
  ~SpielBrett ( );
  Team* getWeis() const;			//Weiß (Wenn erforderlich auf Groß/-Kleinschreibung achten von Initialisierungen)
  Team* getSchwarz() const;
  Feld* getFeld(int x, int y) const;

};

#endif // SPIELBRETT_H

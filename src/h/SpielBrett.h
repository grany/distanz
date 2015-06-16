
#ifndef SPIELBRETT_H
#define SPIELBRETT_H

/**
  * class SpielBrett
  * Bildet ein 8x8 Spielbrett (Schachbrett) ab.
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

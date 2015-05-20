
#ifndef SPIELBRETT_H
#define SPIELBRETT_H

/**
  * class SpielBrett
  * Bildet ein 8x8 Spielbrett (Schachbrett) ab
  */

#include "Feld.h"
#include "Team.h"
class Team;

class SpielBrett
{
private:
	static const short int dimmension = 8;
	Feld** Brett=nullptr;
	Team *schwarz=nullptr, *weis=nullptr;

	void initBrett();
public:

  SpielBrett ();
  SpielBrett (const SpielBrett &sb);
  ~SpielBrett ( );
  Team* getWeis() const;
  Team* getSchwarz() const;
  Feld* getFeld(int x, int y) const;

};

#endif // SPIELBRETT_H

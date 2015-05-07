
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
	Feld** Brett;
	Team *schwarz, *weis;

	void initBrett();
public:

  SpielBrett ();
  ~SpielBrett ( );
  Team* getWeis();
  Team* getSchwarz();
  Feld* getFeld(int x, int y);

};

#endif // SPIELBRETT_H

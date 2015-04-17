
#ifndef SPIELBRETT_H
#define SPIELBRETT_H

#include "head.h"
/**
  * class SpielBrett
  * Bildet ein 8x8 Spielbrett (Schachbrett) ab
  */

class Feld;
class Team;

class SpielBrett
{
private:
	Feld *Brett;
	Team *schwarz, *weis;

public:

  SpielBrett ( );

};

#endif // SPIELBRETT_H

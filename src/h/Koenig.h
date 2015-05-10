
#ifndef KOENIG_H //
#define KOENIG_H //

/**
  * class Koenig
  *
  */
#include "Stein.h"
class Team;
class Feld;

class Koenig : public Stein
{
public:

	Koenig();
	Koenig(int id, Feld *startplatz, Team *mt);
  /**
   * Implementiert zusetzlich die Befreiung von Team-Mitglidern
   * @param  helfer
   */
  bool ziehenach (Feld *ziehe );

  /**
   * Verloren!!!
   */
  void setGeffangen ( );

};

#endif // KOENIG_H

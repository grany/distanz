
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
   * Implementiert zusaetzlich die Befreiung von Team-Mitgliedern.
   * @param  helfer
   */
  virtual bool ziehenach (Feld *ziehe ) override;

  /**
   * Verloren!!!
   */
  virtual void setGeffangen ( ) override;	//Gefangen

};

#endif // KOENIG_H


#ifndef KOENIG_H //
#define KOENIG_H //
#include "head.h"
/**
  * class Koenig
  * 
  */

class Koenig : public Stein
{
public:

	Koenig(Feld *startplatz, Team *mt);
  /**
   * Implementiert zusetzlich die Befreiung von Team-Mitglidern
   * @param  helfer
   */
  void zihenach (Feld *ziehe );

  /**
   * Verloren!!!
   */
  void setGeffangen ( );

};

#endif // KOENIG_H

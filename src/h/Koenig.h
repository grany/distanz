
#ifndef KOENIG_H //
#define KOENIG_H //

/**
  * class Koenig
  * 
  * 	Der Koenig ist eine von zwei Varianten der Spielsteine. Er besitzt eine Vererbung des Helfers bezueglich
	seiner Grundfunktionen. Er kann eigene festgesetzte Helfer befreien, kann sich auf dem Spielfeld 	
	bewegen, jedoch ist er, anders als der Helfer, die Siegbedingung. Wird der Koenig eines Teams 	
	festgesetzt, beziehungsweise gefangen, dann hat dieses Team verloren. Der Koenig ist somit die 	
	Spielentscheidende Komponente.
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


#ifndef KOENIG_H //
#define KOENIG_H //

/**
  * class K�nig
  * 
  * Der K�nig ist eine von zwei Varianten der Spielsteine. Er besitzt eine Vererbung des Helfers bez�glich
	seiner Grundfunktionen. Er kann eigene festgesetzte Helfer befreien, kann sich auf dem Spielfeld 	
	bewegen, jedoch ist er, anders als der Helfer, die Sieg-Bedingung. Wird der K�nig eines Teams
	festgesetzt, beziehungsweise gefangen, dann hat dieses Team verloren. Der K�nig ist somit die
	spielentscheidende Komponente.
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
   * Implementiert den Startplatz des K�nigs.
   *
   */
  virtual bool ziehenach (Feld *ziehe ) override;

  /**ziehenach(Feld)
   * Mit dieser Methode hat der K�nig die M�glichkeit seine Helfer zu befreien und sich auf
   * dem Spielfeld zu bewegen.
   *
   *@param  [Feld] *ziehe 	hierbei handelt sich um einen Pointer auf das Feld, das er springen soll
   *
   * \image html Koenig_ziehenach.png
	* @startuml {Koenig_ziehenach.png}
   * start
   * if (Ziel Feld besetzt) then (ja)
   * if (geh�rt der Stein zum Team) then (ja)
   * :tausche beide Positionen;
   * else (nein)
   * :setze den Gegner gefangen;
   * :tausche beide Positionen;
   * endif
   * else (nein)
   * :ziehe auf das neue Feld;
   * endif
   * end
   * stop
	*@enduml
   */
  virtual void setGeffangen ( ) override;
  /**setGefangen()
   * Diese Methode bewirkt, dass sobald ein K�nig gefangen wird, das Spiel verloren ist.
   */
};

#endif // KOENIG_H

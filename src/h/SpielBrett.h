
#ifndef SPIELBRETT_H
#define SPIELBRETT_H

/**
  * class SpielBrett
  * 	Das Spielfeld besteht aus einem 8x8 gro�en Feld. Jedes der 64 Felder besitzt eine eigene ID, welche
	bei Bewegungen und oder Besetzung abgefragt wird. Mithilfe von Pointern werden die Spielfiguren, je 
	nach Spielzug, auf die Felder verwiesen. Die 2 Teams (Schwarz & Wei�) stehen sich auf dem Spielfeld
	gegen�ber. Damit sind, egal zu welchem Zeitpunkt des Spielverlaufs, immer insgesamt 8 Figuren und
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
	 /** initBrett()
	   * Erzeugt das 8x8 gro�es Feld.
	   *
	   */

public:

  SpielBrett ();
  /** SpielBrett()
    * Beinhaltet die Startaufstellung.
    *
    */

  SpielBrett (const SpielBrett &sb);
  /** SpielBrett (const SpielBrett &sb)
    * Verwei�t auf die Pointer, der einzelnen Spielsteine.
    *
    */

  ~SpielBrett ( );
  /** ~SpielBrett
    * Destruktor des Spiels
    *
    */

  Team* getWeis() const;			//Weiß (Wenn erforderlich auf Groß/-Kleinschreibung achten von Initialisierungen)
  /** getWeis()
    * Kennzeichnet die wei�en Steine.
    *
    * @return wei�
    */

  Team* getSchwarz() const;
  /**getSchwarz()
   * Kennzeichnet die schwarzen Steine.
   *
   * @return schwarz
   */
  Feld* getFeld(int x, int y) const;
  /** getFeld(int x, int y)
    * verhindert, falsche Angaben der Positionen.
    *
    *@param [int]	x, y	Koordinaten des Feldes
    *@return nullptr
    */

};

#endif // SPIELBRETT_H

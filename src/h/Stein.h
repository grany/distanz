#include "head.h"

#ifndef STEIN_H
#define STEIN_H




/**
  * class Stein
  * 
  */
class Stein;
class Team;

class Stein
{
protected:
	bool geffangen;
	Feld *ort;
	Team *mteam;
public:

  /**
   * Constructor
   */
  Stein();
  Stein (Feld *startplatz, Team *mt);

  /**
   * Setzt den Stein Geffangen
   * geffangen -> true
   */
 virtual void setGeffangen ( );

  /*
   * Setzt den Stein frei
   * Setzt geffangen -> false
   */
  void setFrei();

  /**
   * Rückt auf das Übergebene Feld
   */
  virtual void zihenach(Feld *ziehl);

  /**
   * Get the value of geffangen
   * @return the value of geffangen
   */
  bool getGeffangen ( );


  Team* getMteam();
  Feld* getOrt();


  /**
   * Gibt ein Array von ereichbaren Feldern zurück
   * @return Feld
   */
  Feld* zuege ( );
  virtual ~Stein();

};

#endif // STEIN_H

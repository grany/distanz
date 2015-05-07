#ifndef STEIN_H
#define STEIN_H

#include <vector>
class Team;
class Feld;
/**
  * class Stein
  * 
  */
class Stein;

class Stein
{
protected:
	bool geffangen;
	Feld *ort;
	Team *mteam;
	const int id;
public:

  /**
   * Constructor
   */
  Stein (int id, Feld *startplatz, Team *mt);

  int getid();
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
  std::vector<Feld*> zuege ( );
  virtual ~Stein();

};

#endif // STEIN_H

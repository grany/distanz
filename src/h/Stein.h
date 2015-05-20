#ifndef STEIN_H
#define STEIN_H

#include <vector>
class Team;
class Feld;
/**
  * class Stein
  * 
  */

class Stein
{
protected:
	bool geffangen=false;
	Feld *ort=nullptr;
	Team *mteam=nullptr;
	const int id;
public:

  /**
   * Constructor
   */
	Stein();
  Stein (int id, Feld *startplatz, Team *mt);

  /*
   * getid()
   * @return id der instanz
   */
  int getid() const;

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
   * Rückt auf das übergebene Feld
   */
  virtual bool ziehenach(Feld *ziehl);
  void setOrt(Feld* o);

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
  virtual ~Stein()=default;

};

#endif // STEIN_H

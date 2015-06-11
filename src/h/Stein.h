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
	bool geffangen=false;			//gefangen
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
   * @return id der Instanz
   */
  int getid() const;

  /**
   * Setzt den Stein Gefangen.
   * gefangen -> true
   */
 virtual void setGeffangen ( );		//gefangen

  /*
   * Setzt den Stein frei
   * Setzt gefangen -> false
   */
  void setFrei();

  /**
   * Rückt auf das übergebene Feld.
   */
  virtual bool ziehenach(Feld *ziehl);		//ziehl? :s
  void setOrt(Feld* o);

  /**
   * Get the value of gefangen
   * @return the value of gefangen
   */
  bool getGeffangen ( );		//gefangen


  Team* getMteam();
  Feld* getOrt();


  /**
   * Gibt ein Array von erreichbaren Feldern zurück
   * @return Feld
   */
  std::vector<Feld*> zuege ( );
  virtual ~Stein()=default;

};

#endif // STEIN_H

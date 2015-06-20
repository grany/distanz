#ifndef STEIN_H
#define STEIN_H

#include <vector>
class Team;
class Feld;
/**
  * class Stein
  * 
  * Jedes Team besitzt drei Helfer. Sie können sich auf dem Spielfeld bewegen, festgesetzt (gefangen) 	
  * werden, gegnerische Spielfiguren festsetzen, indem man sie ganz einfach auf das vom Gegner besetzte 	
  * Feld schickt und in Verbindung mit dem teameigenen König können sie auch selber befreit werden, 	
  * sollte der Gegner sie gefangen genommen haben. Jede Spielfigur und damit auch jeder Helfer, bekommt 	
  * bei Spielbeginn einen Platz mittels Pointern zugewiesen. Die Spielfigur-ID und die Spielfeld-ID bestimmen 	
  * also, welche Spielfigur von welchem Team sich wo im Feld befindet.
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
   * Rueckt auf das uebergebene Feld.
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
   * Gibt ein Array von erreichbaren Feldern zurueck
   * @return Feld
   */
  std::vector<Feld*> zuege ( );
  virtual ~Stein()=default;

};

#endif // STEIN_H

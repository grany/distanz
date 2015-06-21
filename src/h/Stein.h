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
  * Feld schickt und in Verbindung mit dem teameigenen KÃ¶nig kÃ¶nnen sie auch selber befreit werden, 	
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
   * Konstruktor
   */
	Stein();
  Stein (int id, Feld *startplatz, Team *mt);

  /**getid()
   * getid()
   * Diese Funktion sagt aus, ob es sich hierbei um weiß oder schwarz handelt.
   * @return id der Instanz
   */
  int getid() const;

  /**setGefangen()
   * Setzt den Stein gefangen.
   * gefangen -> true
   */
 virtual void setGeffangen ( );		//gefangen

  /**setFrei()
   * Setzt den Stein frei
   * Setzt gefangen -> false
   */
  void setFrei();

  /**setOrt
   * Rückt auf das übergebene Feld.
   * @param [Feld]	gibt die neue Position an
   */
  virtual bool ziehenach(Feld *ziehl);		//ziehl? :s
  void setOrt(Feld* o);

  /**getGeffangen()
   * Die Funktion beschreibt, ob der Stein gefangen ist oder nicht.
   * @return the value of gefangen
   */
  bool getGeffangen ( );		//gefangen


  Team* getMteam();
  Feld* getOrt();


  /**zuege()
   * Die Funktion Zuege ermittelt alle möglichen Züge und gibt diese als Vector zurück.
   * @return Feld	zue
   */
  std::vector<Feld*> zuege ( );
  virtual ~Stein()=default;

};

#endif // STEIN_H

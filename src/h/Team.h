#ifndef TEAM_H
#define TEAM_H


/**
  * class Team
  * ######################################################################################
  * In diesem programmierten Spiel sind zwei Teams erlaubt. Die jeweiligen Zuege eines Teams uebernimmt 	
  * der Spieler/Anwender, das andere Team ist computergesteuert (KI). Die Teams (schwarz & weiß) 	
  * werden zu Spielbeginn generiert. Der Team ID werden Spielfigur-ID zugewiesen, um zu gewaehrleisten, 	
  * dass sie steuerbar sind und sie die Funktionen im Spielablauf anwenden können. Die Teams wechseln 	
  * sich nach jedem Zug ab. Es besteht Zugzwang.
  * ######################################################################################
  */
#include <vector>
#include "Feld.h"
#include "SpielBrett.h"

class Stein;
class Koenig;
class Team;
class SpielBrett;


/**
 * class Team
 *
 */
class Team
{
private:
  Stein *helfer1=nullptr, *helfer2=nullptr, *helfer3=nullptr;
  Koenig *koenig=nullptr;
  bool Sieg=false;
  Team *gegner=nullptr;
  SpielBrett *brett=nullptr;
  bool Farbe=false;	//Weiß->true; false->Schwarz
public:
  /**
    * Erzeugt Team.
    */
   Team (SpielBrett *br, bool f, Feld *s1, Feld *s2, Feld *s3, Feld *k, Team *g );
   Team ()=default;
   virtual ~Team ( );

    /**
    * distanzen()
    * Tr�gt x und y Distanzen der "Anderen" Steine in einem Array ein.
    * Array muss 6 Felder besitzen und vom Typ Integer sein.
    *
    * @param [in] &anfrage : Stein, [out] *arr : int array[6]
    */
   void distanzen (const Stein &anfrage, int *arr );
   /**
    * getStein
    * Gibt Referenz auf Stein mit �bergebener ID zur�ck, bei falschen ID�s wird Referenz auf Koenig zur�ckgegeben.
    * 1-3 -> Helfer
    * 4 -> Koenig
    * @param [in] id : int
    * @return &Stein
    */
   Stein& getStein(int id) const;

  /**
   * Set the value of Sieg
   * @param new_var the new value of Sieg
   */
  void setSieg ( bool new_var );
  /**
   * Setze Gegnerisches Team
   */
  void setGegner ( Team *new_var );
  /**
   * Gibt Pointer auf Gegnerisches Team aus.
   */
  Team* getGegner () const;
  bool getFarbe() const;
  bool getSieg();

  SpielBrett* getBrett() const;
};

#endif // TEAM_H

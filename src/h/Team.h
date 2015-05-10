#ifndef TEAM_H
#define TEAM_H


/**
  * class Team
  * 
  */
#include <vector>
#include "Feld.h"
#include "SpielBrett.h"

class Stein;
class Koenig;
class Team;
class SpielBrett;



class Team
{
private:
  Stein *helfer1, *helfer2, *helfer3;
  Koenig *koenig;
  bool Sieg;
  Team *gegner;
  SpielBrett *brett;
  bool Farbe;	//Weis->true; false->Schwarz
public:
  /**
    * Erzeugt Team
    */
   Team (SpielBrett *br, bool f, Feld *s1, Feld *s2, Feld *s3, Feld *k, Team *g );
   Team ();
   /**
    * Zerstört Team
    */
   ~Team ( );

    /**
    * Gibt einen Vector mit den distanzen der anderen,
    *  nicht gefangenen, Team-Mitglieder zurück
    * @return vector
    * @param  anfrage
    */
   void distanzen (const Stein &anfrage, int *arr );
   Stein& getStein(int id) const;

  /**
   * Set the value of Sieg
   * @param new_var the new value of Sieg
   */
  void setSieg ( bool new_var );
  /*
   * Setze Gegnerisches Team
   */
  void setGegner ( Team *new_var );
  /*
   * Gibt Pointer auf Gegnerisches Team Aus
   */
  Team* getGegner () const;

  SpielBrett* getBrett() const;
};

#endif // TEAM_H

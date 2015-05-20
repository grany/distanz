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
  Stein *helfer1=nullptr, *helfer2=nullptr, *helfer3=nullptr;
  Koenig *koenig=nullptr;
  bool Sieg=false;
  Team *gegner=nullptr;
  SpielBrett *brett=nullptr;
  bool Farbe=false;	//Weis->true; false->Schwarz
public:
  /**
    * Erzeugt Team
    */
   Team (SpielBrett *br, bool f, Feld *s1, Feld *s2, Feld *s3, Feld *k, Team *g );
   Team ()=default;
   /**
    * Zerstört Team
    */
   ~Team ( );

    /**
    * Gibt einen Vector mit den distanzen der anderen,
    *  nicht gefangenen, Team-Mitglieder zurÃ¼ck
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
  bool getFarbe() const;
  bool getSieg();

  SpielBrett* getBrett() const;
};

#endif // TEAM_H

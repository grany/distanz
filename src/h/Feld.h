
#ifndef FELD_H
#define FELD_H

#include "head.h"

/**
  * class Feld
  * Stellt ein Feld auf einem Spielbrett dar
  */

class Stein;

class Feld
{
private:

  bool besetzt;
  Possition pos;
  Stein *gast;

public:
  /**
   * Initialisiert Feld
   */
  Feld(short int nx, short int ny);

  /**
   * Aufreumen
   */
  ~Feld ( );


  /**
   * Setzt Stein auf das Feld
   * und Markiert das Feld als Besetzt.
   * Fals das Feld besetzt ist werden die Gäste/Steine getauscht.
   */
  void setStein (Stein *stein );

  /**
   *Löscht Zeiger auf Gast
   *Setzt besetzt auf false
   */
  void delStein();


  /**
   * Get the value of besetzt
   * @return the value of besetzt
   */
  bool getBesetzt ( );

  /*
   * Gibt einen Pointer auf den Gast zurück
   */
  Stein* getGast();

  /**
   * Get the value of pos
   * @return the value of pos
   */
  Possition getPos ( );

};

#endif // FELD_H

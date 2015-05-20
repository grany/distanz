
#ifndef FELD_H
#define FELD_H

/**
  * class Feld
  * Stellt ein Feld auf einem Spielbrett dar
  */
#include "../h/Possition.h"
#include "Stein.h"

class Feld
{
private:

  bool besetzt;
  Possition pos;
  Stein *gast=nullptr;

public:
  /**
   * Initialisiert Feld
   */
  Feld();
  Feld(short nx, short  ny);
  Feld(Feld &f);
  /**
   * Setzt Stein auf das Feld
   * und Markiert das Feld als Besetzt.
   * Fals das Feld besetzt ist werden die Gäste/Steine getauscht.
   */
  void setStein (Stein *newstein );

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

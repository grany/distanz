
#ifndef FELD_H
#define FELD_H
#include "../h/Possition.h"
#include "Stein.h"
/**
 * class Feld
 * Symbolisiert ein Feld auf einem Spielbrett.
 */
class Feld
{
private:

  bool besetzt;
  Possition pos;  //Position
  Stein *gast=nullptr;

public:
  Feld();
  /**
   * Feld Konstruktor
   * @param [in] nx x Koordinaten des Feldes
   * @param [in] ny y Koordinaten des Feldes
   */
  Feld(short nx, short  ny);
  Feld(Feld &f);
  /**
   * Setzt Stein auf das Feld
   * und Markiert das Feld als Besetzt.
   * Falls das Feld besetzt ist, werden die Gäste/Steine getauscht.
   * @param [in/out] *newstein pointer auf den zu setzenden Stein.
   */
  void setStein (Stein *newstein );

  /**
   * delStein
   *Löscht Zeiger auf Gast.
   *Setzt besetzt auf false.
   */
  void delStein();


  /**
   * Get the value of besetzt.
   * @return the value of besetzt.
   */
  bool getBesetzt ( );

  /**
   * getGast
   *@return Gibt einen Pointer auf den Gast zurück.
   */
  Stein* getGast();

  /**
   * getPos
   * @return the value of pos.
   */
  Possition getPos ( );   //Position

};

#endif // FELD_H

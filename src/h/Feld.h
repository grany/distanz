
#ifndef FELD_H
#define FELD_H
#include "../h/Possition.h"
#include "Stein.h"
/**
 * class Feld
 * Symbolysiert ein Feld auf einem SpielBrett.
 */
class Feld
{
private:

  bool besetzt;
  Possition pos;
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
   * Fals das Feld besetzt ist werden die G�ste/Steine getauscht.
   * @param [in/out] *newstein pointer auf den zu Setzenden Stein.
   */
  void setStein (Stein *newstein );

  /**
   * delStein
   *L�scht Zeiger auf Gast
   *Setzt besetzt auf false
   */
  void delStein();


  /**
   * Get the value of besetzt
   * @return the value of besetzt
   */
  bool getBesetzt ( );

  /**
   * getGast
   *@return Gibt einen Pointer auf den Gast zur�ck
   */
  Stein* getGast();

  /**
   * getPos
   * @return the value of pos
   */
  Possition getPos ( );

};

#endif // FELD_H

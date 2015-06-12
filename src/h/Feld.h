
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
   * Falls das Feld besetzt ist, werden die GÃ¤ste/Steine getauscht.
   * @param [in/out] *newstein pointer auf den zu setzenden Stein.
   * \image html Feld_setStein_flow.png
   * @startuml{Feld_setStein_flow.png}
   * start
   * if (Feld besetzt?) then (ja)
   * 	:im alten Gast Ort auf Feld vom neuen Stein setzen;
   * 	:im alten Feld Gäste löschen;
   * 	:im alten Feld Gast auf alten Gast setzen;
   * 	:im Feld Gast auf neuen Stein setzen;
   * 	:im neuen Stein Ort auf Feld setzen;
   * else (nein)
   * 	:im Feld Gast auf neuen Stein setzen;
   * 	:im alten Feld Gast auf nullptr setzen;
   * endif
   * stop
   *
   * @enduml
   */
  void setStein (Stein *newstein );

  /**
   * delStein
   * Löscht Zeiger auf Gast
   * Setzt besetzt auf false
   * \image html Feld_delStein_flow.png
   * @startuml{Feld_delStein_flow.png}
   * start
   * :setze Gast auf nullptr;
   * :setze besetzt auf false;
   * stop
   * @enduml
   */
  void delStein();


  /**
   * Get the value of besetzt.
   * @return the value of besetzt.
   */
  bool getBesetzt ( );

  /**
   * getGast
   *@return Gibt einen Pointer auf den Gast zurÃ¼ck.
   */
  Stein* getGast();

  /**
   * getPos
   * @return the value of pos.
   */
  Possition getPos ( );   //Position

};

#endif // FELD_H

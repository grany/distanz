/**main()
 * In der Main-Funktion wird der Spielablauf gesteuert und damit auch der Benutzer durch das
 * Spiel geführt.
 *
 * \image html main.png
 * @startuml{main.png}
 * start
 * :Zeige Anleitung;
 * while (abbruch) is (false)
 * :Ausgabe --> Welcher Modus;
 * :Eingabe <-- auswahl;
 * if (entspricht auswahl der Vorgabe) then (ja)
 * :abbruch <--true;
 * else (nein)
 * :Ausgabe --> Falsche Eingabe;
 * endif
 * endwhile
 * if (auswahl = 1) then (ja)
 * :spieler1 <-- Mensch;
 * :spieler2 <-- Computer;
 * elseif (auswahl = 2) then (ja)
 * :spieler1 <-- Mensch;
 * :spieler2 <-- Mensch;
 * elseif (auswahl = 3) then (ja)
 * :spieler1 <-- Computer;
 * :spieler2 <-- Computer;
 * endif
 * while (abbruch) is (false)
 * if (zug MOD 2) then (mit Rest)
 * if (spieler1 = Mensch) then (ja)
 * :GUI::Spieler;
 * else (nein)
 * :KI::nexZug;
 * :GUI::zeichneSpielfeld;
 * :warte 5 sec;
 * endif
 * else (ohne Rest)
 * if (spieler2 = Mensch) then (ja)
 * :GUI::Spieler;
 * else (nein)
 * :KI::nexZug;
 * :GUI::zeichneSpielfeld;
 * :warte 5 sec;
 * endif
 * endif
 * if (spieler gewonnen) then (ja)
 * :Ausgabe --> gewonnen;
 * :abbruch <-- true;
 * else (nein)
 * endif
 * endwhile
 * stop
  * @enduml
 */

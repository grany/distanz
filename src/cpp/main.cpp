#include <windows.h>
#include <iostream>
#include <memory>
#include "../h/Spielbrett.h"
#include <stdlib.h>
#include "../h/KI.h"
#include "../h/GUI.h"
#include "../h/Stein.h"
using namespace std;


int main(int _argc, char *argv[])
{
	bool abbruch, spieler1, spieler2, spielabbruch;
	int auswahl, zug;


	unique_ptr<SpielBrett>  br( new SpielBrett() );
	Team *ws = br->getWeis();
	Team *sw = br->getSchwarz();
	unique_ptr<KI> KIsw(new KI(*br->getSchwarz()));
	unique_ptr<KI> KIws(new KI(*br->getWeis()));
	GUI grafik(br.get(), KIsw.get());

	do
	{
		abbruch = false;
		spielabbruch = false;
		auswahl = 0;
		zug = 1;

		while (abbruch != true)
		{
			grafik.zeichneAnleitung();
			cout << "\n Bitte w\204hlen Sie einen Modus (1 - Singleplayer; 2 - Multiplayer; 3 - Zuschauer)";
			cin >> auswahl;
			if ((auswahl == 1) || (auswahl == 2) || (auswahl == 3))
			{abbruch = true;}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tIhre Auswahl ist nicht gültig!!";
				Sleep(3000);
			};
		};
		abbruch = false;
		cin.sync();
		switch (auswahl)
		{
			case 1:
				spieler1 = true;
				spieler2 = false;
				break;
			case 2:
				spieler1 = true;
				spieler2 = true;
				break;
			case 3:
				spieler1 = false;
				spieler2 = false;
				break;
		};
		while (abbruch != true)
		{
			system("cls");
			if (zug % 2)
			{
				if (spieler1 == true)
				{
					grafik.Spieler(false,zug,1);
				}
				else
				{
					KIws->nexZug();
					grafik.zeichneSpielfeld(zug,1);
					Sleep(5000);						//Zeitverzögerung
				}
				zug++;
			}
			else
			{
				if (spieler2 == true)
				{
					grafik.Spieler(true,zug,2);
				}
				else
				{
					KIsw->nexZug();
					grafik.zeichneSpielfeld(zug,2);
					Sleep(5000);						//Zeitverzögerung
				}
				zug++;
			}
			if (sw->getSieg())
			{
				cout << "Spieler 2 hat gewonnen!!!";
				abbruch = true;
			}
			if (ws->getSieg())
			{
				cout << "Spieler 1 hat gewonnen!!!";
				abbruch = true;
			}
		}

		abbruch = false;
		while (abbruch == false)
		{
			cout << "\n Soll das Spiel wiederholt werden? (1 - Ja/2 - Nein) ";
			cin  >>  auswahl;
			if (auswahl == 1)	{abbruch = true;};
		}

	} while (spielabbruch == false);
	return 1;
}



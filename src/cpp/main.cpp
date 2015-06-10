

#include <iostream>
#include <memory>
#include "../h/Spielbrett.h"
#include <stdlib.h>
#include "../h/KI.h"
#include "../h/KI1.h"
#include "../h/GUI.h"
using namespace std;


int main(int _argc, char *argv[]){

	bool abbruch = false, spieler1, spieler2;
	int auswahl=0, zug = 1;

	unique_ptr<SpielBrett>  br( new SpielBrett() );
	GUI grafik(br.get());
	Team *ws = br->getWeis();
	Team *sw = br->getSchwarz();
	//unique_ptr<KI> KIsw(new KI(br->getSchwarz()));
	//unique_ptr<KI> KIws(new KI(br->getWeis()));

	grafik.zeichneAnleitung();
	while (abbruch != true)
	{
		cout << "\nBitte wählen Sie den Modus (1 - 1 Spieler; 2 - 2 Spieler; 3 - Computer Spiel)";
		cin >> auswahl;
		if ((auswahl == 1) || (auswahl == 2) || (auswahl == 3)){abbruch = true;};
	};
	abbruch = false;
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
			//if (spieler1 == true)
				//grafik.Spieler;
			//else
				//grafik.Computer;
			grafik.zeichneSpielfeld(zug,2);
			zug++;
		}
		else
		{
		//	if (spieler2 == true)
				//grafik.Spieler;
			//else
				//grafik.Computer;
			grafik.zeichneSpielfeld(zug,1);
			zug++;
		}
		cin.get();
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
	return 1;
}



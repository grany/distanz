#include "../h/GUI.h"
#include <iostream>
#include <stdlib.h>
#include "../h/KI.h"
#include "../h/KI1.h"
#include "../h/Spielbrett.h"
#include "../h/Stein.h"


using namespace std;

GUI::GUI(SpielBrett *br, KI *ki)
{
	brett=br;
	KIsw=ki;
}

void GUI::zeichneZug(int zug,int spieler,int zeile,int spalte)
{
	int zaehler, zaehler1, zaehlerAuswahl = 0;
	std::vector<Feld*> moeglichkeit;


	system("cls");
	//if (brett->getFeld(zeile,spalte)->getBesetzt())
	{
		moeglichkeit = brett->getFeld(spalte,zeile)->getGast()->zuege();
		//zaehlerAuswahl = moeglichkeit.size();
		cout <<	"\n\n Es ist der: "
			 << zug
			 << " Zug"
			 << "\t\tEs spielt gerade: Spieler "
			 << spieler
			 << "\n__________________________________________________________________\n\n"
			 <<	"\n\n\t   A     B     C     D     E     F     G     H\n"
			 << "\t _____ _____ _____ _____ _____ _____ _____ _____\n";
		for (zaehler = 0; zaehler < 8; zaehler++)
		{
			cout << "\t|     |     |     |     |     |     |     |     |\n"
				 << "    "
				 << zaehler
				 << "\t|";
			for (zaehler1 = 0; zaehler1 < 8; zaehler1++)
			{
				cout << "  ";
				if (brett->getFeld(zaehler1,zaehler)->getBesetzt())
				{
					if (moeglichkeit[zaehlerAuswahl] == brett->getFeld(zaehler1,zaehler))
					{
						cout << "X";
						zaehlerAuswahl++;
					}
					else
					{
						if (brett->getFeld(zaehler1,zaehler)->getGast()->getMteam()->getFarbe())
							{
								if (brett->getFeld(zaehler1,zaehler)->getGast()->getGeffangen()) 	{cout << "G";}
								else if (brett->getFeld(zaehler1,zaehler)->getGast()->getid()==4) 	{cout << "K";}
								 	 else 	{cout << "H";}
							}
							else
							{
								if (brett->getFeld(zaehler1,zaehler)->getGast()->getGeffangen()) 	{cout << "g";}
								else if (brett->getFeld(zaehler1,zaehler)->getGast()->getid()==4) 	{cout << "k";}
								 	 else {cout << "h";}
							}
					}
				}
				else
					{
					if (moeglichkeit[zaehlerAuswahl] == brett->getFeld(zaehler1,zaehler))
					{
						cout << "x";
						zaehlerAuswahl++;
					}
					else cout << " ";
					}
				cout << "  |";
			}
		cout << "\n"
			 << "\t|_____|_____|_____|_____|_____|_____|_____|_____|\n";
		}
		cout << "\n\n\tH/h = Helfer wei\341/schwarz"
			 << "\n\tK/k = K\224nig wei\341/schwarz"
			<< "\n\tG/g = gefangener Helfer wei\341/schwarz"
			<< "X = springe auf einen gegnerischen Stein"
			<< "x = springe an diese Stelle"
			<< "\n\n__________________________________________________________________\n";
	}
	//else cout << "\nAn dieser Stelle befindet sich kein Stein!!";
}


void GUI::Spieler(bool farbe,int zug,int spieler)
{
	int zeile = 100, spalte = 100, zeile_neu = 100, spalte_neu = 100;
	string auswahl_stein = "", auswahl_feld = "";
while (zeile_neu > 7 || spalte_neu > 8)
{
	while (zeile > 7 || spalte > 8)
					{
						this->zeichneSpielfeld(zug,spieler);
						cout << "\n Welchen Stein m\224chten Sie bewegen? (Zeile,Spalte): ";
						auswahl_stein = "";
						cin	>> auswahl_stein;
						cin.sync();

						if (auswahl_stein == "0A" || auswahl_stein == "0a" || auswahl_stein == "0,A" || auswahl_stein == "0a") {zeile = 0; spalte = 0;};
						if (auswahl_stein == "0B" || auswahl_stein == "0b" || auswahl_stein == "0,B" || auswahl_stein == "0b") {zeile = 0; spalte = 1;};
						if (auswahl_stein == "0C" || auswahl_stein == "0c" || auswahl_stein == "0,C" || auswahl_stein == "0c") {zeile = 0; spalte = 2;};
						if (auswahl_stein == "0D" || auswahl_stein == "0d" || auswahl_stein == "0,D" || auswahl_stein == "0d") {zeile = 0; spalte = 3;};
						if (auswahl_stein == "0E" || auswahl_stein == "0e" || auswahl_stein == "0,E" || auswahl_stein == "0e") {zeile = 0; spalte = 4;};
						if (auswahl_stein == "0F" || auswahl_stein == "0f" || auswahl_stein == "0,F" || auswahl_stein == "0f") {zeile = 0; spalte = 5;};
						if (auswahl_stein == "0G" || auswahl_stein == "0g" || auswahl_stein == "0,G" || auswahl_stein == "0g") {zeile = 0; spalte = 6;};
						if (auswahl_stein == "0H" || auswahl_stein == "0h" || auswahl_stein == "0,H" || auswahl_stein == "0h") {zeile = 0; spalte = 7;};

						if (auswahl_stein == "1A" || auswahl_stein == "1a" || auswahl_stein == "1,A" || auswahl_stein == "1a") {zeile = 1; spalte = 0;};
						if (auswahl_stein == "1B" || auswahl_stein == "1b" || auswahl_stein == "1,B" || auswahl_stein == "1b") {zeile = 1; spalte = 1;};
						if (auswahl_stein == "1C" || auswahl_stein == "1c" || auswahl_stein == "1,C" || auswahl_stein == "1c") {zeile = 1; spalte = 2;};
						if (auswahl_stein == "1D" || auswahl_stein == "1d" || auswahl_stein == "1,D" || auswahl_stein == "1d") {zeile = 1; spalte = 3;};
						if (auswahl_stein == "1E" || auswahl_stein == "1e" || auswahl_stein == "1,E" || auswahl_stein == "1e") {zeile = 1; spalte = 4;};
						if (auswahl_stein == "1F" || auswahl_stein == "1f" || auswahl_stein == "1,F" || auswahl_stein == "1f") {zeile = 1; spalte = 5;};
						if (auswahl_stein == "1G" || auswahl_stein == "1g" || auswahl_stein == "1,G" || auswahl_stein == "1g") {zeile = 1; spalte = 6;};
						if (auswahl_stein == "1H" || auswahl_stein == "1h" || auswahl_stein == "1,H" || auswahl_stein == "1h") {zeile = 1; spalte = 7;};

						if (auswahl_stein == "2A" || auswahl_stein == "2a" || auswahl_stein == "2,A" || auswahl_stein == "2a") {zeile = 2; spalte = 0;};
						if (auswahl_stein == "2B" || auswahl_stein == "2b" || auswahl_stein == "2,B" || auswahl_stein == "2b") {zeile = 2; spalte = 1;};
						if (auswahl_stein == "2C" || auswahl_stein == "2c" || auswahl_stein == "2,C" || auswahl_stein == "2c") {zeile = 2; spalte = 2;};
						if (auswahl_stein == "2D" || auswahl_stein == "2d" || auswahl_stein == "2,D" || auswahl_stein == "2d") {zeile = 2; spalte = 3;};
						if (auswahl_stein == "2E" || auswahl_stein == "2e" || auswahl_stein == "2,E" || auswahl_stein == "2e") {zeile = 2; spalte = 4;};
						if (auswahl_stein == "2F" || auswahl_stein == "2f" || auswahl_stein == "2,F" || auswahl_stein == "2f") {zeile = 2; spalte = 5;};
						if (auswahl_stein == "2G" || auswahl_stein == "2g" || auswahl_stein == "2,G" || auswahl_stein == "2g") {zeile = 2; spalte = 6;};
						if (auswahl_stein == "2H" || auswahl_stein == "2h" || auswahl_stein == "2,H" || auswahl_stein == "2h") {zeile = 2; spalte = 7;};

						if (auswahl_stein == "3A" || auswahl_stein == "3a" || auswahl_stein == "3,A" || auswahl_stein == "3a") {zeile = 3; spalte = 0;};
						if (auswahl_stein == "3B" || auswahl_stein == "3b" || auswahl_stein == "3,B" || auswahl_stein == "3b") {zeile = 3; spalte = 1;};
						if (auswahl_stein == "3C" || auswahl_stein == "3c" || auswahl_stein == "3,C" || auswahl_stein == "3c") {zeile = 3; spalte = 2;};
						if (auswahl_stein == "3D" || auswahl_stein == "3d" || auswahl_stein == "3,D" || auswahl_stein == "3d") {zeile = 3; spalte = 3;};
						if (auswahl_stein == "3E" || auswahl_stein == "3e" || auswahl_stein == "3,E" || auswahl_stein == "3e") {zeile = 3; spalte = 4;};
						if (auswahl_stein == "3F" || auswahl_stein == "3f" || auswahl_stein == "3,F" || auswahl_stein == "3f") {zeile = 3; spalte = 5;};
						if (auswahl_stein == "3G" || auswahl_stein == "3g" || auswahl_stein == "3,G" || auswahl_stein == "3g") {zeile = 3; spalte = 6;};
						if (auswahl_stein == "3H" || auswahl_stein == "3h" || auswahl_stein == "3,H" || auswahl_stein == "3h") {zeile = 3; spalte = 7;};

						if (auswahl_stein == "4A" || auswahl_stein == "4a" || auswahl_stein == "4,A" || auswahl_stein == "4a") {zeile = 4; spalte = 0;};
						if (auswahl_stein == "4B" || auswahl_stein == "4b" || auswahl_stein == "4,B" || auswahl_stein == "4b") {zeile = 4; spalte = 1;};
						if (auswahl_stein == "4C" || auswahl_stein == "4c" || auswahl_stein == "4,C" || auswahl_stein == "4c") {zeile = 4; spalte = 2;};
						if (auswahl_stein == "4D" || auswahl_stein == "4d" || auswahl_stein == "4,D" || auswahl_stein == "4d") {zeile = 4; spalte = 3;};
						if (auswahl_stein == "4E" || auswahl_stein == "4e" || auswahl_stein == "4,E" || auswahl_stein == "4e") {zeile = 4; spalte = 4;};
						if (auswahl_stein == "4F" || auswahl_stein == "4f" || auswahl_stein == "4,F" || auswahl_stein == "4f") {zeile = 4; spalte = 5;};
						if (auswahl_stein == "4G" || auswahl_stein == "4g" || auswahl_stein == "4,G" || auswahl_stein == "4g") {zeile = 4; spalte = 6;};
						if (auswahl_stein == "4H" || auswahl_stein == "4h" || auswahl_stein == "4,H" || auswahl_stein == "4h") {zeile = 4; spalte = 7;};

						if (auswahl_stein == "5A" || auswahl_stein == "5a" || auswahl_stein == "5,A" || auswahl_stein == "5a") {zeile = 5; spalte = 0;};
						if (auswahl_stein == "5B" || auswahl_stein == "5b" || auswahl_stein == "5,B" || auswahl_stein == "5b") {zeile = 5; spalte = 1;};
						if (auswahl_stein == "5C" || auswahl_stein == "5c" || auswahl_stein == "5,C" || auswahl_stein == "5c") {zeile = 5; spalte = 2;};
						if (auswahl_stein == "5D" || auswahl_stein == "5d" || auswahl_stein == "5,D" || auswahl_stein == "5d") {zeile = 5; spalte = 3;};
						if (auswahl_stein == "5E" || auswahl_stein == "5e" || auswahl_stein == "5,E" || auswahl_stein == "5e") {zeile = 5; spalte = 4;};
						if (auswahl_stein == "5F" || auswahl_stein == "5f" || auswahl_stein == "5,F" || auswahl_stein == "5f") {zeile = 5; spalte = 5;};
						if (auswahl_stein == "5G" || auswahl_stein == "5g" || auswahl_stein == "5,G" || auswahl_stein == "5g") {zeile = 5; spalte = 6;};
						if (auswahl_stein == "5H" || auswahl_stein == "5h" || auswahl_stein == "5,H" || auswahl_stein == "5h") {zeile = 5; spalte = 7;};

						if (auswahl_stein == "6A" || auswahl_stein == "6a" || auswahl_stein == "6,A" || auswahl_stein == "6a") {zeile = 6; spalte = 0;};
						if (auswahl_stein == "6B" || auswahl_stein == "6b" || auswahl_stein == "6,B" || auswahl_stein == "6b") {zeile = 6; spalte = 1;};
						if (auswahl_stein == "6C" || auswahl_stein == "6c" || auswahl_stein == "6,C" || auswahl_stein == "6c") {zeile = 6; spalte = 2;};
						if (auswahl_stein == "6D" || auswahl_stein == "6d" || auswahl_stein == "6,D" || auswahl_stein == "6d") {zeile = 6; spalte = 3;};
						if (auswahl_stein == "6E" || auswahl_stein == "6e" || auswahl_stein == "6,E" || auswahl_stein == "6e") {zeile = 6; spalte = 4;};
						if (auswahl_stein == "6F" || auswahl_stein == "6f" || auswahl_stein == "6,F" || auswahl_stein == "6f") {zeile = 6; spalte = 5;};
						if (auswahl_stein == "6G" || auswahl_stein == "6g" || auswahl_stein == "6,G" || auswahl_stein == "6g") {zeile = 6; spalte = 6;};
						if (auswahl_stein == "6H" || auswahl_stein == "6h" || auswahl_stein == "6,H" || auswahl_stein == "6h") {zeile = 6; spalte = 7;};

						if (auswahl_stein == "7A" || auswahl_stein == "7a" || auswahl_stein == "7,A" || auswahl_stein == "7a") {zeile = 7; spalte = 0;};
						if (auswahl_stein == "7B" || auswahl_stein == "7b" || auswahl_stein == "7,B" || auswahl_stein == "7b") {zeile = 7; spalte = 1;};
						if (auswahl_stein == "7C" || auswahl_stein == "7c" || auswahl_stein == "7,C" || auswahl_stein == "7c") {zeile = 7; spalte = 2;};
						if (auswahl_stein == "7D" || auswahl_stein == "7d" || auswahl_stein == "7,D" || auswahl_stein == "7d") {zeile = 7; spalte = 3;};
						if (auswahl_stein == "7E" || auswahl_stein == "7e" || auswahl_stein == "7,E" || auswahl_stein == "7e") {zeile = 7; spalte = 4;};
						if (auswahl_stein == "7F" || auswahl_stein == "7f" || auswahl_stein == "7,F" || auswahl_stein == "7f") {zeile = 7; spalte = 5;};
						if (auswahl_stein == "7G" || auswahl_stein == "7g" || auswahl_stein == "7,G" || auswahl_stein == "7g") {zeile = 7; spalte = 6;};
						if (auswahl_stein == "7H" || auswahl_stein == "7h" || auswahl_stein == "7,H" || auswahl_stein == "7h") {zeile = 7; spalte = 7;};
					}


	this->zeichneZug(zug,1,zeile,spalte);
	auswahl_stein = "";

	cout << "\n Welchen Stein m\224chten Sie bewegen? (Zeile,Spalte): ";
	cin	>> auswahl_stein;
	cin.sync();

	if (auswahl_stein == "0A" || auswahl_stein == "0a" || auswahl_stein == "0,A" || auswahl_stein == "0a") {zeile_neu = 0; spalte_neu = 0;};
	if (auswahl_stein == "0B" || auswahl_stein == "0b" || auswahl_stein == "0,B" || auswahl_stein == "0b") {zeile_neu = 0; spalte_neu = 1;};
	if (auswahl_stein == "0C" || auswahl_stein == "0c" || auswahl_stein == "0,C" || auswahl_stein == "0c") {zeile_neu = 0; spalte_neu = 2;};
	if (auswahl_stein == "0D" || auswahl_stein == "0d" || auswahl_stein == "0,D" || auswahl_stein == "0d") {zeile_neu = 0; spalte_neu = 3;};
	if (auswahl_stein == "0E" || auswahl_stein == "0e" || auswahl_stein == "0,E" || auswahl_stein == "0e") {zeile_neu = 0; spalte_neu = 4;};
	if (auswahl_stein == "0F" || auswahl_stein == "0f" || auswahl_stein == "0,F" || auswahl_stein == "0f") {zeile_neu = 0; spalte_neu = 5;};
	if (auswahl_stein == "0G" || auswahl_stein == "0g" || auswahl_stein == "0,G" || auswahl_stein == "0g") {zeile_neu = 0; spalte_neu = 6;};
	if (auswahl_stein == "0H" || auswahl_stein == "0h" || auswahl_stein == "0,H" || auswahl_stein == "0h") {zeile_neu = 0; spalte_neu = 7;};

	if (auswahl_stein == "1A" || auswahl_stein == "1a" || auswahl_stein == "1,A" || auswahl_stein == "1a") {zeile_neu = 1; spalte_neu = 0;};
	if (auswahl_stein == "1B" || auswahl_stein == "1b" || auswahl_stein == "1,B" || auswahl_stein == "1b") {zeile_neu = 1; spalte_neu = 1;};
	if (auswahl_stein == "1C" || auswahl_stein == "1c" || auswahl_stein == "1,C" || auswahl_stein == "1c") {zeile_neu = 1; spalte_neu = 2;};
	if (auswahl_stein == "1D" || auswahl_stein == "1d" || auswahl_stein == "1,D" || auswahl_stein == "1d") {zeile_neu = 1; spalte_neu = 3;};
	if (auswahl_stein == "1E" || auswahl_stein == "1e" || auswahl_stein == "1,E" || auswahl_stein == "1e") {zeile_neu = 1; spalte_neu = 4;};
	if (auswahl_stein == "1F" || auswahl_stein == "1f" || auswahl_stein == "1,F" || auswahl_stein == "1f") {zeile_neu = 1; spalte_neu = 5;};
	if (auswahl_stein == "1G" || auswahl_stein == "1g" || auswahl_stein == "1,G" || auswahl_stein == "1g") {zeile_neu = 1; spalte_neu = 6;};
	if (auswahl_stein == "1H" || auswahl_stein == "1h" || auswahl_stein == "1,H" || auswahl_stein == "1h") {zeile_neu = 1; spalte_neu = 7;};

	if (auswahl_stein == "2A" || auswahl_stein == "2a" || auswahl_stein == "2,A" || auswahl_stein == "2a") {zeile_neu = 2; spalte_neu = 0;};
	if (auswahl_stein == "2B" || auswahl_stein == "2b" || auswahl_stein == "2,B" || auswahl_stein == "2b") {zeile_neu = 2; spalte_neu = 1;};
	if (auswahl_stein == "2C" || auswahl_stein == "2c" || auswahl_stein == "2,C" || auswahl_stein == "2c") {zeile_neu = 2; spalte_neu = 2;};
	if (auswahl_stein == "2D" || auswahl_stein == "2d" || auswahl_stein == "2,D" || auswahl_stein == "2d") {zeile_neu = 2; spalte_neu = 3;};
	if (auswahl_stein == "2E" || auswahl_stein == "2e" || auswahl_stein == "2,E" || auswahl_stein == "2e") {zeile_neu = 2; spalte_neu = 4;};
	if (auswahl_stein == "2F" || auswahl_stein == "2f" || auswahl_stein == "2,F" || auswahl_stein == "2f") {zeile_neu = 2; spalte_neu = 5;};
	if (auswahl_stein == "2G" || auswahl_stein == "2g" || auswahl_stein == "2,G" || auswahl_stein == "2g") {zeile_neu = 2; spalte_neu = 6;};
	if (auswahl_stein == "2H" || auswahl_stein == "2h" || auswahl_stein == "2,H" || auswahl_stein == "2h") {zeile_neu = 2; spalte_neu = 7;};

	if (auswahl_stein == "3A" || auswahl_stein == "3a" || auswahl_stein == "3,A" || auswahl_stein == "3a") {zeile_neu = 3; spalte_neu = 0;};
	if (auswahl_stein == "3B" || auswahl_stein == "3b" || auswahl_stein == "3,B" || auswahl_stein == "3b") {zeile_neu = 3; spalte_neu = 1;};
	if (auswahl_stein == "3C" || auswahl_stein == "3c" || auswahl_stein == "3,C" || auswahl_stein == "3c") {zeile_neu = 3; spalte_neu = 2;};
	if (auswahl_stein == "3D" || auswahl_stein == "3d" || auswahl_stein == "3,D" || auswahl_stein == "3d") {zeile_neu = 3; spalte_neu = 3;};
	if (auswahl_stein == "3E" || auswahl_stein == "3e" || auswahl_stein == "3,E" || auswahl_stein == "3e") {zeile_neu = 3; spalte_neu = 4;};
	if (auswahl_stein == "3F" || auswahl_stein == "3f" || auswahl_stein == "3,F" || auswahl_stein == "3f") {zeile_neu = 3; spalte_neu = 5;};
	if (auswahl_stein == "3G" || auswahl_stein == "3g" || auswahl_stein == "3,G" || auswahl_stein == "3g") {zeile_neu = 3; spalte_neu = 6;};
	if (auswahl_stein == "3H" || auswahl_stein == "3h" || auswahl_stein == "3,H" || auswahl_stein == "3h") {zeile_neu = 3; spalte_neu = 7;};

	if (auswahl_stein == "4A" || auswahl_stein == "4a" || auswahl_stein == "4,A" || auswahl_stein == "4a") {zeile_neu = 4; spalte_neu = 0;};
	if (auswahl_stein == "4B" || auswahl_stein == "4b" || auswahl_stein == "4,B" || auswahl_stein == "4b") {zeile_neu = 4; spalte_neu = 1;};
							if (auswahl_stein == "4C" || auswahl_stein == "4c" || auswahl_stein == "4,C" || auswahl_stein == "4c") {zeile_neu = 4; spalte_neu = 2;};
							if (auswahl_stein == "4D" || auswahl_stein == "4d" || auswahl_stein == "4,D" || auswahl_stein == "4d") {zeile_neu = 4; spalte_neu = 3;};
							if (auswahl_stein == "4E" || auswahl_stein == "4e" || auswahl_stein == "4,E" || auswahl_stein == "4e") {zeile_neu = 4; spalte_neu = 4;};
							if (auswahl_stein == "4F" || auswahl_stein == "4f" || auswahl_stein == "4,F" || auswahl_stein == "4f") {zeile_neu = 4; spalte_neu = 5;};
							if (auswahl_stein == "4G" || auswahl_stein == "4g" || auswahl_stein == "4,G" || auswahl_stein == "4g") {zeile_neu = 4; spalte_neu = 6;};
							if (auswahl_stein == "4H" || auswahl_stein == "4h" || auswahl_stein == "4,H" || auswahl_stein == "4h") {zeile_neu = 4; spalte_neu = 7;};

							if (auswahl_stein == "5A" || auswahl_stein == "5a" || auswahl_stein == "5,A" || auswahl_stein == "5a") {zeile_neu = 5; spalte_neu = 0;};
							if (auswahl_stein == "5B" || auswahl_stein == "5b" || auswahl_stein == "5,B" || auswahl_stein == "5b") {zeile_neu = 5; spalte_neu = 1;};
							if (auswahl_stein == "5C" || auswahl_stein == "5c" || auswahl_stein == "5,C" || auswahl_stein == "5c") {zeile_neu = 5; spalte_neu = 2;};
							if (auswahl_stein == "5D" || auswahl_stein == "5d" || auswahl_stein == "5,D" || auswahl_stein == "5d") {zeile_neu = 5; spalte_neu = 3;};
							if (auswahl_stein == "5E" || auswahl_stein == "5e" || auswahl_stein == "5,E" || auswahl_stein == "5e") {zeile_neu = 5; spalte_neu = 4;};
							if (auswahl_stein == "5F" || auswahl_stein == "5f" || auswahl_stein == "5,F" || auswahl_stein == "5f") {zeile_neu = 5; spalte_neu = 5;};
							if (auswahl_stein == "5G" || auswahl_stein == "5g" || auswahl_stein == "5,G" || auswahl_stein == "5g") {zeile_neu = 5; spalte_neu = 6;};
							if (auswahl_stein == "5H" || auswahl_stein == "5h" || auswahl_stein == "5,H" || auswahl_stein == "5h") {zeile_neu = 5; spalte_neu = 7;};

							if (auswahl_stein == "6A" || auswahl_stein == "6a" || auswahl_stein == "6,A" || auswahl_stein == "6a") {zeile_neu = 6; spalte_neu = 0;};
							if (auswahl_stein == "6B" || auswahl_stein == "6b" || auswahl_stein == "6,B" || auswahl_stein == "6b") {zeile_neu = 6; spalte_neu = 1;};
							if (auswahl_stein == "6C" || auswahl_stein == "6c" || auswahl_stein == "6,C" || auswahl_stein == "6c") {zeile_neu = 6; spalte_neu = 2;};
							if (auswahl_stein == "6D" || auswahl_stein == "6d" || auswahl_stein == "6,D" || auswahl_stein == "6d") {zeile_neu = 6; spalte_neu = 3;};
							if (auswahl_stein == "6E" || auswahl_stein == "6e" || auswahl_stein == "6,E" || auswahl_stein == "6e") {zeile_neu = 6; spalte_neu = 4;};
							if (auswahl_stein == "6F" || auswahl_stein == "6f" || auswahl_stein == "6,F" || auswahl_stein == "6f") {zeile_neu = 6; spalte_neu = 5;};
							if (auswahl_stein == "6G" || auswahl_stein == "6g" || auswahl_stein == "6,G" || auswahl_stein == "6g") {zeile_neu = 6; spalte_neu = 6;};
							if (auswahl_stein == "6H" || auswahl_stein == "6h" || auswahl_stein == "6,H" || auswahl_stein == "6h") {zeile_neu = 6; spalte_neu = 7;};

							if (auswahl_stein == "7A" || auswahl_stein == "7a" || auswahl_stein == "7,A" || auswahl_stein == "7a") {zeile_neu = 7; spalte_neu = 0;};
							if (auswahl_stein == "7B" || auswahl_stein == "7b" || auswahl_stein == "7,B" || auswahl_stein == "7b") {zeile_neu = 7; spalte_neu = 1;};
							if (auswahl_stein == "7C" || auswahl_stein == "7c" || auswahl_stein == "7,C" || auswahl_stein == "7c") {zeile_neu = 7; spalte_neu = 2;};
							if (auswahl_stein == "7D" || auswahl_stein == "7d" || auswahl_stein == "7,D" || auswahl_stein == "7d") {zeile_neu = 7; spalte_neu = 3;};
							if (auswahl_stein == "7E" || auswahl_stein == "7e" || auswahl_stein == "7,E" || auswahl_stein == "7e") {zeile_neu = 7; spalte_neu = 4;};
							if (auswahl_stein == "7F" || auswahl_stein == "7f" || auswahl_stein == "7,F" || auswahl_stein == "7f") {zeile_neu = 7; spalte_neu = 5;};
							if (auswahl_stein == "7G" || auswahl_stein == "7g" || auswahl_stein == "7,G" || auswahl_stein == "7g") {zeile_neu = 7; spalte_neu = 6;};
							if (auswahl_stein == "7H" || auswahl_stein == "7h" || auswahl_stein == "7,H" || auswahl_stein == "7h") {zeile_neu = 7; spalte_neu = 7;};
}

	brett->getFeld(spalte,zeile)->getGast()->ziehenach(brett->getFeld(spalte_neu,zeile_neu));
}

void GUI::zeichneAnleitung()
{
	system ("cls");
	cout << "\n"
		 <<	"DISTANZ-Spiel          \n"
		 <<	"_______________________________________________________________________________________________________\n\n"
		 <<	"Ziel des Spiels: Ziel des Spiel ist es, den gegnerischen K\224nig gefangen zu nehmen \n"
		 <<	"oder den Gegner in eine Situation zu bringen, in der er keinen legalen Zug mehr \n"
		 <<	"ausf\201hren kann. Der Spieler, der dieses Ziel erreicht, hat gewonnen.\n\n"
		 <<	"Spieler:\t DISTANZ ist ein Spiel f\201r zwei Spieler.\n\n"
		 <<	"Spielbrett:\t Gespielt wird auf einem Schachbrett mit 8x8 Feldern.\n\n"
		 <<	"Spielfiguren:\t Es gibt zwei Typen von Spielfiguren: K\224nige und Helfer. Was Spielz\201ge\n "
		 <<	"\t\t betrifft, unterscheiden sie sich nicht. Ein Unterschied besteht darin, dass wenn\n "
		 <<	"\t\t ein K\224nig gefangen genommen wurde, das Spiel beendet ist. Bei der Gefangennahme eines\n"
		 <<	"\t\t Helfers ist dies nicht der Fall. Der andere Unterschied besteht darin, dass K\224nige \n"
		 <<	"\t\t gefangene Helfer wieder befreien k\224nnen.\n\n"
		 << "Spielablauf:\t Es wird immer abwechselnd gezogen, wobei Spieler Wei\341 beginnt. Es besteht\n"
		 <<	"\t\t Zugzwang.\n\n"
		 << "_______________________________________________________________________________________________________\n";
}

void GUI::zeichneSpielfeld(int zug,int spieler)
{
	int zeile, spalte;

	system("cls");

	cout <<	"\n\n Es ist der: "
		 << zug
		 << " Zug"
		 << "\t\tEs spielt gerade: Spieler "
		 << spieler
		 << "\n__________________________________________________________________\n\n"
		 <<	"\n\n\t   A     B     C     D     E     F     G     H\n"
		 << "\t _____ _____ _____ _____ _____ _____ _____ _____\n";
	for (zeile = 0; zeile < 8; zeile++)
	{
		cout << "\t|     |     |     |     |     |     |     |     |\n"
			 << "    "
			 << zeile
			 << "\t|";
		for (spalte = 0; spalte < 8; spalte++)
		{
			cout << "  ";
			if (brett->getFeld(spalte,zeile)->getBesetzt())
			{
				if (brett->getFeld(spalte,zeile)->getGast()->getMteam()->getFarbe())
					{
						if (brett->getFeld(spalte,zeile)->getGast()->getGeffangen()) 	{cout << "G";}
						else if (brett->getFeld(spalte,zeile)->getGast()->getid()==4) 	{cout << "K";}
							 else 	{cout << "H";}
					}
					else
					{
						if (brett->getFeld(spalte,zeile)->getGast()->getGeffangen()) 	{cout << "g";}
						else if (brett->getFeld(spalte,zeile)->getGast()->getid()==4) 	{cout << "k";}
							 else {cout << "h";}
					}
			}
			else cout << " ";
			cout << "  |";
		}
	cout << "\n"
		 << "\t|_____|_____|_____|_____|_____|_____|_____|_____|\n";
	}
	cout << "\n\n\tH/h = Helfer wei\341/schwarz"
		 << "\n\tK/k = K\224nig wei\341/schwarz"
		 << "\n\tG/g = gefangener Helfer wei\341/schwarz"
		 << "\n\n\n__________________________________________________________________\n";
}

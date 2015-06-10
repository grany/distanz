#include "../h/GUI.h"
#include <iostream>
#include <stdlib.h>
#include "../h/KI.h"
#include "../h/KI1.h"
#include "../h/Spielbrett.h"
#include "../h/Stein.h"


using namespace std;

GUI::GUI(SpielBrett *br)				//Konstruktor
{
	brett=br;
}

void GUI::zeichneZug()
{
//abgewandelte Version von zeichneSpielfeld, Pointer benötigt
}

void GUI::Spieler()
{
//Ablaug Spieler
}

void GUI::Computer()
{
//
}

void GUI::zeichneAnleitung()
{
	system ("cls");
	cout << "###################################\n"
		 <<	"#          DISTANZ-Spiel          #\n"
		 <<	"###################################\n"
		 <<	"_______________________________________________________________________________________________________\n\n"
		 <<	"Ziel des Spiels: Ziel des Spiel ist es, den gegnerischen König gefangen zu nehmen \n"
		 <<	"oder den Gegner in eine Situation zu bringen, in der er keinen legalen Zug mehr \n"
		 <<	"ausführen kann. Der Spieler, der dieses Ziel erreicht, hat gewonnen.\n\n"
		 <<	"Spieler:\t DISTANZ ist ein Spiel für zwei Spieler.\n\n"
		 <<	"Spielbrett:\t Gespielt wird auf einem Schachbrett mit 8x8 Feldern.\n\n"
		 <<	"Spielfiguren:\t Es gibt zwei Typen von Spielfiguren: Könige und Helfer. Was Spielzüge\n "
		 <<	"\t\t betrifft, unterscheiden sie sich nicht. Ein Unterschied besteht darin, dass wenn\n "
		 <<	"\t\t ein König gefangen genommen wurde, das Spiel beendet ist. Bei der Gefangennahme eines\n"
		 <<	"\t\t Helfers ist dies nicht der Fall. Der andere Unterschied besteht darin, dass Könige \n"
		 <<	"\t\t gefangene Helfer wieder befreien können.\n\n"
		 << "Spielablauf:\t Es wird immer abwechselnd gezogen, wobei Spieler Weiß beginnt. Es besteht\n"
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
						if (brett->getFeld(spalte,zeile)->getGast()->getGeffangen()) 	{cout << "g";}
						else if (brett->getFeld(spalte,zeile)->getGast()->getid()==4) 	{cout << "k";}
							 else 	{cout << "h";}
					}
					else
					{
						if (brett->getFeld(spalte,zeile)->getGast()->getGeffangen()) 	{cout << "G";}
						else if (brett->getFeld(spalte,zeile)->getGast()->getid()==4) 	{cout << "K";}
							 else {cout << "H";}
					}
			}
			else cout << " ";
			cout << "  |";
		}
	cout << "\n"
		 << "\t|_____|_____|_____|_____|_____|_____|_____|_____|\n";
	}
	cout << "\n\n__________________________________________________________________\n"
		 << "\n Bitte geben Sie ihren nächsten Zug ein (Zeile,Spalte): ";
}

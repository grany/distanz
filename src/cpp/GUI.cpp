
#include "../h/GUI.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
void GUI::zeichneAnleitung()
{
	cout << "###################################\n"
		 <<	"#          DISTANZ-Spiel          #\n"
		 <<	"###################################\n"
		 <<	"_______________________________________________________________________________________________________\n"
		 <<	"Ziel des Spiels: Ziel des Spiel ist es, den gegnerischen K�nig gefangen zu nehmen \n"
		 <<	"oder den Gegner in eine Situation zu bringen, in der er keinen legalen Zug mehr \n"
		 <<	"ausf�hren kann. Der Spieler, der dieses Ziel erreicht, hat gewonnen.\n\n"
		 <<	"Spieler:\t DISTANZ ist ein Spiel f�r zwei Spieler.\n\n"
		 <<	"Spielbrett:\t Gespielt wird auf einem Schachbrett mit 8x8 Feldern.\n\n"
		 <<	"Spielfiguren:\t Es gibt zwei Typen von Spielfiguren: K�nige und Helfer. Was Spielz�ge\n "
		 <<	"\t\t betrifft, unterscheiden sie sich nicht. Ein Unterschied besteht darin, dass wenn\n "
		 <<	"\t\t ein K�nig gefangen genommen wurde, das Spiel beendet ist. Bei der Gefangennahme eines\n"
		 <<	"\t\t Helfers ist dies nicht der Fall. Der andere Unterschied besteht darin, dass K�nige \n"
		 <<	"\t\t gefangene Helfer wieder befreien k�nnen.\n\n"
		 << "Spielablauf:\t Es wird immer abwechselnd gezogen, wobei Spieler Wei� beginnt. Es besteht\n"
		 <<	"\t\t Zugzwang.\n\n"
		 << "_______________________________________________________________________________________________________\n";
}

GUI::GUI(SpielBrett *br){
	brett=br;
};
void GUI::zeichneSpielfeld()
{
	int zeile, spalte;

	system("cls");
	cout << "\n\n\t   A     B     C     D     E     F     G     H\n"
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
			if (brett->getFeld(zeile,spalte)->getBesetzt())
			{
				if (brett->getFeld(zeile,spalte)->getGast()->getMteam()->getFarbe())
					cout 	<< "|s"
							<<brett->getFeld(zeile,spalte)->getGast()->getid();
				else
					cout	<<"|S"
							<<brett->getFeld(zeile,spalte)->getGast()->getid();
			}
			cout << "  |";
		}
		cout << "\n"
			 << "\t|_____|_____|_____|_____|_____|_____|_____|_____|\n";
	}
}

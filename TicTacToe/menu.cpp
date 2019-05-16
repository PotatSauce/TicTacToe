#include "menu.h"
#include "pvp.h"
void Meniu::Spausdinimas()
{
	system("cls");
	cout << endl;
	cout << "   =======================================" << endl;
	cout << "   |                                     |" << endl;
	cout << "   |           Tic Tac Toe  v1.0         |" << endl;
	cout << "   |                                     |" << endl;
	cout << "   =======================================" << endl;
	cout << "   |  Pasirinkite þaidimà:               |" << endl;
	cout << "   |  1. Prieð kità þaidëjà              |" << endl;
	cout << "   |  2. Prieð kompiuterá                |" << endl;
	cout << "   |                                     |" << endl;
	cout << "   |  3. Baigti þaidimà                  |" << endl;
	cout << "   =======================================" << endl;
}

void Meniu::Pasirinkimas()
{
	Spausdinimas();
	cout << "   Áveskite pasirinkimà: ";
	cin >> Numeris;
	if (1 == Numeris)
	{
		Zaidimas1 zaidimas;
		zaidimas.Ivedimas();
	}
	if (2 == Numeris)
	{
		;
	}
	if (3 == Numeris)
	{
		exit(0);
	}
	else
	{
		Spausdinimas();
		cout << "   Neteisingas pasirinkimas." << endl;
		cin.ignore();
		cin.get();
		Pasirinkimas();
	}
}

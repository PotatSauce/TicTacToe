#include "menu.h"
#include "pvp.h"
#include "pve.h"

void Meniu::Spausdinimas()
{
	system("cls");
	cout << endl;
	cout << "   =======================================" << endl;
	cout << "   |                                     |" << endl;
	cout << "   |           Tic Tac Toe  v1.0         |" << endl;
	cout << "   |                                     |" << endl;
	cout << "   =======================================" << endl;
	cout << "   |  Pasirinkite �aidim�:               |" << endl;
	cout << "   |  1. Prie� kit� �aid�j�              |" << endl;
	cout << "   |  2. Prie� kompiuter�                |" << endl;
	cout << "   |                                     |" << endl;
	cout << "   |  3. Baigti �aidim�                  |" << endl;
	cout << "   =======================================" << endl;
}

void Meniu::Pasirinkimas()
{
	Spausdinimas();
	cout << "   �veskite pasirinkim�: ";
	cin >> Numeris;
	if ("1" == Numeris)
	{
		Zaidimas1 zaidimas1;
		zaidimas1.Ivedimas();
	}
	if ("2" == Numeris)
	{
		Zaidimas2 zaidimas2;
		zaidimas2.Pasirinkimas();;
	}
	if ("3" == Numeris)
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
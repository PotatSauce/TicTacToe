#include "pvp.h"

void Zaidimas1::Ikelimas()
{
	system("cls");
	cout << endl;
	cout << "   =======================================" << endl;
	cout << "   |                                     |" << endl;
	cout << "   |           Tic Tac Toe  v1.0         |" << endl;
	cout << "   |                                     |" << endl;
	cout << "   =======================================" << endl;
	cout << "   |  Þaidëjas 1 (X)  -  Þaidëjas 2 (O)  |" << endl;
	cout << "   =======================================" << endl;
	cout << "   |                                     |" << endl;
	cout << "   |               |     |               |" << endl;
	cout << "   |            " << Lenta[0] << "  |  " << Lenta[1] << "  |  " << Lenta[2] << "            |" << endl;
	cout << "   |          _____|_____|_____          |" << endl;
	cout << "   |               |     |               |" << endl;
	cout << "   |            " << Lenta[3] << "  |  " << Lenta[4] << "  |  " << Lenta[5] << "            |" << endl;
	cout << "   |          _____|_____|_____          |" << endl;
	cout << "   |               |     |               |" << endl;
	cout << "   |            " << Lenta[6] << "  |  " << Lenta[7] << "  |  " << Lenta[8] << "            |" << endl;
	cout << "   |               |     |               |" << endl;
	cout << "   |                                     |" << endl;
	cout << "   =======================================" << endl;
}
void Zaidimas1::Ivedimas()
{
	int Zaidejas(1), Vieta, Laimetojas;
	char Simbolis, Dar;
	do
	{
		Ikelimas();
		Zaidejas = (Zaidejas % 2) ? 1 : 2;
		cout << "   Þaidëjo " << Zaidejas << " ëjimas: ";
		cin >> Vieta;
		Simbolis = (Zaidejas == 1) ? 'X' : '0';
		if (1 <= Vieta && Vieta <= 9)
		{
			if (Lenta[Vieta - 1] != 'X' && Lenta[Vieta - 1] != '0')
			{
				Lenta[Vieta - 1] = Simbolis;
			}
			else
			{
				Ikelimas();
				cout << "   Laukelis jau uþimtas, bandykite dar kartà.";
				cin.ignore();
				cin.get();
				Zaidejas--;
			}
		}
		else
		{
			Ikelimas();
			cout << "   Neteisinga reikðmë, bandykite dar kartà.";
			cin.ignore();
			cin.get();
			Zaidejas--;
		}
		Zaidejas++;
		Laimetojas = Tikrinimas();
	} while (Laimetojas == -1);
	if (Laimetojas == 1)
	{
		Ikelimas();
		cout << "   Þaidëjas " << Zaidejas - 1 << " laimëjo! Þaisite dar kartà? (T/N): ";
		cin >> Dar;
		if (Dar == 'T' || Dar == 't')
		{
			Laimetojas = -1;
			Zaidejas = 1;
			setLenta();
			Ivedimas();
		}
		if (Dar == 'N' || Dar == 'n')
		{
			Laimetojas = -1;
			Zaidejas = 1;
			setLenta();
			meniu.Pasirinkimas();
		}
		else
		{
			Ikelimas();
			cout << "   Ivestas neteisingas pasirinkimas.";
			cin.ignore();
			cin.get();
		}
	}
	if (Laimetojas == 0)
	{
		Ikelimas();
		cout << "   Lygiosios. Þaisite dar karta? (T/N): ";
		cin >> Dar;
		if (Dar == 'T' || Dar == 't')
		{
			Laimetojas = -1;
			Zaidejas = 1;
			setLenta();
			Ivedimas();
		}
		if (Dar == 'N' || Dar == 'n')
		{
			Laimetojas = -1;
			Zaidejas = 1;

			meniu.Pasirinkimas();
		}
		else
		{
			Ikelimas();
			cout << "   Ivestas neteisingas pasirinkimas.";
			cin.ignore();
			cin.get();

		}
	}
}
int Zaidimas1::Tikrinimas()
{
	if (Lenta[0] == Lenta[1] && Lenta[1] == Lenta[2])
		return 1;
	if (Lenta[3] == Lenta[4] && Lenta[4] == Lenta[5])
		return 1;
	if (Lenta[6] == Lenta[7] && Lenta[7] == Lenta[8])
		return 1;
	if (Lenta[0] == Lenta[3] && Lenta[3] == Lenta[6])
		return 1;
	if (Lenta[1] == Lenta[4] && Lenta[4] == Lenta[7])
		return 1;
	if (Lenta[2] == Lenta[5] && Lenta[5] == Lenta[8])
		return 1;
	if (Lenta[0] == Lenta[4] && Lenta[4] == Lenta[8])
		return 1;
	if (Lenta[2] == Lenta[4] && Lenta[4] == Lenta[6])
		return 1;
	if (Lenta[0] != '1' && Lenta[1] != '2' && Lenta[2] != '3' && Lenta[3] != '4' && Lenta[4] != '5' && Lenta[5] != '6' && Lenta[6] != '7' && Lenta[7] != '8' && Lenta[8] != '9')
		return 0;
	else
		return -1;
}

void Zaidimas1::setLenta()
{
	Lenta[0] = '1';
	Lenta[1] = '2';
	Lenta[2] = '3';
	Lenta[3] = '4';
	Lenta[4] = '5';
	Lenta[5] = '6';
	Lenta[6] = '7';
	Lenta[7] = '8';
	Lenta[8] = '9';
}
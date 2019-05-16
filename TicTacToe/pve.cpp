#include "pve.h"

void Zaidimas2::Ikelimas()
{
	system("cls");
	cout << endl;
	cout << "   =======================================" << endl;
	cout << "   |                                     |" << endl;
	cout << "   |           Tic Tac Toe  v1.0         |" << endl;
	cout << "   |                                     |" << endl;
	cout << "   =======================================" << endl;
	cout << "   |  Þaidëjas (" << ManoSimbolis << ")    -    AI (" << PriesoSimbolis << ")        |" << endl;
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

void Zaidimas2::Pasirinkimas()
{
	Ikelimas();
	cout << "   Pasirinkite (X ar 0): ";
	cin >> ManoSimbolis;
	if (ManoSimbolis == 'X' || ManoSimbolis == 'x')
	{
		ManoSimbolis = 'X';
		PriesoSimbolis = '0';
		Ivedimas();
	}
	if (ManoSimbolis == '0' || ManoSimbolis == 'o')
	{
		ManoSimbolis = '0';
		PriesoSimbolis = 'X';
		Kompiuteris();
	}
	else
	{
		Ikelimas();
		cout << "   Ávestas netinkamas simbolis." << endl;
		cin.ignore();
		cin.get();
		Pasirinkimas();
	}
}

void Zaidimas2::Ivedimas()
{
	int Vieta;
	do
	{
		Ikelimas();
		cout << "   Jûsø ëjimas: ";
		cin >> Vieta;
		if (1 <= Vieta && Vieta <= 9)
		{
			if (Lenta[Vieta - 1] != 'X' && Lenta[Vieta - 1] != '0')
			{
				Lenta[Vieta - 1] = ManoSimbolis;
				Ejimas = 0;
			}
			else
			{
				Ikelimas();
				cout << "   Laukelis jau uþimtas, bandykite dar kartà.";
				cin.ignore();
				cin.get();
			}
		}
		else
		{
			Ikelimas();
			cout << "   Neteisinga reikðmë, bandykite dar kartà.";
			cin.ignore();
			cin.get();
		}
		Laimetojas = Tikrinimas();
	} while (Laimetojas == -1 && Ejimas == 1);
	if (Laimetojas == 1)
	{
		Ikelimas();
		cout << "   Jûs laimëjote! Þaisite dar kartà? (T/N): ";
		cin >> Dar;
		if (Dar == 'T' || Dar == 't')
		{
			Laimetojas = -1;
			ManoSimbolis = '-';
			PriesoSimbolis = '-';
			Ejimas = 1;
			setLenta();
			Pasirinkimas();
		}
		if (Dar == 'N' || Dar == 'n')
		{
			Laimetojas = -1;
			ManoSimbolis = '-';
			PriesoSimbolis = '-';
			Ejimas = 1;
			setLenta();
			meniu.Pasirinkimas();
		}
		else
		{
			Ikelimas();
			cout << "   Ávestas neteisingas pasirinkimas.";
			cin.ignore();
			cin.get();
		}
	}
	if (Laimetojas == 0)
		Lygiosios();
	else
	{
		Ejimas = 1;
		Kompiuteris();
	}
}

void Zaidimas2::Kompiuteris()
{
	Ikelimas();
	cout << "   Laukiama prieðininko." << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));
	Puolimas();
}

void Zaidimas2::Ginyba()
{
	if (Lenta[0] == ManoSimbolis && Lenta[1] == ManoSimbolis && Lenta[2] == '3')
	{
		Lenta[2] = PriesoSimbolis;
	}
	else if (Lenta[0] == ManoSimbolis && Lenta[2] == ManoSimbolis && Lenta[1] == '2')
	{
		Lenta[1] = PriesoSimbolis;
	}
	else if (Lenta[1] == ManoSimbolis && Lenta[2] == ManoSimbolis && Lenta[0] == '1')
	{
		Lenta[0] = PriesoSimbolis;
	}
	else if (Lenta[3] == ManoSimbolis && Lenta[4] == ManoSimbolis && Lenta[5] == '6')
	{
		Lenta[5] = PriesoSimbolis;
	}
	else if (Lenta[3] == ManoSimbolis && Lenta[5] == ManoSimbolis && Lenta[4] == '5')
	{
		Lenta[4] = PriesoSimbolis;
	}
	else if (Lenta[4] == ManoSimbolis && Lenta[5] == ManoSimbolis && Lenta[3] == '4')
	{
		Lenta[3] = PriesoSimbolis;
	}
	else if (Lenta[6] == ManoSimbolis && Lenta[7] == ManoSimbolis && Lenta[8] == '9')
	{
		Lenta[8] = PriesoSimbolis;
	}
	else if (Lenta[6] == ManoSimbolis && Lenta[8] == ManoSimbolis && Lenta[7] == '8')
	{
		Lenta[7] = PriesoSimbolis;
	}
	else if (Lenta[7] == ManoSimbolis && Lenta[8] == ManoSimbolis && Lenta[6] == '7')
	{
		Lenta[6] = PriesoSimbolis;
	}
	else if (Lenta[0] == ManoSimbolis && Lenta[3] == ManoSimbolis && Lenta[6] == '7')
	{
		Lenta[6] = PriesoSimbolis;
	}
	else if (Lenta[0] == ManoSimbolis && Lenta[6] == ManoSimbolis && Lenta[3] == '4')
	{
		Lenta[3] = PriesoSimbolis;
	}
	else if (Lenta[3] == ManoSimbolis && Lenta[6] == ManoSimbolis && Lenta[0] == '1')
	{
		Lenta[0] = PriesoSimbolis;
	}
	else if (Lenta[1] == ManoSimbolis && Lenta[4] == ManoSimbolis && Lenta[7] == '8')
	{
		Lenta[7] = PriesoSimbolis;
	}
	else if (Lenta[1] == ManoSimbolis && Lenta[7] == ManoSimbolis && Lenta[4] == '5')
	{
		Lenta[4] = PriesoSimbolis;
	}
	else if (Lenta[0] == ManoSimbolis && Lenta[1] == ManoSimbolis && Lenta[1] == '2')
	{
		Lenta[1] = PriesoSimbolis;
	}
	else if (Lenta[2] == ManoSimbolis && Lenta[5] == ManoSimbolis && Lenta[8] == '9')
	{
		Lenta[8] = PriesoSimbolis;
	}
	else if (Lenta[2] == ManoSimbolis && Lenta[8] == ManoSimbolis && Lenta[5] == '6')
	{
		Lenta[5] = PriesoSimbolis;
	}
	else if (Lenta[5] == ManoSimbolis && Lenta[8] == ManoSimbolis && Lenta[2] == '3')
	{
		Lenta[2] = PriesoSimbolis;
	}
	else if (Lenta[0] == ManoSimbolis && Lenta[4] == ManoSimbolis && Lenta[8] == '9')
	{
		Lenta[8] = PriesoSimbolis;
	}
	else if (Lenta[0] == ManoSimbolis && Lenta[8] == ManoSimbolis && Lenta[4] == '5')
	{
		Lenta[4] = PriesoSimbolis;
	}
	else if (Lenta[4] == ManoSimbolis && Lenta[8] == ManoSimbolis && Lenta[0] == '1')
	{
		Lenta[0] = PriesoSimbolis;
	}
	else if (Lenta[2] == ManoSimbolis && Lenta[4] == ManoSimbolis && Lenta[6] == '7')
	{
		Lenta[6] = PriesoSimbolis;
	}
	else if (Lenta[2] == ManoSimbolis && Lenta[6] == ManoSimbolis && Lenta[4] == '5')
	{
		Lenta[4] = PriesoSimbolis;
	}
	else if (Lenta[4] == ManoSimbolis && Lenta[6] == ManoSimbolis && Lenta[2] == '3')
	{
		Lenta[2] = PriesoSimbolis;
	}
	else PuolimasRandom();
	Laimetojas = Tikrinimas();
	if (Laimetojas == 0)
		Lygiosios();
	if (Laimetojas == -1)
		Ivedimas();
	if (Laimetojas == 1)
	{
		Ikelimas();
		cout << "   Jûs praimëjote. Þaisite dar kartà? (T/N): ";
		cin >> Dar;
		if (Dar == 'T' || Dar == 't')
		{
			Laimetojas = -1;
			ManoSimbolis = '-';
			PriesoSimbolis = '-';
			Ejimas = 1;
			setLenta();
			Pasirinkimas();
		}
		if (Dar == 'N' || Dar == 'n')
		{
			Laimetojas = -1;
			ManoSimbolis = '-';
			PriesoSimbolis = '-';
			Ejimas = 1;
			setLenta();
			meniu.Pasirinkimas();
		}
		else
		{
			Ikelimas();
			cout << "   Ávestas neteisingas pasirinkimas.";
			cin.ignore();
			cin.get();
		}
	}
}

void Zaidimas2::Puolimas()
{
	if (((Lenta[0] == PriesoSimbolis && Lenta[1] == PriesoSimbolis) || (Lenta[0] == PriesoSimbolis && Lenta[2] == PriesoSimbolis) || (Lenta[1] == PriesoSimbolis && Lenta[2] == PriesoSimbolis)) && (Lenta[0] != ManoSimbolis && Lenta[1] != ManoSimbolis && Lenta[2] != ManoSimbolis))
	{
		if (Lenta[0] == '1')
			Lenta[0] = PriesoSimbolis;
		else if (Lenta[1] == '2')
			Lenta[1] = PriesoSimbolis;
		else if (Lenta[2] == '3')
			Lenta[2] = PriesoSimbolis;
	}
	else if (((Lenta[3] == PriesoSimbolis && Lenta[4] == PriesoSimbolis) || (Lenta[3] == PriesoSimbolis && Lenta[5] == PriesoSimbolis) || (Lenta[4] == PriesoSimbolis && Lenta[5] == PriesoSimbolis)) && (Lenta[3] != ManoSimbolis && Lenta[4] != ManoSimbolis && Lenta[5] != ManoSimbolis))
	{
		if (Lenta[3] == '4')
			Lenta[3] = PriesoSimbolis;
		else if (Lenta[4] == '5')
			Lenta[4] = PriesoSimbolis;
		else if (Lenta[5] == '6')
			Lenta[5] = PriesoSimbolis;
	}
	else if (((Lenta[6] == PriesoSimbolis && Lenta[7] == PriesoSimbolis) || (Lenta[6] == PriesoSimbolis && Lenta[8] == PriesoSimbolis) || (Lenta[7] == PriesoSimbolis && Lenta[8] == PriesoSimbolis)) && (Lenta[6] != ManoSimbolis && Lenta[7] != ManoSimbolis && Lenta[8] != ManoSimbolis))
	{
		if (Lenta[6] == '7')
			Lenta[6] = PriesoSimbolis;
		else if (Lenta[7] == '8')
			Lenta[7] = PriesoSimbolis;
		else if (Lenta[8] == '9')
			Lenta[8] = PriesoSimbolis;
	}
	else if (((Lenta[0] == PriesoSimbolis && Lenta[3] == PriesoSimbolis) || (Lenta[0] == PriesoSimbolis && Lenta[6] == PriesoSimbolis) || (Lenta[3] == PriesoSimbolis && Lenta[6] == PriesoSimbolis)) && (Lenta[0] != ManoSimbolis && Lenta[3] != ManoSimbolis && Lenta[6] != ManoSimbolis))
	{
		if (Lenta[0] == '1')
			Lenta[0] = PriesoSimbolis;
		else if (Lenta[3] == '4')
			Lenta[3] = PriesoSimbolis;
		else if (Lenta[6] == '7')
			Lenta[6] = PriesoSimbolis;
	}
	else if (((Lenta[1] == PriesoSimbolis && Lenta[4] == PriesoSimbolis) || (Lenta[1] == PriesoSimbolis && Lenta[7] == PriesoSimbolis) || (Lenta[4] == PriesoSimbolis && Lenta[7] == PriesoSimbolis)) && (Lenta[1] != ManoSimbolis && Lenta[4] != ManoSimbolis && Lenta[7] != ManoSimbolis))
	{
		if (Lenta[1] == '2')
			Lenta[1] = PriesoSimbolis;
		else if (Lenta[4] == '4')
			Lenta[4] = PriesoSimbolis;
		else if (Lenta[7] == '8')
			Lenta[7] = PriesoSimbolis;
	}
	else if (((Lenta[2] == PriesoSimbolis && Lenta[5] == PriesoSimbolis) || (Lenta[2] == PriesoSimbolis && Lenta[8] == PriesoSimbolis) || (Lenta[5] == PriesoSimbolis && Lenta[8] == PriesoSimbolis)) && (Lenta[2] != ManoSimbolis && Lenta[5] != ManoSimbolis && Lenta[8] != ManoSimbolis))
	{
		if (Lenta[2] == '3')
			Lenta[2] = PriesoSimbolis;
		else if (Lenta[5] == '6')
			Lenta[5] = PriesoSimbolis;
		else if (Lenta[8] == '9')
			Lenta[8] = PriesoSimbolis;
	}
	else if (((Lenta[0] == PriesoSimbolis && Lenta[4] == PriesoSimbolis) || (Lenta[0] == PriesoSimbolis && Lenta[8] == PriesoSimbolis) || (Lenta[4] == PriesoSimbolis && Lenta[8] == PriesoSimbolis)) && (Lenta[0] != ManoSimbolis && Lenta[4] != ManoSimbolis && Lenta[8] != ManoSimbolis))
	{
		if (Lenta[0] == '1')
			Lenta[0] = PriesoSimbolis;
		else if (Lenta[4] == '5')
			Lenta[4] = PriesoSimbolis;
		else if (Lenta[8] == '9')
			Lenta[8] = PriesoSimbolis;
	}
	else if (((Lenta[2] == PriesoSimbolis && Lenta[4] == PriesoSimbolis) || (Lenta[2] == PriesoSimbolis && Lenta[6] == PriesoSimbolis) || (Lenta[4] == PriesoSimbolis && Lenta[6] == PriesoSimbolis)) && (Lenta[2] != ManoSimbolis && Lenta[4] != ManoSimbolis && Lenta[6] != ManoSimbolis))
	{
		if (Lenta[2] == '3')
			Lenta[2] = PriesoSimbolis;
		else if (Lenta[4] == '5')
			Lenta[4] = PriesoSimbolis;
		else if (Lenta[6] == '7')
			Lenta[6] = PriesoSimbolis;
	}
	else Ginyba();
	Laimetojas = Tikrinimas();
	if (Laimetojas == -1)
		Ivedimas();
	if (Laimetojas == 0)
		Lygiosios();
	if (Laimetojas == 1)
	{
		Ikelimas();
		cout << "   Jûs pralaimëjote. Þaisite dar kartà? (T/N): ";
		cin >> Dar;
		if (Dar == 'T' || Dar == 't')
		{
			Laimetojas = -1;
			ManoSimbolis = '-';
			PriesoSimbolis = '-';
			Ejimas = 1;
			setLenta();
			Pasirinkimas();
		}
		if (Dar == 'N' || Dar == 'n')
		{
			Laimetojas = -1;
			ManoSimbolis = '-';
			PriesoSimbolis = '-';
			Ejimas = 1;
			setLenta();
			meniu.Pasirinkimas();
		}
		else
		{
			Ikelimas();
			cout << "   Ávestas neteisingas pasirinkimas.";
			cin.ignore();
			cin.get();
		}
	}
}

void Zaidimas2::PuolimasRandom()
{
	int Random;
	srand((unsigned int)time(NULL));
	Random = rand() % 8 - 0;
	if (Lenta[Random] == PriesoSimbolis && Lenta[Random] == ManoSimbolis)
	{
		Random = 0;
		while (Lenta[Random] == PriesoSimbolis || Lenta[Random] == ManoSimbolis)
		{
			Random++;
		}
	}
	if (Lenta[Random] != PriesoSimbolis && Lenta[Random] != ManoSimbolis)
	{
		Lenta[Random] = PriesoSimbolis;
		Laimetojas = Tikrinimas();
		if (Laimetojas == -1)
			Ivedimas();
		if (Laimetojas == 0)
			Lygiosios();
		if (Laimetojas == 1)
		{
			Ikelimas();
			cout << "   Jûs pralaimëjote. Þaisite dar kartà? (T/N): ";
			cin >> Dar;
			if (Dar == 'T' || Dar == 't')
			{
				Laimetojas = -1;
				ManoSimbolis = '-';
				PriesoSimbolis = '-';
				Ejimas = 1;
				setLenta();
				Pasirinkimas();
			}
			if (Dar == 'N' || Dar == 'n')
			{
				Laimetojas = -1;
				ManoSimbolis = '-';
				PriesoSimbolis = '-';
				Ejimas = 1;
				setLenta();
				meniu.Pasirinkimas();
			}
			else
			{
				Ikelimas();
				cout << "   Ávestas neteisingas pasirinkimas.";
				cin.ignore();
				cin.get();
			}
		}
	}
	else
	{

		PuolimasRandom();
	}
}

int Zaidimas2::Tikrinimas()
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

void Zaidimas2::Lygiosios()
{
	Ikelimas();
	cout << "   Lygiosios. Þaisite dar karta? (T/N): ";
	cin >> Dar;
	if (Dar == 'T' || Dar == 't')
	{
		Laimetojas = -1;
		ManoSimbolis = '-';
		PriesoSimbolis = '-';
		Ejimas = 1;
		setLenta();
		Pasirinkimas();
	}
	if (Dar == 'N' || Dar == 'n')
	{
		Laimetojas = -1;
		ManoSimbolis = '-';
		PriesoSimbolis = '-';
		Ejimas = 1;
		setLenta();
		meniu.Pasirinkimas();
	}
	else
	{
		Ikelimas();
		cout << "   Ávestas neteisingas pasirinkimas.";
		cin.ignore();
		cin.get();
	}
}
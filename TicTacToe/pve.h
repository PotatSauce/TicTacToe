#pragma once
#include "pvp.h"
#include <thread>

class Zaidimas2 : public Zaidimas1
{
private:
	int Laimetojas, Ejimas = 1;
	string ManoSimbolis = "-", PriesoSimbolis = "-", Dar;
public:
	virtual void Ivedimas();
	virtual void Ikelimas();
	virtual int Tikrinimas();
	void Pasirinkimas();
	void Kompiuteris();
	void Ginyba();
	void Puolimas();
	void PuolimasRandom();
	void Lygiosios();
};
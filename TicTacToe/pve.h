#pragma once
#include "pvp.h"
#include <thread>

class Zaidimas2 : public Zaidimas1
{
private:
	int Laimetojas, Ejimas;
	string ManoSimbolis, PriesoSimbolis, Dar;
public:
	Zaidimas2();
	~Zaidimas2() {};
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
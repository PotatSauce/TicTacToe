#pragma once
#include <iostream>
#include <vector>
#include "menu.h"
using namespace std;
class Zaidimas1
{
public:
	vector <char> Lenta = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	Meniu meniu;

	virtual ~Zaidimas1() {}
	virtual void Ikelimas();
	virtual int Tikrinimas();
	virtual void Ivedimas();
	virtual void setLenta();
};
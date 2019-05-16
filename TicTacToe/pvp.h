#pragma once
#include <iostream>
#include <vector>
#include "menu.h"
using namespace std;
class Zaidimas1
{
private:
	vector <char> Lenta = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	Meniu meniu;
public:
	void Ikelimas();
	int Tikrinimas();
	void Ivedimas();
	void setLenta();
};
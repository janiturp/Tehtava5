#pragma once
#include "Maastotyyppi.h"

class Maastoruutu
{
public:
	int _x = 0;
	int _y = 0;
	Maastotyyppi _tyyppi;

	Maastoruutu() 
	{
	};

	Maastoruutu(int x, int y)
	{
		_x = x;
		_y = y;
	};

	void SetMaastotyyppi(Maastotyyppi tyyppi);
	int GetX();
	int GetY();
};


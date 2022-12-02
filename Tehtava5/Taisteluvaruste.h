#pragma once
#include "Objekti.h"
#include <string>
#include "Maastoruutu.h"
using namespace std;

class Taisteluvaruste : public Objekti
{
public:
	int _hyokkaysvoima;
	int _puolustusvoima;
	Maastoruutu* _sijainti;

	Taisteluvaruste(int hyokkaysvoima, int puolustusvoima, string nimi) 
		: Objekti(nimi), _hyokkaysvoima(hyokkaysvoima), _puolustusvoima(puolustusvoima) {};

	void SetSijainti(Maastoruutu* sijainti);
};


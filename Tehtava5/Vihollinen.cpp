#include "Vihollinen.h"
#include <iostream>
using namespace std;

int Vihollinen::Hyokkaa()
{
	cout << "Vihollinen hyökkää!\n";
	return _alku_hyokkaysvoima;
}

void Vihollinen::OtaVahinkoa(int vahinko, int puolustusvoima)
{
	cout << "Vihollinen ottaa vahinkoa!\n";
	_hp -= vahinko - puolustusvoima;
	if (_hp <= 0)
	{
		Vihollinen::Kuoli();
	}
}

void Vihollinen::Kuoli()
{
	cout << "Vihollinen kuoli!\n";
}

void Vihollinen::SetSijainti(Maastoruutu* sijainti)
{
	_sijainti = sijainti;
}

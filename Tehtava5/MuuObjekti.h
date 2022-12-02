#pragma once
#include "Objekti.h"
#include <string>
#include "Maastoruutu.h";
using namespace std;

class MuuObjekti : public Objekti
{
public:
	int _kuntovaikutus;
	int _rahavaikutus;
	Maastoruutu* _sijainti;

	MuuObjekti(int kuntovaikutus, int rahavaikutus, string nimi) 
		: Objekti(nimi), _kuntovaikutus(kuntovaikutus), _rahavaikutus(rahavaikutus){}

	void SetSijainti(Maastoruutu* sijainti);
};


#pragma once
#include <string>
#include "Objekti.h"
#include "Maastoruutu.h"
using namespace std;

class Pelihahmo
{
public:
	string _nimi;
	int _level;
	int _hp;
	int _gold;
	Maastoruutu* _sijainti;
	Objekti* inventaario[10];


	Pelihahmo(string nimi, int level, int hp, int gold)
	{
		_nimi = nimi;
		_level = level;
		_hp = hp;
		_gold = gold;
	}

	void SetSijainti(Maastoruutu* sijainti);
};


#pragma once
class Vihollistyyppi
{
public:
	int _alku_hp;
	int _alku_hyokkaysvoima;
	int _alku_puolustusvoima;

	Vihollistyyppi(int alku_hp, int alku_hyokkaysvoima, int alku_puolustusvoima) 
	{
		_alku_hp = alku_hp;
		_alku_hyokkaysvoima = alku_hyokkaysvoima;
		_alku_puolustusvoima = alku_puolustusvoima;
	};
	~Vihollistyyppi() {};

	int GetAlkuHP();
	int GetAlkuHyokkaysvoima();
	int GetAlkuPuolustusvoima();
};


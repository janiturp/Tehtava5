#pragma once
#include "Vihollistyyppi.h"
#include "Maastoruutu.h"
#include <string>
using namespace std;

class Vihollinen :
    public Vihollistyyppi
{
public:
    int _hp;
    Maastoruutu* _sijainti;

    Vihollinen(int hp, int alku_hp, int alku_hyokkaysvoima, int alku_puolustusvoima)
        : Vihollistyyppi(alku_hp, alku_hyokkaysvoima, alku_puolustusvoima), _hp(hp)
    {};

    ~Vihollinen() {};

    int Hyokkaa();
    void OtaVahinkoa(int vahinko, int puolustusvoima);
    void Kuoli();
    void SetSijainti(Maastoruutu* sijainti);
};


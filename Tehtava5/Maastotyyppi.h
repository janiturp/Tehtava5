#pragma once
#include <string>
using namespace std;

class Maastotyyppi
{
public:
	float _liikkumisvaikeus;
	float _taisteluvaikeus;
	string _tyyppikirjain;

	Maastotyyppi() {};
	
	Maastotyyppi(float liikkumisvaikeus, float taisteluvaikeus, string tyyppikirjain) 
	{
		_liikkumisvaikeus = liikkumisvaikeus;
		_taisteluvaikeus = taisteluvaikeus;
		_tyyppikirjain = tyyppikirjain;
	};

	virtual string GetTyyppikirjain()
	{
		return _tyyppikirjain;
	}
};


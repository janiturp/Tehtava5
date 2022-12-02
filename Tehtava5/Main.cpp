#include <iostream>
#include <string>
#include "Vihollistyyppi.h"
#include "Vihollinen.h"
#include "Karttapohja.h"
#include "Maastoruutu.h"
#include "Maastotyyppi.h"
#include "MuuObjekti.h"
#include "Objekti.h"
#include "Pelihahmo.h"
#include "Taisteluvaruste.h"
using namespace std;

int main()
{
	Karttapohja* karttapohja = new Karttapohja();
	Maastoruutu* ruudut[12];


	// Ruudukon luonti.
	int ruutuNro = 0;
	for (int i = 0; i < 3; i++)
	{
		ruudut[ruutuNro] = new Maastoruutu(0, i);
		for (int j = 0; j < 4; j++)
		{
			ruudut[ruutuNro] = new Maastoruutu(j, i);
			ruutuNro++;
		}
	}
	cout << "Kartta luotu " << ruutuNro << " ruudukolla. \n";


	Maastotyyppi tie(0, 0, "T");
	Maastotyyppi mets‰(2, 1, "M");
	Maastotyyppi vuoristo(5, 5, "V");

	// Maastotyypien m‰‰ritys.
	// 1. rivi
	ruudut[0]->SetMaastotyyppi(tie);
	ruudut[1]->SetMaastotyyppi(tie);
	ruudut[2]->SetMaastotyyppi(tie);
	ruudut[3]->SetMaastotyyppi(tie);

	// 2. Rivi
	ruudut[4]->SetMaastotyyppi(vuoristo);
	ruudut[5]->SetMaastotyyppi(vuoristo);
	ruudut[6]->SetMaastotyyppi(tie);
	ruudut[7]->SetMaastotyyppi(mets‰);

	// 3. rivi
	ruudut[8]->SetMaastotyyppi(vuoristo);
	ruudut[9]->SetMaastotyyppi(mets‰);
	ruudut[10]->SetMaastotyyppi(tie);
	ruudut[11]->SetMaastotyyppi(mets‰);

	// Kartan piirto konsoliin.
	cout << "\nKartta: \n";

	cout << sizeof(ruudut) /  8;
	for (int i = 0; i < sizeof(ruudut) / 8; i++)
	{
		cout << ruudut[i]->_tyyppi.GetTyyppikirjain();
		// Pirkkaratkaisu rivivaihtoon, tied‰n. Kovakoodattu vaan luvuilla vastaamaan t‰t‰ teht‰v‰‰.
		// Jos jaksan ja ehdin niin mietin t‰h‰n hienomman ratkaisun.
		if (i == 3)
		{
			cout << "\n";
		}
		if (i == 3 + 4)
		{
			cout << "\n";
		}
	}

	cout << "\n \n";

	// Hahmon luonti ja sijoittaminen kartalle.
	Pelihahmo hilfred("Hilfred", 1, 70, 0);
	hilfred.SetSijainti(ruudut[0]);
	cout << "Pelihahmo " << hilfred._nimi << " luotu.\n" 
		<< "Taso: " << hilfred._level << "\n"
		<< "HP: " << hilfred._hp << "\n"
		<< "Rahat: " << hilfred._gold << "\n"
		<< "Sijainti kartan ruudukossa: " << hilfred._sijainti->GetX() << ", " << hilfred._sijainti->GetY() << "\n\n";

	// Vihollisten luonti ja sijoittaminen kartalle.
	// Vihollistyypit:
	Vihollistyyppi orkki(75, 50, 30);
	Vihollistyyppi vuorenpeikko(100, 60, 40);

	// Viholliset:
	Vihollinen Thrall(orkki.GetAlkuHP(), orkki.GetAlkuHP(), orkki.GetAlkuHyokkaysvoima(), orkki.GetAlkuPuolustusvoima());
	Thrall.SetSijainti(ruudut[1]);
	Vihollinen Durotan(orkki.GetAlkuHP(), orkki.GetAlkuHP(), orkki.GetAlkuHyokkaysvoima(), orkki.GetAlkuPuolustusvoima());
	Durotan.SetSijainti(ruudut[5]);
	Vihollinen Zuuzuu(vuorenpeikko.GetAlkuHP(), vuorenpeikko.GetAlkuHP(), vuorenpeikko.GetAlkuHyokkaysvoima(), vuorenpeikko.GetAlkuPuolustusvoima());
	Zuuzuu.SetSijainti(ruudut[9]);

	cout << "Viholliset luotu.\n\n";

	// Esineiden luonti ja sijoittaminen kartalle.
	// Miekka pelihahmolle.
	Taisteluvaruste* miekka =  new Taisteluvaruste(30, 10, "Bastardimiekka");
	hilfred.inventaario[0] = miekka;

	// Kartalla olevien objektien luonti ja sijoitus.
	MuuObjekti sormus(0, 50, "Heikko taikasormus");
	sormus.SetSijainti(ruudut[4]);
	MuuObjekti rohto(40, 10, "Rohto");
	rohto.SetSijainti(ruudut[1]);
	Taisteluvaruste haarniska(0, 20, "Rengashaarniska");
	haarniska.SetSijainti(ruudut[6]);

	cout << "Objektit luotu.\n\n";

	return 0;
}

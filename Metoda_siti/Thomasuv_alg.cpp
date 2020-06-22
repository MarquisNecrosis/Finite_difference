#include "Thomasuv_alg.h"



Thomasuv_alg::Thomasuv_alg()
{
}

vector<double> Thomasuv_alg::Vypocet(vector<double>& spodni, vector<double>& stredni, vector<double>& horni, vector<double>& prava_strana)
{
	vector <double> vysledek;
	int m = stredni.size();
	double pom;
	for (int i = 1; i < m; i++)
	{
		pom = spodni[i] / stredni[i-1];
		stredni[i] = stredni[i] - pom * horni[i - 1];
		prava_strana[i] = prava_strana[i] - pom * prava_strana[i - 1];
	}
	vysledek.push_back(prava_strana[m-1] / stredni[m-1]);
	for (int i = m-2; i >=0; i--)
	{
		vysledek.insert(vysledek.begin(),(prava_strana[i] - horni[i] * vysledek[0]) / stredni[i]);
	}
	return vysledek;
}


Thomasuv_alg::~Thomasuv_alg()
{
}

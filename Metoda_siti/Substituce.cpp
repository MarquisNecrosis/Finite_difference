#include "Substituce.h"
#include <iostream>


/*Substituce::Substituce()
{
}*/

Substituce::Substituce(double a, double b, double c, double d, double krok, double prvni, double posledni, double spodni_omezeni, double horni_omezeni)
{
	for (double i = spodni_omezeni + krok; i < horni_omezeni; i = i + krok)
	{
		mezikrok.push_back(i);
	}
	int m = size(mezikrok)-1;
	for (int i = 0; i <= m; i++)
	{
		spodni.push_back(-a*mezikrok[i] + b * mezikrok[i] * krok / 2);
		stredni.push_back(2 * a*mezikrok[i] - c * mezikrok[i] * (krok*krok));
		horni.push_back(-a*mezikrok[i] - b * mezikrok[i] * krok / 2);
		prava_strana.push_back(-d*mezikrok[i]);
	}
	prava_strana[0] = prava_strana[0] - spodni[0]*prvni;
	prava_strana[m] = prava_strana[m] - horni[m] * posledni;

	set_Spodni(spodni);
	set_Stredni(stredni);
	set_Horni(horni);
	set_Prava_strana(prava_strana);
	set_Mezikrok(mezikrok);
}

Substituce::~Substituce()
{
}

void Substituce::set_Horni(vector<double> value)
{
	horni.swap(value);
}

vector<double> Substituce::get_Horni()
{
	return horni;
}

void Substituce::set_Spodni(vector<double> value)
{
	spodni.swap(value);
}

vector<double> Substituce::get_Spodni()
{
	return spodni;
}

void Substituce::set_Stredni(vector<double> value)
{
	stredni.swap(value);
}

vector<double> Substituce::get_Stredni()
{
	return stredni;
}

void Substituce::set_Mezikrok(vector<double> value)
{
	mezikrok.swap(value);
}

vector<double> Substituce::get_Mezikrok()
{
	return mezikrok;
}

void Substituce::set_Prava_strana(vector<double> value)
{
	prava_strana.swap(value);
}

vector<double> Substituce::get_Prava_strana()
{
	return prava_strana;
}

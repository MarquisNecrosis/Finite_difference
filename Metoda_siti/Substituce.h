#pragma once
#include <vector>

using namespace std;

class Substituce
{
private:
	vector<double> horni, spodni, stredni,prava_strana;
	vector <double> mezikrok;
public:
	Substituce(double a, double b, double c, double d, double krok, double prvni, double posledni, double spodni_omezeni, double horni_omezeni);
	//void substituj(double a, double b,double c ,double d,double krok, double prvni, double posledni, double spodni_omezeni, double horni_omezeni);
	~Substituce();
	void set_Horni(vector<double> value);
	vector <double> get_Horni();
	void set_Spodni(vector<double> value);
	vector <double> get_Spodni();
	void set_Stredni(vector<double> value);
	vector <double> get_Stredni();
	void set_Mezikrok(vector<double> value);
	vector <double> get_Mezikrok();
	void set_Prava_strana(vector<double> value);
	vector <double> get_Prava_strana();
};


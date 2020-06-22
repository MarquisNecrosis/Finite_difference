#pragma once
#include <vector>
using namespace std;
class Thomasuv_alg
{
public:
	Thomasuv_alg();
	vector<double> Vypocet(vector<double>& spodni, vector<double>& stredni, vector<double>& horni, vector<double>& prava_strana);
	~Thomasuv_alg();
};


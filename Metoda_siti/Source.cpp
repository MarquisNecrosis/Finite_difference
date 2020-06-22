#include <iostream>
#include <vector>
#include <math.h>
#include "Substituce.h"
#include "Thomasuv_alg.h"

using namespace std;

int main()
{
	// parametry rovnice a*y''+ b*y' + c*y = d
	double druha_derivace, prvni_derivace, nulta_derivace, prava_strana;

	// okrajove podminky y(0) a y(1)
	double prvni, posledni;
	// zadani kde lezi x + po jakem kroku postupovat

	double dolni_omezeni, horni_omezeni, krok;

	bool rozh;

	cout << "Default example:" << endl << "y''-3y'-4y=0, where x is (0,1), y(0)=1, y(1)=1/e" << endl << "Press button 1" << endl << "For any equation press button 0" << endl;
	cin >> rozh;
	if (rozh == true)
	{
		druha_derivace = 1;
		prvni_derivace = -3;
		nulta_derivace = -4;
		prava_strana = 0;
		prvni = 1;
		posledni = 1 / exp(1);
		dolni_omezeni = 0;
		horni_omezeni = 1;
		cout << endl << "------------------------------------" << endl << endl;
		cout << "Enter a step: ";
		cin >> krok;
	}
	else
	{
		cout << "Enter the parameters in the equation : a*y''+b*y'+c*y=d" << endl;
		cout << "a = ";
		cin >> druha_derivace;
		cout << "b = ";
		cin >> prvni_derivace;
		cout << "c = ";
		cin >> nulta_derivace;
		cout << "d = ";
		cin >> prava_strana;
		cout << endl << "---------------------------" << endl << endl;;
		cout << "Enter the first boundary condition: ";
		cin >> prvni;
		cout << "Enter the second boundary condition: ";
		cin >> posledni;
		cout << "Enter a step: ";
		cin >> krok;
		cout << "Enter the lower limit x: ";
		cin >> dolni_omezeni;
		cout << "Enter the upper limit x: ";
		cin >> horni_omezeni;
	}

	// udelani substituce za derivace, vraci 3 diagonalni vektory + vektor prace strany
	Substituce Sub = Substituce(druha_derivace, prvni_derivace, nulta_derivace, prava_strana, krok, prvni, posledni, dolni_omezeni, horni_omezeni);	
	// ziskani vektoru
	vector <double> Spodni = Sub.get_Spodni();
	vector <double> Stredni = Sub.get_Stredni();
	vector <double> Horni = Sub.get_Horni();
	vector <double> Prava_strana = Sub.get_Prava_strana();

	// thomasuv algoritmus na vypocitani vysledku
	Thomasuv_alg thomas = Thomasuv_alg();
	vector<double> Vysledek = thomas.Vypocet(Spodni, Stredni, Horni, Prava_strana);
	cout << prvni << ' ';
	for (vector<double>::const_iterator i = Vysledek.begin(); i != Vysledek.end(); ++i)
		std::cout << *i << ' ';
	cout << posledni;
	cout << endl;
	system("PAUSE");
}
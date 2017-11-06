#include <io.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include "generator.h"

/*******************************************************************/
generator::generator(){}
/*******************************************************************/
generator::~generator()
{

for(int i=0 ; i<tablicaImion.size();i++)
{ 
	tablicaImion[i].clear();
}
tablicaImion.clear();
tablicaPlikow.clear();

}
/*******************************************************************/
void generator::wczytanie()
{
	_finddata_t danePliku;
	std::string b = "imiona/", linia = "";
	long long uchwyt = _findfirst("imiona/*.txt", &danePliku);//jak to zrobc lepiej ?
	int SzukamDalej = 1;
	if (uchwyt != -1)
	{
		while (SzukamDalej != -1)
		{
			std::ifstream plik;	//
			plik.open(b + danePliku.name, std::ios::in);//proba otwarcia pliku
			if (plik.good()) {//jesli otwarto
				tablicaPlikow.push_back(danePliku.name);
				std::vector< std::string> tmp;
				while (std::getline(plik, linia)) {//poki jest jakas linia w pliku
					tmp.push_back(linia);
				}
				tablicaImion.push_back(tmp);
				plik.close();
			}
			//std::cout << plik.is_open() << "\t" << std::endl;

			SzukamDalej = _findnext(uchwyt, &danePliku);
		}

		_findclose(uchwyt);
	}
	else
	{
		//std::string wyjatek = "Nie udalo sie wczytac imion\n"; 
		//throw wyjatek;
	}
}
/*******************************************************************/
std::string generator::losowanie()
{
	srand(time(NULL));
	int a = 0, b = 0;
	//std::cout << a << "\t" << b << "\n";
	if (tablicaPlikow.size() != 0) //sprawdzanie czy dlugosc wektora jest wiekszy od zera
	{	// drugi warunek 
		a = rand() % tablicaPlikow.size();
		b = rand() % tablicaImion[a].size();
		return tablicaImion[a][b];
	}
	else
	{
		std::string wyjatek = "Nie udalo sie wylosowac imiona\n";
		/*throw wyjatek;*/
		return wyjatek;
	}
}
/*******************************************************************/

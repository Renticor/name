#include "generator.h"
#include <io.h>
#include <fstream>
#include <iostream>
#include <ctime>

generator::generator()
{
	_finddata_t danePliku;
	std::string b = "imiona/", linia;
	long uchwyt = _findfirst("imiona/*.txt", &danePliku);
	int SzukamDalej = 1;
	int i = 0;
	while (SzukamDalej != -1)
	{
		i++;
		std::ifstream plik;	//
		plik.open(b + danePliku.name, std::ios::in);
		tablicaPlikow.push_back(danePliku.name);
		int j = 0;
		if (plik.good()) {
			std::vector< std::string> tmp;
			while (std::getline(plik, linia)) {
				//std::cout << j << "\t" << linia << "\n";
				tmp.push_back(linia);
				j++;
			}
			tablicaImion.push_back(tmp);

		}
		//std::cout << plik.is_open() << "\t" << std::endl;
		plik.close();
		SzukamDalej = _findnext(uchwyt, &danePliku);
	}
	//uchwyt = _findfirst("imiona/*.txt", &danePliku);

	/*
	for (i = 0; i < tablicaImion.size(); i++)
	{
	for(int k=0;k<tablicaImion[i].size();k++)
	{
	std::cout << tablicaImion[i][k] << "\t" << i << "\t" <<k<< std::endl;
	}
	}*/
	_findclose(uchwyt);



}

std::string generator::losowanie()
{
	srand(time(NULL));
	int a, b;
	a=rand()%tablicaPlikow.size();
	b = rand() % tablicaImion[a].size();
	std::cout << a << "\t" << b << "\n";
	return tablicaImion[a][b];

}


generator::~generator()
{
}

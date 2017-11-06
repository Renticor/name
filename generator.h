#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H
#include <string>
#include <vector>

class generator
{
private:
	std::vector<std::string> tablicaPlikow;
	std::vector<std::vector<std::string>> tablicaImion;
public:
	generator();
	~generator();
	void wczytanie();//zaladowanie do wektorow imion 
	std::string losowanie();//zwracajaca jedno slowo wylosowane
};
#endif

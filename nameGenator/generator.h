
#pragma once
#include <string>
#include <vector>

class generator
{
private:
	std::vector<std::string> tablicaPlikow;
	std::vector<std::vector<std::string>> tablicaImion;
public:
	generator();
	std::string losowanie();
	~generator();
};


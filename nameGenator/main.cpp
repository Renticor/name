#include <iostream>
#include "generator.h"
#include <io.h>
#include <fstream>


int main()
{
	generator g;
	std::cout<<g.losowanie();
	std::cin.ignore();
	std::getchar();
	return 0;
}
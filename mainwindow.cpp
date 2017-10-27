#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <io.h>
#include <fstream>
#include <iostream>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	
    ui->setupUi(this);
	try {
		generator g;
	}
	catch (std::string w)
	{

		std::cout << w;
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   
    std::string text= g.losowanie();
   QString text1=QString::fromStdString(text);
     ui->label->setText(text1);
}

void generator::wczytanie()
{
	_finddata_t danePliku;
	std::string b = "imiona/", linia="";
	long long uchwyt = _findfirst("imiona/*.txt", &danePliku);
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
				while (std::getline(plik, linia)) {
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
		std::string wyjatek = "Nie udalo sie wczytac imion\n"; 
		throw wyjatek;
	}
}

generator::generator()
{
	wczytanie();
}

std::string generator::losowanie()
{
    srand(time(NULL));
    int a=0, b=0;
    //std::cout << a << "\t" << b << "\n";
	if (tablicaPlikow.size() != 0 && tablicaImion[a].size() != 0) {
		a = rand() % tablicaPlikow.size();
		b = rand() % tablicaImion[a].size();
		return tablicaImion[a][b];
	}
	else
	{
		std::string wyjatek = "Nie udalo sie wylosowac imiona\n";
		throw wyjatek;
	}
}


generator::~generator()
{
}

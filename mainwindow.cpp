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
	generator g;
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


generator::generator()
{
    _finddata_t danePliku;
    std::string b = "imiona/", linia;
    long long uchwyt = _findfirst("imiona/*.txt", &danePliku);
    int SzukamDalej = 1;
    int i = 0,j=0;
	if (uchwyt != -1)
	{
		while (SzukamDalej != -1)
		{
			i++;
			std::ifstream plik;	//
			plik.open(b + danePliku.name, std::ios::in);
			if (plik.good()) {
				tablicaPlikow.push_back(danePliku.name);
				std::vector< std::string> tmp;
				while (std::getline(plik, linia)) {
					//std::cout << "\t" << linia << "\n";
					tmp.push_back(linia);
					j++;
				}
				tablicaImion.push_back(tmp);
				plik.close();
			}
			//std::cout << plik.is_open() << "\t" << std::endl;

			SzukamDalej = _findnext(uchwyt, &danePliku);
		}

		_findclose(uchwyt);
	}
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

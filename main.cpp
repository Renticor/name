#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "pl_PL");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generator.h"

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
	g.wczytanie();
    std::string text= g.losowanie();
   QString textQt=QString::fromStdString(text);
     ui->label->setText(textQt);

}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>

namespace Ui {
class MainWindow;
}


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


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
	generator g;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H

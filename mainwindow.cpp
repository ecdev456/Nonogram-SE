#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "createwindow.h"
//#include "ui_createwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    CreateWindow createWin;
    createWin.setModal(true);
    createWin.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}





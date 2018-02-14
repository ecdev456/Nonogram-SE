#include "mainwindow.h"
#include "ui_mainwindow.h"


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

//create window button was pushed
void MainWindow::on_pushButton_clicked()
{
    CreateWindow createWin;
    createWin.setModal(true);
    createWin.exec();
}

//exit button on main screen
void MainWindow::on_pushButton_4_clicked()
{
    close();
}





#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "removewindow.h"
#include "createwindow.h"

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
void MainWindow::on_createButton_clicked()
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

//remove button was pressed
void MainWindow::on_removeButton_clicked()
{
    RemoveWindow removeWin;
    removeWin.setModal(true);
    removeWin.exec();
}

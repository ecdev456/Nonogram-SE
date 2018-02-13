#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nextdialog.h"

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
   NextDialog editWindow;
   editWindow.setModal(true);
   editWindow.exec();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkout.h"
//#include "Model.h"
#include <iostream>
using namespace std;

//Model setData;

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
    QObject * senderObj = sender();
       if(senderObj->isWidgetType())
       {
           QPushButton * button = qobject_cast<QPushButton*>(senderObj);
                   if (button)
                   {
                       //sends student id info to model
                       QString studentID = ui->studentID->toPlainText();
                       string id = studentID.toStdString();
                       //need a setter from model
                       cout << "id entered " << id << endl;

                       //sends book number info to model
                       QString bookNum = ui->bookNum->toPlainText();
                       string bookNumber = bookNum.toStdString();
                       //need a setter from model
                       cout << "Book Number entered " << bookNumber << endl;

                       Checkout checkout;
                       checkout.setModal(true);
                       checkout.exec();

                       ui->studentID->setText("");
                       ui->bookNum->setText("");


                   }
       }

}

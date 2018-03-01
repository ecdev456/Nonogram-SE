#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkout.h"
#include "Model.h"
#include <iostream>
#include <QTimer>
#include <QDateTime>
#include <QObject>
using namespace std;


Library dataCollection;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->timeEdit->setTime(QTime::currentTime());

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(updateTime()));
    timer->start(4000);

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
                       dataCollection.SetStudentInfo(id);
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


void MainWindow::updateTime()
{

    QDate currentD = QDate::currentDate();
    QString cDate = currentD.toString();
    string dateA = cDate.toStdString();
    //string reminderInfo;
    //cout << dateA << endl;
    //int timeToIterate = DataCollection.GetNumData();
    ui->timeEdit->setTime(QTime::currentTime());

    QTime cTime = QTime::currentTime();
    QString timeString = cTime.toString();
    string timeA = timeString.toStdString();


    }

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkout.h"
#include "Model.h"
//#include "finallibrary.h"

#include <QTimer>
#include <QDateTime>
#include <iostream>
using namespace std;

Library TopLayer;
Library Edwin;
//FinalLibrary Collect;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    string bookInventoryInfo;
    for(int i = 0; i < 5; i++)
    {
        //only prints out available books
        if(TopLayer.GetBookInstance(i) == 1)
        {
            bookInventoryInfo += to_string(i+1) + "  " + TopLayer.GetBook(i)  + " - " + TopLayer.GetAuthor(i) + "\n";
        }

    }

    //prints out inventory onto screen
    ui->bookInventory->setPlainText(QString::fromStdString(bookInventoryInfo));
    bookInventoryInfo = "";
    //prints out time
    ui->timeEdit->setTime(QTime::currentTime());

    //timer to update current time
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
    string TimeDue;
    QObject * senderObj = sender();
       if(senderObj->isWidgetType())
       {
           QPushButton * button = qobject_cast<QPushButton*>(senderObj);
                   if (button)
                   {
                       //sends student id info to model
                       QString studentID = ui->studentID->toPlainText();
                       string id = studentID.toStdString();
                       Edwin.SetTempName(id);
                       //need a setter from model
                       QString bookNum = ui->bookNum->toPlainText();
                       int bookID = bookNum.toInt();
                       Edwin.SetTempBook(bookID);
                      // BookData = TopLayer.GetBookInfo(bookNumber);



                      // TimeDue = "6:00 PM";
                       // Edwin.SetTempTime(TimeDue);
                       cout << "id entered " << id << endl;

                       QTime check = QTime::currentTime();
                       //set to 7200 for 2 hours
                       QTime checkOutTime = check.addSecs(60);
                       QString timeC = checkOutTime.toString();
                       string cOutTime = timeC.toStdString();

                       TopLayer.SetTimeDue(cOutTime);
                       Edwin.SetTempTime(cOutTime);

                     //  Collect.MakeReminder("Desctest", "EdwinTITLE", "6:00PM", "1/12/18");
                   //    cout << "Test" << endl;
                   //        Collect.CheckIN(1);
                       //sends book number info to model
                       //need a setter from model
                    //   cout << "Book Number entered " << bookNumber << endl;

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

    ui->timeEdit->setTime(QTime::currentTime());


    QTime cTime = QTime::currentTime();
    QString timeString = cTime.toString();
    string timeA = timeString.toStdString();

    for(int i = 0; i < 5; i++)
    {
        string timeD = TopLayer.GetTimeDue(i);
        if(timeD.compare(0,5, timeA,0,5) == 0 )
        {
            //should trigger reminder window
            //automatically checks in books
            TopLayer.Checkin(i);
            cout << "book was checked back in" << endl;
        }
    }


}



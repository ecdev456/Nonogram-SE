#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "removewindow.h"
#include "createwindow.h"
#include "updatewindow.h"
#include "reminder.h"
#include <QTimer>
#include "model.h"

Model TempE;
Model TempR;
Model updateModel;

static string test1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->currentTimeBox->setTime(QTime::currentTime());

   QTimer *timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this, SLOT(updateTime()));
   timer->start(4000);

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
//  DO NOT REMOVE THESE
         TempE.SetTitle(DataCollection.GetTitle(DataCollection.GetNumData()-1));
         TempE.SetDesc(DataCollection.GetDesc(DataCollection.GetNumData()-1));
         TempE.SetTime(DataCollection.GetTime(DataCollection.GetNumData()-1));
         TempE.SetDate(DataCollection.GetDate(DataCollection.GetNumData()-1));
         TempE.CreateReminder();

    //Purpose:
    //Each Time Create is Ran, we need to update the Object TempE for Remove
    // 'DataCollection.GetNumData() - 1'is to get the latest created Reminder and passing it to TempE
    // TempE.CreateReminder will update TempE's NumData

         updateModel.SetTitle(DataCollection.GetTitle(DataCollection.GetNumData()-1));
         updateModel.SetDesc(DataCollection.GetDesc(DataCollection.GetNumData()-1));
         updateModel.SetTime(DataCollection.GetTime(DataCollection.GetNumData()-1));
         updateModel.SetDate(DataCollection.GetDate(DataCollection.GetNumData()-1));
         updateModel.CreateReminder();

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

    updateModel.SetNumData(0); //Set the Remove Object list to same for Update List
   // DataCollection.SetNumData(0);
    for(int i = 0; i < TempE.GetNumData(); i++)
    {
        updateModel.SetTitle(TempE.GetTitle(i));
        updateModel.SetDesc(TempE.GetDesc(i));
        updateModel.SetTime(TempE.GetTime(i));
        updateModel.SetDate(TempE.GetDate(i));
        updateModel.CreateReminder();

    }


}

void MainWindow::on_pushButton_2_clicked()
{

    UpdateWindow updateWin;
    updateWin.setModal(true);
    updateWin.exec();
    TempE.SetNumData(0);
    for(int i = 0; i < updateModel.GetNumData(); i++)
    {
        TempE.SetTitle(updateModel.GetTitle(i));
        TempE.SetDesc(updateModel.GetDesc(i));
        TempE.SetTime(updateModel.GetTime(i));
        TempE.SetDate(updateModel.GetDate(i));
        TempE.CreateReminder();

    }
    DataCollection.SetNumData(0);
    for(int i = 0; i < updateModel.GetNumData(); i++)
    {
        DataCollection.SetTitle(updateModel.GetTitle(i));
        DataCollection.SetDesc(updateModel.GetDesc(i));
        DataCollection.SetTime(updateModel.GetTime(i));
        DataCollection.SetDate(updateModel.GetDate(i));
        DataCollection.CreateReminder();

    }

}

void MainWindow::updateTime()
{

    QDate currentD = QDate::currentDate();
    QString cDate = currentD.toString();
    string dateA = cDate.toStdString();
    string reminderInfo;

    int timeToIterate = DataCollection.GetNumData();
    ui->currentTimeBox->setTime(QTime::currentTime());

    QTime cTime = QTime::currentTime();
    QString timeString = cTime.toString();
    string timeA = timeString.toStdString();


    for(int i = 0; i < timeToIterate; i++)
    {
        string timeCompare = DataCollection.GetTime(i);
        string dateCompare = DataCollection.GetDate(i);

        if(dateCompare.compare(4,11,dateA,4,11)== 0)
        {
            if (timeCompare.compare(0,5,timeA,0,5) == 0)
            {
                TempR.SetTitle(DataCollection.GetTitle(i));
                TempR.SetDesc(DataCollection.GetDesc(i));
                TempR.SetTime(DataCollection.GetTime(i));
                TempR.SetDate(DataCollection.GetDate(i));
                TempR.CreateReminder();
                string test = "hello";
                Reminder reminderWin;
                reminderWin.setModal(true);
                reminderWin.exec();
                DataCollection.DeleteReminder(i);   // This reminder has been fulfilled.
                TempE.DeleteReminder(i);
                updateModel.DeleteReminder(i);

                //Udate Delete Object
                //Update Update Object


            }
        }
    }

}




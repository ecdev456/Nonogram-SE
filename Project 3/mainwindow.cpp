#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "removewindow.h"
#include "createwindow.h"
#include "model.h"

Model TempE;
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

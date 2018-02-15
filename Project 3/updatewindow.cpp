#include "updatewindow.h"
#include "ui_updatewindow.h"

UpdateWindow::UpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateWindow)
{
    ui->setupUi(this);
}

UpdateWindow::~UpdateWindow()
{
    delete ui;
}

void UpdateWindow::on_pushButton_2_clicked()
{
    close();
}

void UpdateWindow::on_pushButton_clicked()
{
    close();
}

// If on UpdateWindow, user inputs: an integer

/* for (int i = 0; i < 20; i++)
{
  if(Userinput
 *TitlePtr = DataGrab.getTitleArray[i]; //Pointer that points to each element in the TitleArray[]
 *DatePtr = DataGrab.getDateArray[i];   //Pointer that points to each element in the DateArray[]
 *TimePtr = DataGrab.getTimeArray[i];   //Pointer that points to each element in the TimeArray[]
 *DescPtr = DataGrab.getDescArray[i];   //Pointer that points to each element in the DescArray[]
  //Pull up window that has event showing all the user's inputs for the Event Title, Date, Time, and Description.
  //Then gives the user the option to edit the strings in each of the array element.
  //User either clicks 'DONE' to save edit or 'CANCEL'to cancel edit.
  i++; //moves on to the next element in the array.

}
//The For Loop above is just a test. Hopefully it can at least give us an idea on how to approach getting our Update to work

//Below is also another test
void UpdateWindow::on_reminderTitle_editingFinished()
{
   //Edit String QSignal Button(?)
    if(senderObj->isWidgetType())
    {
        QPushButton * button = qobject_cast<QPushButton*>(senderObj);

                    if(tData.length() == 0)
                    {
                        DataCollection.SetTitle("No Title");

                    }
}
void UpdateWindow::Time_editingFinished()
{
    //Edit String QSignal Button(?)
    QObject * senderObj = sender();
    if(senderObj->isWidgetType())
    {
        //QStringEditButton * button = qobject_cast<QPushButton*>(senderObj);


                    if(dData.length() == 0)
                    {
                        DataCollection.SetDate("2/12/2018");
                    }
}
void UpdateWindow::on_Date_editingFinished()
{
    //Edit String QSignal Button(?) goes here
    if(senderObj->isWidgetType())
    {
        //QStringEditButton * button = qobject_cast<QPushButton*>(senderObj);


                    if(tmData.length() == 0)
                    {
                        DataCollection.SetTime("12:00 AM");
                    }
}

void UpdateWindow::on_reminderDescription_editingFinished()
{
   //Edit String QSignal Button(?) goes here
    if(senderObj->isWidgetType())
    {
        //QStringEditButton * button = qobject_cast<QPushButton*>(senderObj);

                    if(deData.length() == 0)
                    {
                        DataCollection.SetDesc("No Description");
                    }

                   */

                   // tData = "";

                    //cout << "edit finished" << endl;
                //}
    //}
    //close();

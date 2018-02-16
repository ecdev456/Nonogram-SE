#include "removewindow.h"
#include "ui_removewindow.h"
//#include "model.h"

using namespace std;

string info, info2;
RemoveWindow::RemoveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveWindow)
{
    ui->setupUi(this);

    // Here is where the loop is happening.
for(int i = 0; i < TempE.GetNumData(); i++)
{
    info2 = to_string(i+1);
    info += "Reminder ID: " + info2+ "   Title: " + TempE.GetTitle(i) + ", Date: " + TempE.GetDate(i) + ", Time: " + TempE.GetTime(i) + ", Desc: " + TempE.GetDesc(i) +"\n";
 }
// End loop here

ui->printInfo->setText(QString::fromStdString((info)));
info = "";

}

RemoveWindow::~RemoveWindow()
{
    delete ui;
}

//when cancel button has been clicked
void RemoveWindow::on_cancelRemove_clicked()
{
    close();
}

//done button has been pressed
void RemoveWindow::on_doneRemove_clicked()
{
    close();
}

void RemoveWindow::on_removeChoice_editingFinished()
{
    int choiceRemove = ui->removeChoice->text().toInt();
    TempE.DeleteReminder(choiceRemove); //Removes it from this object
    DataCollection.DeleteReminder(choiceRemove); //Updates this object also
}

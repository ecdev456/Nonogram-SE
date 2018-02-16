#include "updatewindow.h"
#include "ui_updatewindow.h"
#include "model.h"

string infoUpdate, infoUpdate2;
int c = updateModel.GetChoice();
static int choiceEntered;

UpdateWindow::UpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateWindow)
{
    ui->setupUi(this);


    for(int i = 0; i < updateModel.GetNumData(); i++)
    {
        infoUpdate2 = to_string(i+1);
        infoUpdate += "Reminder ID: " + infoUpdate2+ "   Title: " + updateModel.GetTitle(i) + ", Date: " + updateModel.GetDate(i) + ", Time: " + updateModel.GetTime(i) + ", Desc: " + updateModel.GetDesc(i) +"\n";
     }
    // End loop here

    ui->updateInfo->setText(QString::fromStdString((infoUpdate)));
    infoUpdate = "";
}

UpdateWindow::~UpdateWindow()
{
    delete ui;
}

void UpdateWindow::on_cancelUpdate_clicked()
{
    close();
}

void UpdateWindow::on_doneUpdate_clicked()
{
    choiceEntered = updateModel.GetChoice();
    string title = updateModel.GetTitle(choiceEntered-1);
    string desc = updateModel.GetDesc(choiceEntered-1);
    QString time1 = QString::fromStdString(updateModel.GetTime(choiceEntered-1));
    QString date1 = QString::fromStdString(updateModel.GetDate(choiceEntered-1));

    ui->updateTitle->setText(QString::fromStdString(title));
    ui->updateTime->setTime(QTime::fromString(time1));
    ui->updateDate->setDate(QDate::fromString(date1));
    ui->updateDesc->setText(QString::fromStdString(desc));

}

void UpdateWindow::on_updateChoice_editingFinished()
{
    int choiceEntered = ui->updateChoice->text().toInt();
    updateModel.SetChoice(choiceEntered);

}

void UpdateWindow::on_reminderDone_clicked()
{
    QObject * senderObj = sender();
    if(senderObj->isWidgetType())
    {
        QPushButton * button = qobject_cast<QPushButton*>(senderObj);
                if (button)
                {
                    choiceEntered = updateModel.GetChoice();
                    int num = choiceEntered;
                    QString titleName = ui->updateTitle->text();
                    string titleT = titleName.toStdString();
                    updateModel.EditTitle(num-1, titleT);

                    QDate dateT = ui->updateDate->date();
                    QString dateI = dateT.toString();
                    string date = dateI.toStdString();
                    updateModel.EditDate(num-1, date);

                    QTime timeT = ui->updateTime->time();
                    QString timeI = timeT.toString();
                    string time = timeI.toStdString();
                    updateModel.EditTime(num-1, time);

                    QString titleDes = ui->updateDesc->text();
                    string titleD = titleDes.toStdString();
                    updateModel.EditDesc(num-1, titleD);




                }
    }
    close();
}

void UpdateWindow::on_updateCancel_clicked()
{
    close();
}

#include "updatewindow.h"
#include "ui_updatewindow.h"
//#include "model.h"

string infoUpdate, infoUpdate2;
int c = updateModel.GetChoice();

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
    string title = updateModel.GetTitle(c);
    string desc = updateModel.GetDesc(c);
    QString time1 = QString::fromStdString(updateModel.GetTime(c));
    QString date1 = QString::fromStdString(updateModel.GetDate(c));

    //cout << "title: " << data1.to << endl;

    ui->updateTitle->setText(QString::fromStdString(title));
    ui->updateTime->setTime(QTime::fromString(time1));
    ui->updateDate->setDate(QDate::fromString(date1));
    ui->updateDesc->setText(QString::fromStdString(desc));

}

void UpdateWindow::on_updateChoice_editingFinished()
{
    int choiceEntered = ui->updateChoice->text().toInt();
    updateModel.SetChoice(choiceEntered);
    //updateModel.EditReminder(choiceEntered);
}

void UpdateWindow::on_reminderDone_clicked()
{
    QObject * senderObj = sender();
    if(senderObj->isWidgetType())
    {
        QPushButton * button = qobject_cast<QPushButton*>(senderObj);
                if (button)
                {
                    int num = c;
                    cout << "num: " << num << endl;
                    QString titleName = ui->updateTitle->text();
                    string titleT = titleName.toStdString();
                    //cout << titleT << endl;
                    //updateMo2.SetTitle(titleT);
                    updateModel.EditTitle(num, titleT);
                    //updateMo2.CreateReminder()

                }
    }
    close();
}

void UpdateWindow::on_updateCancel_clicked()
{
    close();
}

#ifndef REMINDER_H
#define REMINDER_H

#include <QDialog>
//#include "model.h"
#include "mainwindow.h"
#include <iostream>
using namespace std;

//extern Model TempR; //For settting up the Reminder

namespace Ui {
class Reminder;
}

class Reminder : public QDialog
{
    Q_OBJECT

public:

    explicit Reminder(QWidget *parent=0);
    ~Reminder();
    void setInfo(const string& i);

private slots:


private:
    Ui::Reminder *ui;

};

#endif // REMINDER_H

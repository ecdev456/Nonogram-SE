#ifndef NEXTDIALOG_H
#define NEXTDIALOG_H

#include <QDialog>

namespace Ui {
class NextDialog;
}

class NextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NextDialog(QWidget *parent = 0);
    ~NextDialog();

private:
    Ui::NextDialog *ui;
};

#endif // NEXTDIALOG_H

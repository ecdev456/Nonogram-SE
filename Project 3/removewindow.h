#ifndef REMOVEWINDOW_H
#define REMOVEWINDOW_H

#include <QDialog>

namespace Ui {
class RemoveWindow;
}

class RemoveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveWindow(QWidget *parent = 0);
    ~RemoveWindow();

private:
    Ui::RemoveWindow *ui;
};

#endif // REMOVEWINDOW_H

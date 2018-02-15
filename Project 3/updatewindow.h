#ifndef UPDATEWINDOW_H
#define UPDATEWINDOW_H

#include <QDialog>

namespace Ui {
class UpdateWindow;
}

class UpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateWindow(QWidget *parent = 0);
    ~UpdateWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::UpdateWindow *ui;
};

#endif // UPDATEWINDOW_H

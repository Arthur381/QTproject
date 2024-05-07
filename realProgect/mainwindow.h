#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calendarmc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    calendarMC cal;//创建了一个实例化对象，在mainwindow.cpp 中 show

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calBT_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

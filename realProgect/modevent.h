#ifndef MODEVENT_H
#define MODEVENT_H
#include "calendarmc.h"

#include <QWidget>

namespace Ui {
class ModEvent;
}

class ModEvent : public QWidget
{
    Q_OBJECT

public:
    explicit ModEvent(QWidget *parent = nullptr);
    ~ModEvent();
    //virtual void keyPressEvent(QKeyEvent * event);

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_delete_clicked();




private:
    Ui::ModEvent *ui;
    void PrintP();
    //void PrintOne(AEventInfo);不需要
    //calendarMC * m_ptrcalendar;
};

#endif // MODEVENT_H

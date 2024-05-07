#ifndef CALENDARMC_H
#define CALENDARMC_H

#include <QWidget>

namespace Ui {
class calendarMC;
}

class calendarMC : public QWidget
{
    Q_OBJECT

public:
    explicit calendarMC(QWidget *parent = nullptr);
    ~calendarMC();

private:
    Ui::calendarMC *ui;
};

#endif // CALENDARMC_H

#ifndef DAILYMSY_H
#define DAILYMSY_H

#include <QWidget>

namespace Ui {
class dailyMSY;
}

class dailyMSY : public QWidget
{
    Q_OBJECT

public:
    explicit dailyMSY(QWidget *parent = nullptr);
    ~dailyMSY();

private:
    Ui::dailyMSY *ui;
};

#endif // DAILYMSY_H

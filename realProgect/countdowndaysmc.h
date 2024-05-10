#ifndef COUNTDOWNDAYSMC_H
#define COUNTDOWNDAYSMC_H

#include <QWidget>

namespace Ui {
class CountDownDaysMC;
}

class CountDownDaysMC : public QWidget
{
    Q_OBJECT

public:
    explicit CountDownDaysMC(QWidget *parent = nullptr);
    ~CountDownDaysMC();

private:
    Ui::CountDownDaysMC *ui;
};

#endif // COUNTDOWNDAYSMC_H

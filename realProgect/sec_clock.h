#ifndef SEC_CLOCK_H
#define SEC_CLOCK_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class sec_clock;
}

class sec_clock : public QWidget
{
    Q_OBJECT

public:
    explicit sec_clock(QWidget *parent = nullptr);
    ~sec_clock();

    QTimer timer,timer_cur;
    QTime time;
    QDateTime curDTime;

public slots:
    void changetheme();


private slots:
    void on_start_clicked();
    void timeout_slot();//计时开始的槽函数
    void showcurtime();

    void on_pause_clicked();

    void on_clear_clicked();

    void on_setpoint_clicked();

private:
    Ui::sec_clock *ui;
};

#endif // SEC_CLOCK_H

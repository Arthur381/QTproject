#ifndef ALARM_H
#define ALARM_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QCheckBox>

namespace Ui {
class alarm;
}

class alarm : public QWidget
{
    Q_OBJECT

public:
    explicit alarm(QWidget *parent = nullptr);
    ~alarm();

    QTimer timer_cur,timerunner;
    QDateTime curDTime;

private slots:
    void showcurtime();
    void checktime();

    void on_set1_clicked();
    void on_set2_clicked();
    void on_set3_clicked();
    void on_set4_clicked();
    void on_set5_clicked();

    void on_check1_clicked();
    void on_check2_clicked();
    void on_check3_clicked();
    void on_check4_clicked();
    void on_check5_clicked();

private:
    Ui::alarm *ui;
};

#endif // ALARM_H

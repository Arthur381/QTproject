#ifndef CLOCKHZJ_H
#define CLOCKHZJ_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class clockHZJ;
}

class clockHZJ : public QWidget
{
    Q_OBJECT

public:
    explicit clockHZJ(QWidget *parent = nullptr);
    ~clockHZJ();

    QTimer timer_cur;
    QDateTime curDTime;


    void paintEvent(QPaintEvent *e);

signals:
    void themeChanged();


private slots:
    //void on_pushButton_3_clicked();

    void on_sec_clock_clicked();

    void on_rsec_clo_clicked();

    void on_alarms_clicked();

    void showcurtime();


public slots:
    void changetheme();

private:
    Ui::clockHZJ *ui;
};

#endif // CLOCKHZJ_H

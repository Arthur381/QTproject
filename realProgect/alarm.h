#ifndef ALARM_H
#define ALARM_H

#include <QWidget>

namespace Ui {
class alarm;
}

class alarm : public QWidget
{
    Q_OBJECT

public:
    explicit alarm(QWidget *parent = nullptr);
    ~alarm();

private:
    Ui::alarm *ui;
};

#endif // ALARM_H

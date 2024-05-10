#ifndef MODEVENT_H
#define MODEVENT_H

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

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::ModEvent *ui;
};

#endif // MODEVENT_H

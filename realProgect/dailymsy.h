#ifndef DAILYMSY_H
#define DAILYMSY_H

#include <QWidget>
#include <QAbstractButton>

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

public slots:

private slots:
    void on_iNote_clicked();
    void on_allIn_clicked();
};

#endif // DAILYMSY_H

#ifndef R_CLOCK_H
#define R_CLOCK_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class r_clock;
}

class r_clock : public QWidget
{
    Q_OBJECT

public:
    explicit r_clock(QWidget *parent = nullptr);
    ~r_clock();


    void paintEvent(QPaintEvent *e);
private:
    Ui::r_clock *ui;
    QTimer* p_timer;
    int total;
    void display_number();

private slots:
    void update();
    void on_pushButton_clicked();
    void hourChanged();
    void minChanged();
    void secChanged();
    void on_end_clicked();
    void on_pause_clicked();

public slots:
    void changetheme();
};


#endif // R_CLOCK_H

#ifndef SCHEDULEMSY_H
#define SCHEDULEMSY_H

#include <QWidget>

namespace Ui {
class scheduleMSY;
}

class scheduleMSY : public QWidget
{
    Q_OBJECT

public:
    explicit scheduleMSY(QWidget *parent = nullptr);
    ~scheduleMSY();

private:
    Ui::scheduleMSY *ui;
};

#endif // SCHEDULEMSY_H

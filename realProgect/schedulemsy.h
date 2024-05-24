#ifndef SCHEDULEMSY_H
#define SCHEDULEMSY_H

#include <QWidget>
#include "coursemsy.h"
//把course中的表引进到这里面，将来在tablewidgt中显示

namespace Ui {
class scheduleMSY;
}

class scheduleMSY : public QWidget
{
    Q_OBJECT

public:
    explicit scheduleMSY(QWidget *parent = nullptr);

    void Print();
    ~scheduleMSY();

private:
    Ui::scheduleMSY *ui;
};

#endif // SCHEDULEMSY_H

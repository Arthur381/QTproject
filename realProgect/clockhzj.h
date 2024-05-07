#ifndef CLOCKHZJ_H
#define CLOCKHZJ_H

#include <QWidget>

namespace Ui {
class clockHZJ;
}

class clockHZJ : public QWidget
{
    Q_OBJECT

public:
    explicit clockHZJ(QWidget *parent = nullptr);
    ~clockHZJ();

private:
    Ui::clockHZJ *ui;
};

#endif // CLOCKHZJ_H

#ifndef FOODIRO_H
#define FOODIRO_H

#include <QWidget>

namespace Ui {
class FoodIro;
}

class FoodIro : public QWidget
{
    Q_OBJECT

public:
    explicit FoodIro(QWidget *parent = nullptr);
    ~FoodIro();

private:
    Ui::FoodIro *ui;
};

#endif // FOODIRO_H

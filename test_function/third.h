#ifndef THIRD_H
#define THIRD_H

#include <QDialog>

namespace Ui {
class third;
}

class third : public QDialog
{
    Q_OBJECT

public:
    explicit third(QWidget *parent = nullptr);
    ~third();

private:
    Ui::third *ui;
};

#endif // THIRD_H

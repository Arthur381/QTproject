#ifndef DAILYMSY2_H
#define DAILYMSY2_H

#include <QDialog>

namespace Ui {
class dailymsy2;
}

class dailymsy2 : public QDialog
{
    Q_OBJECT

public:
    explicit dailymsy2(QWidget *parent = nullptr);
    ~dailymsy2();

private:
    Ui::dailymsy2 *ui;
};

#endif // DAILYMSY2_H

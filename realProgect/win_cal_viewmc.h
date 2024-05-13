#ifndef WIN_CAL_VIEWMC_H
#define WIN_CAL_VIEWMC_H

#include <QWidget>

namespace Ui {
class win_cal_viewMC;
}

class win_cal_viewMC : public QWidget
{
    Q_OBJECT

public:
    explicit win_cal_viewMC(QWidget *parent = nullptr);
    ~win_cal_viewMC();

private:
    Ui::win_cal_viewMC *ui;
};

#endif // WIN_CAL_VIEWMC_H

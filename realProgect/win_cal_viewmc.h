#ifndef WIN_CAL_VIEWMC_H
#define WIN_CAL_VIEWMC_H

#include <QWidget>
#include<QDate>

namespace Ui {
class win_cal_viewMC;
}

class win_cal_viewMC : public QWidget
{
    Q_OBJECT

public:
    explicit win_cal_viewMC(QWidget *parent = nullptr);
    static win_cal_viewMC *ptrWCV;//类内声明的静态指针
    static win_cal_viewMC *getinstance(){//单例化，希望eves也单例化
        if(nullptr==ptrWCV){
            ptrWCV=new win_cal_viewMC;
        }
        return ptrWCV;
    }
    ~win_cal_viewMC();




public:
    QDate curdate;

private:
    Ui::win_cal_viewMC *ui;
    void FindAndPrint();
};

#endif // WIN_CAL_VIEWMC_H

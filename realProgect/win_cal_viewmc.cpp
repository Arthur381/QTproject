#include "win_cal_viewmc.h"
#include "ui_win_cal_viewmc.h"

win_cal_viewMC* win_cal_viewMC::ptrWCV = nullptr;//在类外初始化

win_cal_viewMC::win_cal_viewMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::win_cal_viewMC)
{
    ui->setupUi(this);
}

void FindAndPrint(){
    //从数据库中找到属于这一天的事件，然后通过“有趣的语句组合起来”



}




win_cal_viewMC::~win_cal_viewMC()
{
    delete ui;
}

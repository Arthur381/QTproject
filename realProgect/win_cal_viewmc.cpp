#include "win_cal_viewmc.h"
#include "ui_win_cal_viewmc.h"

win_cal_viewMC::win_cal_viewMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::win_cal_viewMC)
{
    ui->setupUi(this);
}

win_cal_viewMC::~win_cal_viewMC()
{
    delete ui;
}

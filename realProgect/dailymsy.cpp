#include "dailymsy.h"
#include "ui_dailymsy.h"

dailyMSY::dailyMSY(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dailyMSY)
{
    ui->setupUi(this);
}

dailyMSY::~dailyMSY()
{
    delete ui;
}

#include "schedulemsy.h"
#include "ui_schedulemsy.h"

scheduleMSY::scheduleMSY(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::scheduleMSY)
{
    ui->setupUi(this);
}

scheduleMSY::~scheduleMSY()
{
    delete ui;
}

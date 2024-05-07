#include "calendarmc.h"
#include "ui_calendarmc.h"

calendarMC::calendarMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::calendarMC)
{
    ui->setupUi(this);
}

calendarMC::~calendarMC()
{
    delete ui;
}

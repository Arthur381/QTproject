#include "calendarmc.h"
#include "ui_calendarmc.h"
#include "modevent.h"
#include "countdowndaysmc.h"

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

void calendarMC::on_Modify_clicked()
{
    ModEvent* eve=new ModEvent;
    eve->show();
}


void calendarMC::on_countdowndays_clicked()
{
    CountDownDaysMC* days=new CountDownDaysMC;
    days->show();
}


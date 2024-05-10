#include "countdowndaysmc.h"
#include "ui_countdowndaysmc.h"

CountDownDaysMC::CountDownDaysMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CountDownDaysMC)
{
    ui->setupUi(this);
}

CountDownDaysMC::~CountDownDaysMC()
{
    delete ui;
}

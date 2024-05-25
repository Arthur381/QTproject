#include "alarm.h"
#include "ui_alarm.h"

alarm::alarm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::alarm)
{
    ui->setupUi(this);
}

alarm::~alarm()
{
    delete ui;
}

#include "clockhzj.h"
#include "ui_clockhzj.h"

clockHZJ::clockHZJ(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::clockHZJ)
{
    ui->setupUi(this);
}

clockHZJ::~clockHZJ()
{
    delete ui;
}

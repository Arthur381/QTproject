#include "modevent.h"
#include "ui_modevent.h"

ModEvent::ModEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModEvent)
{
    ui->setupUi(this);
}

ModEvent::~ModEvent()
{
    delete ui;
}

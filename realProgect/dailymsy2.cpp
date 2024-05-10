#include "dailymsy2.h"
#include "ui_dailymsy2.h"

dailymsy2::dailymsy2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dailymsy2)
{
    ui->setupUi(this);
}

dailymsy2::~dailymsy2()
{
    delete ui;
}

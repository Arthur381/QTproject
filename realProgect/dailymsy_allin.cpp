#include "dailymsy_allin.h"
#include "ui_dailymsy_allin.h"

dailymsy_allin::dailymsy_allin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dailymsy_allin)
{
    ui->setupUi(this);
}

dailymsy_allin::~dailymsy_allin()
{
    delete ui;
}

#include "third.h"
#include "ui_third.h"

third::third(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::third)
{
    ui->setupUi(this);
}

third::~third()
{
    delete ui;
}

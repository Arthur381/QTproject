#include "foodiro.h"
#include "ui_foodiro.h"

FoodIro::FoodIro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FoodIro)
{
    ui->setupUi(this);
}

FoodIro::~FoodIro()
{
    delete ui;
}

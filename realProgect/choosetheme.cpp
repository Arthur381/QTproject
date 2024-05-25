#include "choosetheme.h"
#include "ui_choosetheme.h"
#include <QFile>
#include <QCoreApplication>
#include"global.h"

ChooseTheme::ChooseTheme(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChooseTheme)
{
    ui->setupUi(this);
}

ChooseTheme::~ChooseTheme()
{
    delete ui;
}

void ChooseTheme::on_pushButton_clicked()
{
    ThemeStyle=1;
}


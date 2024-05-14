#include "dailymsy.h"
#include "ui_dailymsy.h"
#include "dailymsy2.h"
#include "dailymsy_allin.h"
#include <QPainter>
#include <QStyleOption>

dailyMSY::dailyMSY(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dailyMSY)
{
    ui->setupUi(this);//建立窗口和界面的关系
}

dailyMSY::~dailyMSY()
{
    delete ui;
}

/*void dailyMSY::on_iNote_clicked(){
    dailyMSY *Aday=new dailyMSY;
    Aday->show();
}*/

void dailyMSY::on_iNote_clicked()
{
    dailymsy2 *Bday=new dailymsy2;
    Bday->show();
}


void dailyMSY::on_allIn_clicked()
{
    dailymsy_allin *AllDay=new dailymsy_allin;
    AllDay->show();
}


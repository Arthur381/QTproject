#include "coursemsy.h"
#include "ui_coursemsy.h"
#include "schedulemsy.h"
//建立数据库存储所有数据
#include <QSqlDatabase>
#include <QSqlQuery>

coursemsy::coursemsy(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::coursemsy)
{
    ui->setupUi(this);
}

coursemsy::~coursemsy()
{
    delete ui;
}

void coursemsy::on_pushButton_clicked()//显示课程表的
{
    scheduleMSY *Aschedulemsy=new scheduleMSY;
    Aschedulemsy->show();
}


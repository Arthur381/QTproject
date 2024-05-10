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

void dailymsy_allin::on_missionAdd_clicked()//添加任务并且显示
{

}

void dailymsy_allin::CreatDataFunc(){//创建SQLite数据库

    }
void dailymsy_allin::CreatTableFunc(){//创建sqlite数据表

    }

#include "calendarmc.h"
#include "ui_calendarmc.h"
#include "modevent.h"
#include "countdowndaysmc.h"


calendarMC::calendarMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::calendarMC)
{
    ui->setupUi(this);
    //创建且打开数据库,调用函数
    CreatDataFunc();

}

calendarMC::~calendarMC()
{
    delete ui;
}

void calendarMC::CreatDataFunc(){
    //1.添加驱动
    sqldb=QSqlDatabase::addDatabase("QSQLITE");
    //2.名称

    //3.数据库打开是否成功
    if(sqldb.open()!=true){
        QMessageBox::critical(0,"抱歉","数据库打开失败!",QMessageBox::Ok);
    }

}
void calendarMC::CreatTableFunc(){
    //创建SQL
    QSqlQuery createquery;
    QString strsql=QString();

}

void calendarMC::on_Modify_clicked()
{
    ModEvent* eve=new ModEvent;
    eve->show();
}


void calendarMC::on_countdowndays_clicked()
{
    CountDownDaysMC* days=new CountDownDaysMC;
    days->show();
}


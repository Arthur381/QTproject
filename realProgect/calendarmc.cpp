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
    CreatTableFunc();
}

calendarMC::~calendarMC()
{
    delete ui;
}

void calendarMC::CreatDataFunc(){
    //1.添加驱动
    sqldb=QSqlDatabase::addDatabase("QSQLITE");
    //2.名称
    sqldb.setDatabaseName("Event_cal.db");
    //3.数据库打开是否成功
    if(sqldb.open()!=true){
        QMessageBox::critical(0,"抱歉","数据库打开失败!",QMessageBox::Ok);
    }

}
void calendarMC::CreatTableFunc(){
    //创建SQL
    QSqlQuery createquery;
    QString strsql=QString("create table event("
                             "date text primary key not null,"
                             "atime text not null,"
                             "mood text not null,"
                             "details text not null)");

    //执行SQL
    if(createquery.exec(strsql)!=true){//已经创建
        //QMessageBox::critical(0,"抱歉","数据表创建失败!",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"Success","数据表创建成功。",QMessageBox::Ok);
    }
}



void calendarMC::QueryTableFunc(){

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


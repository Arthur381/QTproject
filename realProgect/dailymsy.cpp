#include "dailymsy.h"
#include "ui_dailymsy.h"
#include "dailymsy2.h"
#include "dailymsy_allin.h"
#include<QMessageBox>
#include "dailymsy3.h"
#include "dailymsy4.h"
#include "dailymsy5.h"

#include <QPainter>
#include <QStyleOption>

dailyMSY* dailyMSY::ptrdailymsy_allin = nullptr;//在类外初始化

dailyMSY::dailyMSY(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dailyMSY)
{
    ui->setupUi(this);//建立窗口和界面的关系

    CreatDataFunc();
    CreatTableFunc();

}

dailyMSY::~dailyMSY()
{
    delete ui;
}


int dailyMSY::CountNum(){//统计行数
    QSqlQuery sql(sqldb);
    sql.exec("select count(id) from event;");
    int uiCnt=0;
    while(sql.next()){
        uiCnt=sql.value(0).toUInt();//有可能会有bug
    }
    return uiCnt;
}

/*void dailyMSY::on_iNote_clicked(){
    dailyMSY *Aday=new dailyMSY;
    Aday->show();
}*/

void dailyMSY::CreatTableFunc(){//创建sqlite数据表

    QSqlQuery sql(sqldb);
//这里设置的thingname是不能为空的，但是为什么我可以为空
    QString strsql=QString("create table event("
                             "id int not null,"
                             "thingsname text primary key not null,"
                             "im int not null,"
                             "em int not null)");

    //执行SQL语句
    if(sql.exec(strsql)==false){
        QMessageBox::critical(0,"错误","数据表创建失败",QMessageBox::Ok);
    }
    else{
        //QMessageBox::information(0,"正确","恭喜你，数据表创建成功",QMessageBox::Ok);
    }
}


void dailyMSY::CreatDataFunc(){//创建SQLite数据库
    //1.添加数据库驱动
    sqldb=QSqlDatabase::addDatabase("QSQLITE","myConnection");

    //2.设置数据库名称
    sqldb.setDatabaseName("ThingsDemo.db");

    //3.打开数据库是否成功
    if(sqldb.open()==true){
        //QMessageBox::information(0,"正确","恭喜你，数据库打开成功",QMessageBox::Ok);
    }
    else{
        QMessageBox::critical(0,"错误","数据库打开失败",QMessageBox::Ok);
    }
}

QList<BEventInfo> dailyMSY::getPage(int page,int uicnt){//根本目的是得到列表
    QList<BEventInfo> l;
    QSqlQuery sql(sqldb);
    QString strsql=QString("select * from event order by id limit %1 offset %2")
                         .arg(uicnt).arg(page*uicnt);
    sql.exec(strsql);
    int id;
    BEventInfo info;
    while(sql.next()){
        id=sql.value(0).toInt();
        info.thingsname=sql.value(1).toString();
        info.im=sql.value(2).toUInt();
        info.em=sql.value(3).toUInt();
        l.push_back(info);
    }
    return l;
}

bool dailyMSY::addOne(BEventInfo info){
    QSqlQuery sqlquery(sqldb);
    quint32 id=dailyMSY::CountNum()+1;
    //qDebug()<<"id:"<<id;
    QString strs=QString("INSERT INTO event VALUES(%1,'%2',%3,%4)").
                   arg(id).arg(info.thingsname).arg(info.im).arg(info.em);

    if(sqlquery.exec(strs)!=true){
        QMessageBox::critical(0,"失败","数据表插入新数据失败!可能是标题重复。",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"Success","插入新事项成功。",QMessageBox::Ok);
        //getinstance()->getEventList().push_back(newEve);//加入在类内列表中,!!!不需要QLIst了！！！
    }
    return true;
}

void dailyMSY::on_allIn_clicked()
{
    dailymsy_allin *AllDay=new dailymsy_allin;
    AllDay->show();
}

void dailyMSY::on_iNote_clicked()
{
    dailymsy2 *Bday=new dailymsy2;
    Bday->show();
}

void dailyMSY::on_nine_clicked()
{
    dailymsy3 *Cday=new dailymsy3;
    Cday->show();
}


void dailyMSY::on_iAnde_clicked()
{
    dailymsy4 *Dday=new dailymsy4;
    Dday->show();
}

void dailyMSY::on_eNoti_clicked()
{
    dailymsy5 *Eday=new dailymsy5;
    Eday->show();
}


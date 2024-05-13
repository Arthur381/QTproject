#include "dailymsy_allin.h"
#include "ui_dailymsy_allin.h"
#include <QMessageBox>

#include<QDebug>
dailymsy_allin* dailymsy_allin::ptrdailymsy_allin = nullptr;//在类外初始化
dailymsy_allin::dailymsy_allin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dailymsy_allin)
{
    ui->setupUi(this);

    //调用函数创建且打开数据库
    CreatDataFunc();

    //调用数据表创建程序
    CreatTableFunc();
}

dailymsy_allin::~dailymsy_allin()
{
    delete ui;
}

void dailymsy_allin::on_missionAdd_clicked()//添加任务并且显示
{

}

void dailymsy_allin::CreatDataFunc(){//创建SQLite数据库
    //1.添加数据库驱动
    sqldb=QSqlDatabase::addDatabase("QSQLITE");

    //2.设置数据库名称
    sqldb.setDatabaseName("ThingsDemo.db");

    //3.打开数据库是否成功
    if(sqldb.open()==true){
        QMessageBox::information(0,"正确","恭喜你，数据库打开成功",QMessageBox::Ok);
    }
    else{
        QMessageBox::critical(0,"错误","数据库打开失败",QMessageBox::Ok);
    }
}

QList<BEventInfo> dailymsy_allin::getPage(int page,int uicnt){//根本目的是得到列表
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
        info.im=sql.value(2).toString();
        info.em=sql.value(3).toString();
        l.push_back(info);
    }
    return l;
}
void dailymsy_allin::CreatTableFunc(){//创建sqlite数据表
    QSqlQuery creatquery;

    QString strsql=QString("create table event("
                                    "id int not null,"
                                    "thingsname text primary key not null,"
                                    "im int not null,"
                                    "em int not null)");

    //执行SQL语句
    if(creatquery.exec(strsql)==false){
         QMessageBox::critical(0,"错误","数据表创建失败",QMessageBox::Ok);
    }
    else{
         QMessageBox::information(0,"正确","恭喜你，数据表创建成功",QMessageBox::Ok);
    }
    }

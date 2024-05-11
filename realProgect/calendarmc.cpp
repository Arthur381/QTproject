#include "calendarmc.h"
#include "ui_calendarmc.h"
#include "modevent.h"
#include "countdowndaysmc.h"

#include<QDebug>


calendarMC* calendarMC::ptrcalendar = nullptr;//在类外初始化

calendarMC::calendarMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::calendarMC)
{
    ui->setupUi(this);
    //创建且打开数据库,调用函数
<<<<<<< HEAD

=======
>>>>>>> 4c714ed7a7a96e4ae67ed713879be9aa970af1cf
    CreatDataFunc();
    CreatTableFunc();
}

calendarMC::~calendarMC()
{
    delete ui;
}

void calendarMC::CreatDataFunc(){//sqldb实际上是一个静态变量
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
<<<<<<< HEAD
                             "id int not null,"
                             "name text primary key not null,"
                             "date text not null,"
=======
                             "date text primary key not null,"
>>>>>>> 4c714ed7a7a96e4ae67ed713879be9aa970af1cf
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

<<<<<<< HEAD
int calendarMC::countNum(){//统计行数
    QSqlQuery sql(sqldb);
    sql.exec("select count(id) from event;");
    int uiCnt=0;
    while(sql.next()){
        uiCnt=sql.value(0).toUInt();//有可能会有bug
    }
    return uiCnt;
}


bool calendarMC::AddEvent(AEventInfo newEve){


    qDebug() << "Value:" << newEve.date << ", Name:" << newEve.name;
    QSqlQuery sqlquery(sqldb);
    quint32 id=calendarMC::countNum()+1;
    qDebug()<<"id:"<<id;
    QString strs=QString("INSERT INTO event VALUES(%1,'%2','%3','%4','%5','%6')").
                   arg(id).arg(newEve.name).arg(newEve.date).arg(newEve.atimes).arg(newEve.mood).arg(newEve.details);

    if(sqlquery.exec(strs)!=true){
        QMessageBox::critical(0,"失败","数据表插入新数据失败!可能是标题重复。",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"Success","插入新事项成功。",QMessageBox::Ok);
        eves.append(newEve);
    }
    qDebug()<<"listsize"<<getEventList().size();

    return true;
}

bool calendarMC::iffind(QString name_){
    QSqlQuery sql(sqldb);
    QString queryString = "SELECT COUNT(*) FROM event WHERE name = :name";
    sql.prepare(queryString);

    sql.bindValue(":name", name_);

    // 执行 SQL 查询
    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        return false;
    }

    // 获取查询结果
    if (sql.next()) {
        int count = sql.value(0).toInt();
        return (count > 0);
    }
    return false;
=======


void calendarMC::QueryTableFunc(){
>>>>>>> 4c714ed7a7a96e4ae67ed713879be9aa970af1cf

}


bool calendarMC::DeleteEvent(QString name_){//输入序号之后删除一个事件；
    QSqlQuery sql(sqldb);
    qDebug()<<"return:"<<calendarMC::iffind(name_)<<"name:"<<name_;
    if(calendarMC::iffind(name_)){
        QMessageBox::information(0,"Success","删除事项成功。",QMessageBox::Ok);
    }
    else{
        QMessageBox::critical(0,"失败","删除事项失败，您输入的事项不存在!",QMessageBox::Ok);
    }
    QString dequery="delete from event where name==:name";
    sql.prepare(dequery);
    sql.bindValue(":name", name_);

    // 执行 SQL 删除查询
    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        return false;
    }

    // 如果删除成功，返回 true
    return true;
    //return sql.exec(QString("delete from event where name==%1").arg(name_));
}



//void calendarMC::QueryTableFunc(){}

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


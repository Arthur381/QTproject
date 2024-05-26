#include "coursemsy.h"
#include "ui_coursemsy.h"
#include "schedulemsy.h"
//建立数据库存储所有数据
#include <QSqlDatabase>
#include <QSqlQuery>

coursemsy* coursemsy::ptrcoursemsy = nullptr;

coursemsy::coursemsy(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::coursemsy)
{
    ui->setupUi(this);

    ui->selectDay->addItem("1");
    ui->selectDay->addItem("2");
    ui->selectDay->addItem("3");
    ui->selectDay->addItem("4");
    ui->selectDay->addItem("5");
    ui->selectDay->addItem("6");
    ui->selectDay->addItem("7");


    ui->selectTime->addItem("1");
    ui->selectTime->addItem("2");
    ui->selectTime->addItem("3");
    ui->selectTime->addItem("4");
    ui->selectTime->addItem("5");
    ui->selectTime->addItem("6");
    ui->selectTime->addItem("7");
    ui->selectTime->addItem("8");

    /*
    ui->selectTime->addItem("第一节");
    ui->selectTime->addItem("第二节");
    ui->selectTime->addItem("午休时间");
    ui->selectTime->addItem("第三节");
    ui->selectTime->addItem("第四节");
    ui->selectTime->addItem("晚饭时间");
    ui->selectTime->addItem("第五节");
    ui->selectTime->addItem("第六节");
*/

    CreatDataFunc();
    CreatTableFunc();
}

coursemsy::~coursemsy()
{
    delete ui;
}

void coursemsy::CreatDataFunc(){//创建SQLite数据库
    //1.添加数据库驱动
    sqldb=QSqlDatabase::addDatabase("QSQLITE");

    //2.设置数据库名称
    sqldb.setDatabaseName("CourseShow.db");

    //3.打开数据库是否成功
    if(sqldb.open()==true){
        //QMessageBox::information(0,"正确","恭喜你，数据库打开成功",QMessageBox::Ok);
    }
    else{
        //QMessageBox::critical(0,"错误","数据库打开失败",QMessageBox::Ok);
    }
}

void coursemsy::CreatTableFunc(){//创建sqlite数据表

    QSqlQuery creatquery;

    QString strsql=QString("create table courseDemo("
                             "col int not null,"
                             "row int not null,"
                             "courseName text primary key not null)");

    //执行SQL语句
    if(creatquery.exec(strsql)==false){
        //QMessageBox::critical(0,"错误","数据表创建失败",QMessageBox::Ok);
    }
    else{
        //QMessageBox::information(0,"正确","恭喜你，数据表创建成功",QMessageBox::Ok);
    }
}

void coursemsy::on_pushButton_clicked()//显示课程表的
{
    scheduleMSY *Aschedulemsy=new scheduleMSY;
    Aschedulemsy->show();
}

int coursemsy::countnum(){
    QSqlQuery sql(sqldb);
    sql.exec("select * from courseDemo");
    int uiCnt=0;
    while(sql.next()){
        uiCnt=sql.value(0).toUInt();//有可能会有bug
    }
    return uiCnt;
}

bool coursemsy::addone(CEventInfo info){
    QSqlQuery sqlquery(sqldb);
    QString strsql=QString("INSERT INTO courseDemo VALUES(%1,%2,'%3')").
                     arg(info.col).arg(info.row).arg(info.courseName);

    //查询原表中有没有和当前一样的
    QString strsearch=QString("SELECT col=%1 row=%2 FROM courseDemo;").
                        arg(info.col).arg(info.row);

    if(sqlquery.exec(strsearch)==true){//原先这个位置已经有了，不能重复插入
        QMessageBox::critical(0,"失败","插入新课程失败!该时间段已有课程，请删除后加入新课程",QMessageBox::Ok);
    }
    else{
    if(sqlquery.exec(strsql)!=true){
        QMessageBox::critical(0,"失败","插入新课程失败!可能是时间重复。",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"Success","插入新课程成功。",QMessageBox::Ok);
    }
    }
    return true;
}

QList<CEventInfo> coursemsy::getPage(int page,int uicnt){//根本目的是得到列表
    QList<CEventInfo> l;
    QSqlQuery sql(sqldb);
    QString strsql=QString("select * from courseDemo order by id limit %1 offset %2")
                         .arg(uicnt).arg(page*uicnt);
    sql.exec(strsql);
    CEventInfo info;
    while(sql.next()){
        info.col=sql.value(0).toInt();
        info.row=sql.value(1).toInt();
        info.courseName=sql.value(2).toString();
        l.push_back(info);
    }
    return l;
}


void coursemsy::on_pushButton_2_clicked()//将课程添加到课程表中去
{
    CEventInfo info;
    info.col=ui->selectDay->currentText().toUInt();
    info.row=ui->selectTime->currentText().toUInt();
    info.courseName=ui->inputName->text();
    coursemsy::getinstance()->addone(info);//将数据加入到数据库中，并加入在相应的List中
    //PrintP();//将数据显示在TableWidget上；
}

bool coursemsy::delone(CEventInfo info){
    QSqlQuery sqlquery(sqldb);
    QString strsql=QString("delete from courseDemo where col=%1 and row=%2").//此处不完善，要加上两个条件才好
                     arg(info.col).arg(info.row);
        if(sqlquery.exec(strsql)!=true){
            QMessageBox::critical(0,"失败","删除课程失败!",QMessageBox::Ok);
        }
        else{
            QMessageBox::information(0,"Success","删除课程成功。",QMessageBox::Ok);
        }
    return true;
}

void coursemsy::on_delCourse_clicked()
{
    CEventInfo info;
    info.col=ui->selectDay->currentText().toUInt();
    info.row=ui->selectTime->currentText().toUInt();
    info.courseName=ui->inputName->text();
    coursemsy::getinstance()->delone(info);
}


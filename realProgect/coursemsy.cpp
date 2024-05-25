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

    ui->selectDay->addItem("周一");
    ui->selectDay->addItem("周二");
    ui->selectDay->addItem("周三");
    ui->selectDay->addItem("周四");
    ui->selectDay->addItem("周五");
    ui->selectDay->addItem("周六");
    ui->selectDay->addItem("周天");

    ui->selectTime->addItem("第一节");
    ui->selectTime->addItem("第二节");
    ui->selectTime->addItem("午休时间");
    ui->selectTime->addItem("第三节");
    ui->selectTime->addItem("第四节");
    ui->selectTime->addItem("晚饭时间");
    ui->selectTime->addItem("第五节");
    ui->selectTime->addItem("第六节");

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
        QMessageBox::information(0,"正确","恭喜你，数据库打开成功",QMessageBox::Ok);
    }
    else{
        QMessageBox::critical(0,"错误","数据库打开失败",QMessageBox::Ok);
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
        QMessageBox::critical(0,"错误","数据表创建失败",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"正确","恭喜你，数据表创建成功",QMessageBox::Ok);
    }
}

void coursemsy::on_pushButton_clicked()//显示课程表的
{
    scheduleMSY *Aschedulemsy=new scheduleMSY;
    Aschedulemsy->show();
}


void coursemsy::on_pushButton_2_clicked()//将课程添加到课程表中去
{
    CEventInfo info;
    info.col=ui->selectDay->currentText().toUInt();
    info.row=ui->selectTime->currentText().toUInt();
    info.courseName=ui->inputName->text();
    QSqlQuery sql(sqldb);
    QString strsql=QString("insert into courseShow values(null,%1,%2,'%3')").
                     arg(info.col).arg(info.row).arg(info.courseName);
    sql.exec(strsql);
}


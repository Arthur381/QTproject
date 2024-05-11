#include "dailymsy_allin.h"
#include "ui_dailymsy_allin.h"
#include <QMessageBox>
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
void dailymsy_allin::CreatTableFunc(){//创建sqlite数据表
    QSqlQuery creatquery;

    QString strsql="creat table ThingsDemo ("
                             "DescribeThings text primary key autoincrement,"
                             "importantNum integerr not null,"
                             "emergentNum integer not null)";


    //执行SQL语句
    if(creatquery.exec(strsql)==false){
         QMessageBox::critical(0,"错误","数据表创建失败",QMessageBox::Ok);
    }
    else{
         QMessageBox::information(0,"正确","恭喜你，数据表创建成功",QMessageBox::Ok);
    }
    }

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
    BEventInfo info;
    info.thingsname=ui->thingsname->text();
    info.im=ui->imNum->text().toInt();
    info.em=ui->emNum->text().toUInt();
    dailymsy_allin::getinstance()->addOne(info);//将数据加入到数据库中，并加入在相应的List中
    PrintP();//将数据显示在TableWidget上；
}

int dailymsy_allin::CountNum(){//统计行数
    QSqlQuery sql(sqldb);
    sql.exec("select count(id) from event;");
    int uiCnt=0;
    while(sql.next()){
        uiCnt=sql.value(0).toUInt();//有可能会有bug
    }
    return uiCnt;
}

void dailymsy_allin::PrintP(){
    dailymsy_allin* m_ptrdailymsy_allin=dailymsy_allin::getinstance();
    auto cnt = m_ptrdailymsy_allin->CountNum();
    QList<BEventInfo> listeve=m_ptrdailymsy_allin->getPage(0,cnt);//仅仅跟踪到它指向的Qlist里面
    ui->workTable->clearContents();
    ui->workTable->setRowCount(cnt);
    for(int i=0;i<listeve.size();i++){
        ui->workTable->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->workTable->setItem(i,1,new QTableWidgetItem(listeve[i].thingsname));
        ui->workTable->setItem(i,2,new QTableWidgetItem(listeve[i].im));
        ui->workTable->setItem(i,2,new QTableWidgetItem(listeve[i].em));
        }
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
        info.im=sql.value(2).toUInt();
        info.em=sql.value(3).toUInt();
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

bool dailymsy_allin::addOne(BEventInfo info){
    QSqlQuery sql(sqldb);
    QString strSql= QString("insert into demo values(%1,'%2','%3','%4')").
                     arg(info.id).
                     arg(info.thingsname).
                     arg(info.im).
                     arg(info.em);
    if(sql.exec(strSql)!=true){
        QMessageBox::critical(0,"失败","数据表插入新数据失败!可能是标题重复。",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"Success","插入新事项成功。",QMessageBox::Ok);
        //getinstance()->getEventList().push_back(newEve);//加入在类内列表中,!!!不需要QLIst了！！！
    }
    return true;
}

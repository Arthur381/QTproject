#include "dailymsy3.h"
#include "ui_dailymsy3.h"
#include "dailymsy.h"

dailymsy3::dailymsy3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dailymsy3)
{
    ui->setupUi(this);
    sqldb.setDatabaseName("ThingsDemo.db");
    if(!sqldb.open())
        qDebug()<<"database open failed";
    Print();
}

dailymsy3::~dailymsy3()
{
    delete ui;
}

void dailymsy3::Print(){
    //显示相应的分类,不重要不紧急 重要：50以下，紧急：50以下
    QList<BEventInfo> l;
    QSqlQuery sql(sqldb);
    //此处可能有问题，怎么根据im和em的值去筛选出相应的条列
    QString strsql=QString("select * from courseDemo WHERE im<50 and em<50;");
    sql.exec(strsql);

    BEventInfo info;
    while(sql.next()){
        info.id=sql.value(0).toInt();
        info.thingsname=sql.value(1).toString();
        info.im=sql.value(2).toInt();
        info.em=sql.value(3).toInt();
        l.push_back(info);
    }

    //把l列表中的东西打印出来
    ui->nine->clearContents();
    ui->nine->setRowCount(l.size());
    for(int i=0;i<l.size();i++){
        ui->nine->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->nine->setItem(i,1,new QTableWidgetItem(l[i].thingsname));
    }
}

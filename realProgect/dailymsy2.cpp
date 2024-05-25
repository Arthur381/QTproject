#include "dailymsy2.h"
#include "ui_dailymsy2.h"
#include <QPainter>
#include <QStyleOption>
#include "dailymsy.h"

#include <QWidget>
#include<QSqlDatabase>
#include <QAbstractButton>
#include <QMessageBox>

dailymsy2::dailymsy2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dailymsy2)
{
    ui->setupUi(this);
    sqldb.setDatabaseName("ThingsDemo.db");
    if(!sqldb.open())
        qDebug()<<"database open failed";
    Print();
}

dailymsy2::~dailymsy2()
{
    delete ui;
}

void dailymsy2::Print(){
    dailyMSY* m_ptrdailymsy_allin=dailyMSY::getinstance();
    auto cnt = m_ptrdailymsy_allin->CountNum();
    QList<BEventInfo> listeve=m_ptrdailymsy_allin->getPage(0,cnt);//仅仅跟踪到它指向的Qlist里面

    //显示相应的分类,重要不紧急 重要：50以上，紧急：50以下
        QList<BEventInfo> l;
        QSqlQuery sql(sqldb);
        //此处可能有问题，怎么根据im和em的值去筛选出相应的条列
        QString strsql=QString("select * from ThingsDemo where im>=50 and em<50;");
        if(sql.exec(strsql)){
            QMessageBox::information(0,"Success","放入特定分类成功。",QMessageBox::Ok);
        }
        else{
            QMessageBox::critical(0,"失败","特定分类失败。",QMessageBox::Ok);
        }
        BEventInfo info;
        while(sql.next()){
            info.id=sql.value(0).toInt();
            info.thingsname=sql.value(1).toString();
            info.im=sql.value(2).toInt();
            info.em=sql.value(3).toInt();
            l.push_back(info);
        }

        //把l列表中的东西打印出来
        ui->showImNem->clearContents();
        ui->showImNem->setRowCount(l.size());
        for(int i=0;i<l.size();i++){
            ui->showImNem->setItem(i,0,new QTableWidgetItem(QString::number(i)));
            ui->showImNem->setItem(i,1,new QTableWidgetItem(l[i].thingsname));
        }
}

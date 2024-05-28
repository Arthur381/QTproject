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
    //固定行宽
    ui->showImNem->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->showImNem->setColumnWidth(0,100);
    ui->showImNem->setColumnWidth(1,150);
    modifyDatabase();
}

dailymsy2::~dailymsy2()
{
    delete ui;
}

void dailymsy2::modifyDatabase(){
    QSqlDatabase db=QSqlDatabase::database("myConnection");
    if(!db.isOpen()){
        qDebug()<<"error";
        return;
    }
    QSqlQuery sql(db);
    QString strsql=QString("select * from event where im>=50 and em<50;");
    if(sql.exec(strsql)){
        //QMessageBox::information(0,"Success","放入特定分类成功。",QMessageBox::Ok);
    }
    else{
        QMessageBox::critical(0,"失败","特定分类失败。",QMessageBox::Ok);
    }
    QList<BEventInfo> l;
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

#include "dailymsy5.h"
#include "ui_dailymsy5.h"
#include "dailymsy.h"

#include <QMessageBox>

dailymsy5::dailymsy5(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dailymsy5)
{
    ui->setupUi(this);

    //固定行宽
    ui->eNoti->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->eNoti->setColumnWidth(0,100);
    ui->eNoti->setColumnWidth(1,175);

    modifyDatabase();
}

dailymsy5::~dailymsy5()
{
    delete ui;
}

void dailymsy5::modifyDatabase(){
    QSqlDatabase db=QSqlDatabase::database("myConnection");
    if(!db.isOpen()){
        qDebug()<<"error";
        return;
    }
    QSqlQuery sql(db);
    QString strsql=QString("select * from event where im<50 and em>=50;");
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
    ui->eNoti->clearContents();
    ui->eNoti->setRowCount(l.size());
    for(int i=0;i<l.size();i++){
        ui->eNoti->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->eNoti->setItem(i,1,new QTableWidgetItem(l[i].thingsname));
    }
}

void dailymsy5::changetheme(){
    if(ThemeStyle==0){


    }
    else if(ThemeStyle==1){



    }
    else if(ThemeStyle==2){

    }
}
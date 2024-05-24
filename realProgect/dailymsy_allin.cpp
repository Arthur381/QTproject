#include "dailymsy_allin.h"
#include "ui_dailymsy_allin.h"
#include"dailymsy.h"
#include <QMessageBox>
<<<<<<< HEAD
=======

>>>>>>> 892b0e877f7240b24e298794dee0beb5f0457153
#include <QPainter>
#include <QStyleOption>
#include<QDebug>


dailymsy_allin::dailymsy_allin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dailymsy_allin)
{
    ui->setupUi(this);
    PrintP();
}

dailymsy_allin::~dailymsy_allin()
{
    delete ui;
}

void dailymsy_allin::on_missionAdd_clicked()//添加任务并且显示
{
    BEventInfo info;
    info.thingsname=ui->thingsname->text();
    info.id=1;
    info.im=ui->imNum->text().toInt();
    info.em=ui->emNum->text().toUInt();
    dailyMSY::getinstance()->addOne(info);//将数据加入到数据库中，并加入在相应的List中
    PrintP();//将数据显示在TableWidget上；
}


void dailymsy_allin::PrintP(){
    dailyMSY* m_ptrdailymsy_allin=dailyMSY::getinstance();
    auto cnt = m_ptrdailymsy_allin->CountNum();
    QList<BEventInfo> listeve=m_ptrdailymsy_allin->getPage(0,cnt);//仅仅跟踪到它指向的Qlist里面
    ui->workTable->clearContents();
    ui->workTable->setRowCount(cnt);
    for(int i=0;i<listeve.size();i++){
        ui->workTable->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        //ui->workTable->setItem(i,1,new QTableWidgetItem(listeve[i].thingsname));
        ui->workTable->setItem(i,2,new QTableWidgetItem(listeve[i].im));
        ui->workTable->setItem(i,3,new QTableWidgetItem(listeve[i].em));
    }
}





void dailymsy_allin::on_pushButton_clicked()//完成了该项任务，将文字设置成划线形式
{
    QList<QTableWidgetItem*> item=ui->workTable->selectedItems();
    int ncount=item.count();
    int nCurrentRow,nMaxRow;
    nMaxRow=ui->workTable->rowCount();
    if(ncount>0){
        nCurrentRow=ui->workTable->row(item.at(0));
        nCurrentRow+=1;
        ui->workTable->setCurrentCell(nCurrentRow,QItemSelectionModel::Select);
        if(nCurrentRow>=nMaxRow)
            ui->workTable->setCurrentCell(0,QItemSelectionModel::Select);
        else
            ui->workTable->setCurrentCell(nCurrentRow,QItemSelectionModel::Select);
    }
    else
        ui->workTable->setCurrentCell(0,QItemSelectionModel::Select);
}


void dailymsy_allin::on_workTable_cellClicked(int row, int column)
{

}


#include "dailymsy_allin.h"
#include "ui_dailymsy_allin.h"
#include"dailymsy.h"
#include <QMessageBox>
#include <QPainter>
#include <QStyleOption>
#include<QDebug>


dailymsy_allin::dailymsy_allin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dailymsy_allin)
{
    ui->setupUi(this);
    ui->workTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->workTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->workTable->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止对表格内容进行修改
    PrintP();
}

dailymsy_allin::~dailymsy_allin()
{
    delete ui;
}

void dailymsy_allin::on_missionAdd_clicked()//添加任务并且显示
{
    dailyMSY* m_ptrdailymsy_allin=dailyMSY::getinstance();
    auto cnt = m_ptrdailymsy_allin->CountNum();
    BEventInfo info;
    // dailyMSY* m_ptrdailymsy_allin=dailyMSY::getinstance();
    // auto cnt = m_ptrdailymsy_allin->CountNum();
    info.thingsname=ui->thingsname->text();
    info.id=cnt+1;
    qDebug()<<info.id;
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
        qDebug()<<listeve[i].id;
        ui->workTable->setItem(i,0,new QTableWidgetItem(QString::number(listeve[i].id)));
        ui->workTable->setItem(i,1,new QTableWidgetItem(listeve[i].thingsname));
        ui->workTable->setItem(i,2,new QTableWidgetItem(QString::number(listeve[i].im)));
        ui->workTable->setItem(i,3,new QTableWidgetItem(QString::number(listeve[i].em)));
    }
}

void dailymsy_allin::on_delectAll_clicked()
{
    int nCount=ui->workTable->rowCount();
    if(nCount>0){
        ui->workTable->clearContents();
    }
}


void dailymsy_allin::on_nextRow_clicked()//转到选择行的下一行
{
    QList<QTableWidgetItem*> items=ui->workTable->selectedItems();
    int nCount=items.count();
    int nCurrentRow,nMaxRow;

    nMaxRow=ui->workTable->rowCount();

    if(nCount>0){
        nCurrentRow=ui->workTable->row(items.at(0));
        nCurrentRow+=1;

        if(nCurrentRow>=nMaxRow){
            ui->workTable->setCurrentCell(0,QItemSelectionModel::Select);
            ui->show->setText(QString("%1").arg(1));
        }
        else{
            ui->workTable->setCurrentCell(nCurrentRow,QItemSelectionModel::Select);
            ui->show->setText(QString("%1").arg(nCurrentRow+1));
        }
    }
    else{//没选中则设置为首行
        ui->workTable->setCurrentCell(0,QItemSelectionModel::Select);
        ui->show->setText(QString("%1").arg(1));
    }

}


void dailymsy_allin::on_horizontalSlider_valueChanged(int value)
{
    ui->imNum->setText(QString("%1").arg(value));
}


void dailymsy_allin::on_horizontalSlider_2_valueChanged(int value)
{
     ui->emNum->setText(QString("%1").arg(value));
}


void dailymsy_allin::on_imNum_textChanged(const QString &arg1)
{
    ui->horizontalSlider->setValue(arg1.toUInt());
}


void dailymsy_allin::on_emNum_textChanged(const QString &arg1)
{
    ui->horizontalSlider_2->setValue(arg1.toUInt());
}


void dailymsy_allin::on_workTable_itemClicked(QTableWidgetItem *item)
{
    int nrow=item->row();
    ui->show->setText(QString("%1").arg(nrow));
}


void dailymsy_allin::on_deleteMission_clicked()
{
    QSqlDatabase db=QSqlDatabase::database("myConnection");
    if(!db.isOpen()){
        qDebug()<<"error";
        return;
    }
    QSqlQuery sql(db);
    //这里有问题，我先将其划线，再从中删去可以实现么
    QList<QTableWidgetItem*> item=ui->workTable->selectedItems();
    int idValue=item[0]->text().toInt();
    // 获取要删除的行的唯一标识，假设在第一列
    // 这里假设标识是整数类型的，根据实际情况修改

    // 准备 SQL 删除语句，根据 id 列删除对应行
    QString deleteStr = QString("DELETE FROM event WHERE id = %1").arg(idValue);

    qDebug()<<idValue;
    // 执行删除语句
    if (!sql.exec(deleteStr)) {
        // 删除失败，打印错误信息
        qDebug() << "Delete query failed:" << sql.lastError().text();
    }
    else {
        // 删除成功，你可以更新 QTableWidget 中的显示以反映删除
        // 例如，删除 QTableWidget 中的当前行
        int row = item[0]->row();
        ui->workTable->removeRow(row);
    }
    // ui->workTable->setStyleSheet("selection-background-color:rgb(255,209,128)");
    // ui->workTable->selectRow(ncount);
    // 准备 SQL 查询语句，根据行号查询对应行的 id 列的值
    // QString queryStr = QString("SELECT id FROM event WHERE rowid = %1").arg(ncount);
    // // 执行查询语句
    // if (sql.exec(queryStr)) {
    //     // 如果查询成功，获取结果
    //     if (sql.next()) {
    //         // 从查询结果中获取 id 列的值
    //         int idValue = sql.value(0).toInt();
    //         // 这里的 idValue 就是你要获取的 id 列的值
    //         QString deleteStatement = QString("DELETE FROM event WHERE id = %1;").arg(idValue);
    //         sql.exec(deleteStatement);
    //     } else {
    //         // 没有找到对应行的数据
    //         qDebug() << "No data found for row number";
    //     }
    // } else {
    //     // 查询失败，打印错误信息
    //     qDebug() << "Query failed:" << sql.lastError().text();
    // }
    // //qDebug() << ncount;
    // //QString deleteStatement = QString("DELETE FROM event WHERE rowid = %1;").arg(ncount+1);
    // //sql.exec(deleteStatement);
    // // QString strsql=QString("delete from event where id=%1;").arg(ncount);
    // // if(sql.exec(strsql)==false){
    // //     QMessageBox::critical(0,"错误","删除事项失败",QMessageBox::Ok);
    // // }
}

void dailymsy_allin::changetheme(){
    if(ThemeStyle==0){


    }
    else if(ThemeStyle==1){



    }
    else if(ThemeStyle==2){

    }
}

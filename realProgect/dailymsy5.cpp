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
    setWindowTitle(QStringLiteral("显示日程"));
     setWindowIcon(QIcon(":/icon/dailymsy3.jpg"));
    ui->eNoti->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->eNoti->setColumnWidth(0,100);
    ui->eNoti->setColumnWidth(1,200);
    //ui->eNoti->resizeColumnsToContents();
    changetheme();
    modifyDatabase();
    ui->eNoti->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
    ui->eNoti->setStyleSheet(
        "QTableWidget{background-color:rgba(250, 250,250, 0.327);"
        "text-decoration-color: rgba(90, 66, 59, 0.163);"
        "text-lightcolor;"
        "}"
        );
    if(ThemeStyle==0){

        this->setStyleSheet(
            "QDialog{"
            "    background-image: url(:/PKU/4.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );

    }
    else if(ThemeStyle==1){
        this->setStyleSheet(
            "QDialog{"
            "    background-image: url(:/happydog/444.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );


    }
    else if(ThemeStyle==2){

    }
}

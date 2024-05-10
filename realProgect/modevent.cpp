#include "modevent.h"
#include "ui_modevent.h"
#include "calendarmc.h"

ModEvent::ModEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModEvent)
{
    ui->setupUi(this);
}

ModEvent::~ModEvent()
{
    delete ui;
}

void ModEvent::on_pushButton_add_clicked()//点击之后加入事项
{
    QSqlQuery sqlquery;
    QString date=ui->inputdate->text();
    if(date==""){
        QMessageBox::critical(this,"输入错误","不能插入过去的时间");
        return;
    }
    QString atimes=ui->inputtime->text();
    QString details=ui->WriteEve->text();
    QString mood=ui->comboBox_moodchange->currentText();



    QString strs=QString("insert into event "
                           "values('%1','%2','%3','%4')")
                            .arg(date).arg(atimes).arg(mood).arg(details);


    if(sqlquery.exec(strs)!=true){//已经创建
        QMessageBox::critical(0,"失败","数据表插入新数据失败!",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"Success","插入新事项成功。",QMessageBox::Ok);
    }
}


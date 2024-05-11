#include "modevent.h"
#include "ui_modevent.h"
#include "calendarmc.h"
<<<<<<< HEAD
//现存的问题：List始终是空的，每次添加一个元素，就要打印出来；
//使用单例,每次重新初始化列表
=======

>>>>>>> 4c714ed7a7a96e4ae67ed713879be9aa970af1cf
ModEvent::ModEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModEvent)
{
    ui->setupUi(this);
    //PrintP();//将数据显示在TableWidget上；

}

void ModEvent::PrintP(){
    calendarMC* m_ptrcalendar=calendarMC::getinstance();

    auto cnt = m_ptrcalendar->countNum();
    QList<AEventInfo> listeve=m_ptrcalendar->getEventList();
    //ui->tableWidget->clear();
    qDebug()<<"Emepty:"<<listeve.size();
    ui->tableWidget->setRowCount(cnt);
    qDebug()<<"cnt:"<<cnt;
    for(int i=0;i<cnt;i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(listeve[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(listeve[i].date));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(listeve[i].atimes));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(listeve[i].mood));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(listeve[i].details));
    }
}


ModEvent::~ModEvent()
{
    delete ui;
}

<<<<<<< HEAD

void ModEvent::on_pushButton_add_clicked()//点击之后加入事项
{
    AEventInfo aeve;
    ;//创建实例化对象
    aeve.date=ui->inputdate->text();
    if(aeve.date==""){
        QMessageBox::critical(this,"输入错误","不能插入过去的时间");
        return;
    }
    aeve.name=ui->lineEditID->text();
    aeve.atimes=ui->inputtime->text();
    aeve.mood=ui->comboBox_moodchange->currentText();
    aeve.details=ui->WriteEve->text();
    calendarMC::getinstance()->AddEvent(aeve);
    PrintP();//将数据显示在TableWidget上；
=======
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
>>>>>>> 4c714ed7a7a96e4ae67ed713879be9aa970af1cf
}


void ModEvent::on_pushButton_delete_clicked()
{
    //创建实例化对象,单例
    QString Aname=ui->lineEdit_eve->text();
    calendarMC::getinstance()->DeleteEvent(Aname);
    PrintP();
}





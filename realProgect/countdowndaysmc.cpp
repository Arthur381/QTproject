#include "countdowndaysmc.h"
#include "ui_countdowndaysmc.h"
#include <QDateTime>
#include<QDate>
#include<QDebug>

//QDate currentDate = QDate::currentDate();
//qDebug() << "Current Date:" << currentDate.toString(Qt::ISODate);



CountDownDaysMC::CountDownDaysMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CountDownDaysMC)
{
    ui->setupUi(this);
    calendarMC* m_ptrcalendar=calendarMC::getinstance();
    CountDownDaysMC::PrintForView();
}

void CountDownDaysMC::PrintForView(){
    calendarMC* m_ptrcalendar=calendarMC::getinstance();
    auto cnt = m_ptrcalendar->countNum();
    qDebug()<<"here2?";
    QList<AEventInfo> listeve=m_ptrcalendar->selectPage(0,cnt);//仅仅跟踪到它指向的Qlist里面
    cnt = listeve.size();
    ui->tableWidget->clearContents();
    //qDebug()<<"Emepty:"<<listeve.size();
    ui->tableWidget->setRowCount(cnt);
    //qDebug()<<"cnt:"<<cnt;
    for(int i=0;i<listeve.size();i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(listeve[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(listeve[i].mood));
        QDate date = QDate::fromString(listeve[i].date,"yyyy/MM/dd");
        //qDebug()<<"date:"<<date;
        int diff=m_ptrcalendar->TToday.daysTo(date);
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(diff)));
    }
}



CountDownDaysMC::~CountDownDaysMC()
{
    delete ui;
}

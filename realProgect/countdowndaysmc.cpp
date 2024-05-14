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
    //ui->tableWidget->setColumnWidth(0, 50); // 设置第一列固定宽度
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(2, 100); // 第二列根据内容调整
    ui->tableWidget->setColumnWidth(3, 150); // 第
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
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
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(i));
        item->setTextAlignment(Qt::AlignCenter); // 设置水平和垂直居中对齐
        ui->tableWidget->setItem(i,0,item);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(listeve[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(listeve[i].mood));
        QDate date = QDate::fromString(listeve[i].date,"yyyy/MM/dd");
        int diff=m_ptrcalendar->TToday.daysTo(date);
        item=new QTableWidgetItem(QString::number(diff));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,3,item);
    }
}



CountDownDaysMC::~CountDownDaysMC()
{
    delete ui;
}

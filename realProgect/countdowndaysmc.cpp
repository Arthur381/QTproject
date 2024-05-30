#include "countdowndaysmc.h"
#include "ui_countdowndaysmc.h"
#include <QDateTime>
#include<QDate>
#include<QDebug>
#include <QPainter>
#include <QStyleOption>

#include<QKeyEvent>
#include<QFile>
#include<QCoreApplication>

#include"global.h"

CountDownDaysMC::CountDownDaysMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CountDownDaysMC)
{
    ui->setupUi(this);
    setWindowTitle(QStringLiteral("倒数日"));
    setWindowIcon(QIcon(":/icon/cal.jpg"));
    //ui->tableWidget->setColumnWidth(0, 50); // 设置第一列固定宽度
    ui->tableWidgetCD->setColumnWidth(1, 100);
    ui->tableWidgetCD->setColumnWidth(2, 100); // 第二列根据内容调整
    ui->tableWidgetCD->setColumnWidth(3, 150); // 第
    ui->tableWidgetCD->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    calendarMC* m_ptrcalendar=calendarMC::getinstance();
    CountDownDaysMC::PrintForView();
    changetheme();

    QFont font1("YouYuan",15);
    ui->daoshu->setFont(font1);

}

void CountDownDaysMC::PrintForView(){
    calendarMC* m_ptrcalendar=calendarMC::getinstance();
    auto cnt = m_ptrcalendar->countNum();
    qDebug()<<"here2?";
    QList<AEventInfo> listeve=m_ptrcalendar->selectPage(0,cnt);//仅仅跟踪到它指向的Qlist里面
    cnt = listeve.size();
    ui->tableWidgetCD->clearContents();
    //qDebug()<<"Emepty:"<<listeve.size();
    ui->tableWidgetCD->setRowCount(cnt);
    //qDebug()<<"cnt:"<<cnt;
    for(int i=0;i<listeve.size();i++){
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(i));
        item->setTextAlignment(Qt::AlignCenter); // 设置水平和垂直居中对齐
        ui->tableWidgetCD->setItem(i,0,item);
        ui->tableWidgetCD->setItem(i,1,new QTableWidgetItem(listeve[i].name));
        ui->tableWidgetCD->setItem(i,2,new QTableWidgetItem(listeve[i].mood));
        QDate date = QDate::fromString(listeve[i].date,"yyyy/MM/dd");
        int diff=m_ptrcalendar->TToday.daysTo(date);
        item=new QTableWidgetItem(QString::number(diff));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetCD->setItem(i,3,item);
    }
}


void CountDownDaysMC::paintEvent(QPaintEvent *e)
{
    QStyleOptionFrame opt;
    opt.initFrom(this);  // 初始化 QStyleOptionFrame
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void CountDownDaysMC::changetheme(){
    if(ThemeStyle==0){
        this->setStyleSheet(
            "QWidget#CountDownDaysMC{"
            "    background-image: url(:/PKU/hj.png);"
            "    background-position: center; "
            "    background-repeat: no-repeat;"
            "}"

            "QTableWidget#tableWidgetCD{"
            "background-color:rgba(255, 255, 255, 0.527);"
            "text-decoration-color: rgba(164, 225, 156, 0.963);"
            "}"
            );

    }
    else if(ThemeStyle==1){
        this->setStyleSheet(
            "QWidget#CountDownDaysMC{"
            "    background-image: url(:/happydog/countdown.jpg);"
            "    background-position: center; "
            "    background-repeat: no-repeat;"
            "}"

            "QTableWidget#tableWidgetCD{"
            "background-color:rgba(255, 255, 255, 0.527);"
            "text-decoration-color: rgba(164, 225, 156, 0.963);"
            "}"
            );



    }
    else if(ThemeStyle==2){

    }
    themechanged();
}

CountDownDaysMC::~CountDownDaysMC()
{
    delete ui;
}

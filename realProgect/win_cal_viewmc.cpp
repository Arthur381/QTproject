#include "win_cal_viewmc.h"
#include "ui_win_cal_viewmc.h"
#include"calendarmc.h"
#include<QDebug>
#include<QDate>
#include <QPainter>
#include <QStyleOption>
#include"global.h"
win_cal_viewMC* win_cal_viewMC::ptrWCV = nullptr;//在类外初始化

win_cal_viewMC::win_cal_viewMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::win_cal_viewMC)
{
    setWindowTitle(QStringLiteral("今天的日程"));
     setWindowIcon(QIcon(":/icon/changetheme.png"));
    ui->setupUi(this);
    changetheme();
}

void win_cal_viewMC::FindAndPrint(QList<AEventInfo> speeve){
    /**
     *
     * @note:调用这个函数之前已经将这一天的日程列出来了，且保证list不为空
     *
     */
    //从数据库中找到属于这一天的事件，然后通过“有趣的语句组合起来”
    int cnt = speeve.size();
    ui->tableWidget->clearContents();
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(cnt);
    //qDebug()<<"cnt:"<<cnt;
    for(int i=0;i<cnt;i++){
        QString s0="这一天，怀着";
        QString s1=speeve[i].mood;
        QString s2="的心情,";
        QString s3="在 "+speeve[i].atimes+" 去迎接（面对）";
        QString s4=speeve[i].name;
        QString s5=" (";
        QString s6=speeve[i].details;
        QString s7=") ";
        qDebug()<<s1+s2+s3+s4+s5+s6+s7;
        QTableWidgetItem *item = new QTableWidgetItem(s1+s2+s3+s4+s5+s6+s7);
        //item->setTextAlignment(Qt::AlignCenter); // 设置水平和垂直居中对齐
        ui->tableWidget->setItem(i,0,item);

    }
    changetheme();

}


void win_cal_viewMC::paintEvent(QPaintEvent *e)
{
    QStyleOptionFrame opt;
    opt.initFrom(this);  // 初始化 QStyleOptionFrame
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

win_cal_viewMC::~win_cal_viewMC()
{
    delete ui;
}


void win_cal_viewMC::changetheme(){
    if(ThemeStyle==0){
        this->setStyleSheet(
            "QWidget#win_cal_viewMC{"
            "background-image: url(:/PKU/ju.jpg);"
            "background-position: center;"
            "background-repeat: no-repeat;"
            "}"

            "QTableWidget#tableWidgetCD{"
            "background-color:rgba(255, 255, 255, 0.527);"
            "text-decoration-color: rgba(164, 225, 156, 0.963);"
            "}"
            );

    }
    else if(ThemeStyle==1){
        this->setStyleSheet(
            "QWidget#win_cal_viewMC{"
            "background-image: url(:/happydog/mmcc.jpg);"
            "background-position: center;"
            "background-repeat: no-repeat;"
            "}"

            "QTableWidget#tableWidgetCD{"
            "background-color:rgba(255, 255, 255, 0.527);"
            "text-decoration-color: rgba(164, 225, 156, 0.963);"
            "}"
            );

    }
    else if(ThemeStyle==2){


    }

}

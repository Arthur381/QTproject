#include "countdowndaysmc.h"
#include "ui_countdowndaysmc.h"
#include <QDateTime>
#include<QDebug>

QDate currentDate = QDate::currentDate();
//qDebug() << "Current Date:" << currentDate.toString(Qt::ISODate);



CountDownDaysMC::CountDownDaysMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CountDownDaysMC)
    ,TToday(2024,5,11)
{
    ui->setupUi(this);
}





/*
筛选出未发生的事件然后，根据相隔的天数由近到远排序，最后输出到一个新的TableWidget中
int daysDifference = date1.daysTo(date2); // 计算 date1 和 date2 之间的天数差异
    qDebug() << "Days difference:" << daysDifference; // 打印天数差异
    return 0;


*/
CountDownDaysMC::~CountDownDaysMC()
{
    delete ui;
}

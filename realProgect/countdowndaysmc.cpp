#include "countdowndaysmc.h"
#include "ui_countdowndaysmc.h"
#include <QDateTime>
#include<QDebug>

QDate currentDate = QDate::currentDate();
//qDebug() << "Current Date:" << currentDate.toString(Qt::ISODate);



CountDownDaysMC::CountDownDaysMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CountDownDaysMC)
{
    ui->setupUi(this);
}

CountDownDaysMC::~CountDownDaysMC()
{
    delete ui;
}

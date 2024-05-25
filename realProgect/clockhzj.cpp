#include "clockhzj.h"
#include "ui_clockhzj.h"
#include <QPainter>
#include <QStyleOption>
#include "sec_clock.h"
#include "alarm.h"
#include "r_clock.h"

clockHZJ::clockHZJ(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::clockHZJ)
{
    ui->setupUi(this);

    connect(&timer_cur, SIGNAL(timeout()), this, SLOT(showcurtime()));
    timer_cur.start(1000);
    ui->curtime->setText("0000-00-00 00:00:00");
}

clockHZJ::~clockHZJ()
{
    delete ui;
}

void clockHZJ::showcurtime(){
    curDTime = QDateTime::currentDateTime();
    ui->curtime->setText(curDTime.toString("yyyy-MM-dd HH:mm:ss"));
}

void clockHZJ::on_sec_clock_clicked()
{
    sec_clock *sec=new sec_clock;
    sec->show();
}


void clockHZJ::on_rsec_clo_clicked()
{
    r_clock *rck=new r_clock;
    rck->show();
}


void clockHZJ::on_alarms_clicked()
{
    alarm *ala=new alarm;
    ala->show();
}


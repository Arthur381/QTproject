#include "sec_clock.h"
#include "ui_sec_clock.h"
#include"global.h"

static int i;//打点计数

sec_clock::sec_clock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sec_clock)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));

    time.setHMS(0,0,0,0);//时间初始化
    ui->showtime->setText("00:00:00:000");

    connect(&timer_cur, SIGNAL(timeout()), this, SLOT(showcurtime()));
    timer_cur.start(1000);
    ui->curtime->setText("0000-00-00 00:00:00");
}

sec_clock::~sec_clock()
{
    delete ui;
}


void sec_clock::showcurtime(){
    curDTime = QDateTime::currentDateTime();
    ui->curtime->setText(curDTime.toString("yyyy-MM-dd HH:mm:ss"));
}

void sec_clock::timeout_slot(){
    time=time.addMSecs(32);
    ui->showtime->setText(time.toString("HH:mm:ss.zzz"));
}

void sec_clock::on_start_clicked()
{
    timer.start(30);
}

void sec_clock::on_pause_clicked()
{
    timer.stop();
}

void sec_clock::on_clear_clicked()
{
    //
    timer.stop();
    time.setHMS(0,0,0,0);//时间初始化
    ui->showtime->setText("00:00:00:000");
    //
    ui->showpoints->clear();
    i=0;
}

void sec_clock::on_setpoint_clicked()
{
    QString temp;
    i++;
    temp=QString::asprintf("%0*d:  ",2,i);
    ui->showpoints->append(temp+time.toString("HH:mm:ss.zzz"));
}

void sec_clock::changetheme(){
    if(ThemeStyle==0){

    }
    else if(ThemeStyle==1){


    }
    else if(ThemeStyle==2){


    }

}
